#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>

struct Author
{
    std::string familiya_;
    std::string imya_;
    std::string otchestvo_;

    Author(const std::string& fam, const std::string& im, const std::string& otch): familiya_(fam), imya_(im), otchestvo_(otch) {}

    bool operator< (const Author& other) const
    {
        return familiya_ < other.familiya_;
    }

    bool operator== (const Author& other) const
    {
        return ((familiya_ == other.familiya_) && (imya_ == other.imya_) && (otchestvo_ == other.otchestvo_));
    }

    void print_name() const
    {
        std::cout << familiya_ << " " << imya_ << " " << otchestvo_;
    }
};

struct Book 
{
    int YDK_number_;
    std::list<Author> authors_;
    std::string title_;
    int year_of_publication_;

    bool operator< (const Book& other) const
    {
        return title_ < other.title_;
    }

    void book_print_info() const
    {
        std::cout << "---------------------------------------------------" << std::endl;
        std::cout << "УДК: " << YDK_number_ << std::endl;
        std::cout << "Название: " << title_ << std::endl;
        std::cout << "Авторы: ";
        for(const auto& person: authors_)
        {
            person.print_name();
            std::cout << std::endl;
        }
        std::cout << "Год публикации: " << year_of_publication_ << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;
    }
};

class Library
{
private:
    std::list<Book> all_books;
    
public:

    void sort_all_books()
    {
        all_books.sort();
        for(auto& book: all_books)
        {
            book.authors_.sort();
        }
    }

    void UploadFromFile(const std::string& inputfile)
    {
        std::ifstream instream(inputfile);
        if(!(instream.is_open()))
        {
            throw "Ошибка открытия файла!";
        }

        std::string line;
        int new_books_amount = 0;
        while(std::getline(instream, line))
        {
            if(line.empty())
            {
                continue;
            }

            Book new_book;
            std::stringstream linestream(line);

            if(!(linestream >> new_book.YDK_number_))
            {
                throw "Ошибка: обнаружен неверный удк!";
            }
            linestream.ignore();

            int authors_amount;
            if(!(linestream >> authors_amount))
            {
                throw "Введите количество авторов книг!";
            }
            linestream.ignore();

            for(int i = 0; i < authors_amount; ++i)
            {
                std::string familiya, imya, otchestvo;
                if(!(linestream >> familiya >> imya >> otchestvo))
                {
                    throw "Ошибка в имени автора!";
                }
                new_book.authors_.push_back(Author(familiya, imya, otchestvo));
            }

            std::string word_from_title;
            std::string title;
            while(linestream >> word_from_title)
            {
                std::stringstream wordstream(word_from_title);
                int year_of_publication;
                if((wordstream >> year_of_publication) && (wordstream.eof()))
                {
                    new_book.year_of_publication_ = year_of_publication;
                    break;
                }
                if(!(title.empty()))
                {
                    title += " ";
                }
                title += word_from_title;
            }
            new_book.title_ = title;

            all_books.push_back(new_book);
            new_books_amount++;
        }

        instream.close();
        sort_all_books();
        std::cout << "Загружено " << new_books_amount << " книг." << std::endl;
    }



    void AddBook(const Book& new_book)
    {
        all_books.push_back(new_book);
        sort_all_books();
        std::cout << "Добавлена 1 новая книга." << std::endl;
    }

    void DeleteBook(const std::string& title)
    {
        auto it = std::find_if(all_books.begin(), all_books.end(),
        [&title](const Book& book){return book.title_ == title;});

        if(it != all_books.end())
        {
            all_books.erase(it);
            std::cout << "1 Книга удалена." << std::endl;
        }
        else
        {
            std::cout << "Книга не найдена" << std::endl;
        }
    }

    std::list<Book> FindByTitle(const std::string& title) const
    {
        std::list<Book> answer;

        for(const auto& book: all_books)
        {
            if(book.title_.find(title) != std::string::npos)
            {
                answer.push_back(book);
            }
        }
        return answer;
    }

    std::list<Book> FindByAuthor(const std::string& familiya) const
    {
        std::list<Book> answer;

        for(const auto& book: all_books)
        {
            for(const auto& author: book.authors_)
            {
                if(author.familiya_ == familiya)
                {
                    answer.push_back(book);
                    break;
                }
            }
        }
        return answer;
    }

    void AddAuthor(const std::string& title_of_book, const Author& author)
    {
        auto it = std::find_if(all_books.begin(), all_books.end(),
        [&title_of_book](const Book& book){return book.title_ == title_of_book;});
        
        if(it != all_books.end())
        {
            it -> authors_.push_back(author);
            it -> authors_.sort();
            std::cout << "Добавлен 1 автор к книге" << std::endl;
        }
        else
        {
            std::cout << "Книга не найдена" << std::endl;
        }
    }

    void DeleteAuthor(const std::string& title_of_book, const Author& author)
    {
        auto it = std::find_if(all_books.begin(), all_books.end(),
        [&title_of_book](const Book& book){return book.title_ == title_of_book;});

        if(it != all_books.end())
        {
            auto authorIt = find(it -> authors_.begin(), it -> authors_.end(), author);
            if(authorIt != it -> authors_.end())
            {
                it -> authors_.erase(authorIt);
                std::cout << "Автор удален из книги" << std::endl;
            }
            else
            {
                std::cout << "У книги не найден такой автор" << std::endl;
            }
        }
        else
        {
            std::cout << "Книга не найдена" << std::endl;
        }
    }

    void SaveToFile(const std::string& outfile)
    {
        std::ofstream outstream(outfile);
        if(!(outstream.is_open()))
        {
            std::cout << "Ошибка записи данных! Последние изменения не сохранены" << std::endl;
            std::cout << "Сохраните библиотеку вручную чтобы избежать потери данных" << std::endl;
            return;
        }
        for(const auto& book: all_books)
        {
            outstream << book.YDK_number_ << " " << book.authors_.size();
            for(const auto& author: book.authors_)
            {
                outstream << " " << author.familiya_ << " " << author.imya_ << " " << author.otchestvo_;
            }
            outstream << " " << book.title_ << " " << book.year_of_publication_;
            outstream << std::endl;
        }
        outstream.close();
        std::cout << "Данные сохранены в файл " << outfile << std::endl;
    }
};

Book new_book_from_user()
{
    Book new_book;

    std::cout << "Введите удк книги: ";
    if(!(std::cin >> new_book.YDK_number_))
    {
        throw "Введен неверный удк";
    }
    std::cin.ignore();
    std::cout << std::endl;


    std::cout << "Введите название книги: ";
    if(!(std::getline(std::cin, new_book.title_)))
    {
        throw "Введено недопустимое название книги";
    }
    std::cout << std::endl;


    std::cout << "Введите количество авторов: ";
    int authors_amount;
    if(!(std::cin >> authors_amount))
    {
        throw "Введено неверное число авторов";
    }
    std::cin.ignore();
    std::cout << std::endl;
    for(int i = 0; i < authors_amount; ++i)
    {
        std::cout << "Введите автора " << i+1 << ": " << std::endl;
        std::string fam, im, otch;
        std::cout << "Фамилия: " << std::endl;
        std::getline(std::cin, fam);
        std::cout << "Имя: " << std::endl;
        std::getline(std::cin, im);
        std::cout << "Отчество: " << std::endl;
        std::getline(std::cin, otch);

        new_book.authors_.push_back(Author(fam, im, otch));
    }
    new_book.authors_.sort();

    std::cout << "Введите год издания: ";
    if(!(std::cin >> new_book.year_of_publication_))
    {
        throw "Введен неверный год издания";
    }
    return new_book;
}

Author new_author_from_user()
{
    std::cout << "Введите автора: " << std::endl;
    std::string fam, im, otch;
    std::cout << "Фамилия: " << std::endl;
    std::getline(std::cin, fam);
    std::cout << "Имя: " << std::endl;
    std::getline(std::cin, im);
    std::cout << "Отчество: " << std::endl;
    std::getline(std::cin, otch);

    return Author(fam, im, otch);
}

int main() {
    setlocale(LC_ALL, "Russian");

    try
    {
        const std::string inputfile = "Books.txt";
        const std::string outputfile = "Books.txt";

        Library my_library;
        my_library.UploadFromFile(inputfile);

        int menu_choosed;
        do
        {
            std::cout << std::endl;
            std::cout << "_____________Меню____________" << std::endl;
            std::cout << "1. Добавить книгу в каталог" << std::endl;
            std::cout << "2. Удалить книгу из каталога" << std::endl;
            std::cout << "3. Поиск книги по названию" << std::endl;
            std::cout << "4. Поиск книги по автору" << std::endl;
            std::cout << "5. Добавить автора к книге" << std::endl;
            std::cout << "6. Удалить автора из книги" << std::endl;
            std::cout << "7. Сохранить изменения" << std::endl;
            std::cout << "0. Выход" << std::endl;
            std::cout << "_____________________________" << std::endl;

            std::cin >> menu_choosed;
            std::cin.ignore();


            switch (menu_choosed)
            {
            case 1:
            {
                Book new_book = new_book_from_user();
                my_library.AddBook(new_book);
                break;
            }
            case 2:
            {
                std::string title;
                std::cout << "Введите название книги: ";
                std::getline(std::cin, title);
                my_library.DeleteBook(title);
                break;
            }
            case 3:
            {
                std::string title;
                std::cout << "Введите название книги: ";
                std::getline(std::cin, title);
                
                std::list<Book> results = my_library.FindByTitle(title);
                if(results.empty())
                {
                    std::cout << "Книг с таким названием не найдено" << std::endl;
                }
                else
                {
                    std::cout << "Найдено " << results.size() << " книг:" << std::endl;
                    for(const auto& book: results)
                    {
                        book.book_print_info();
                    }
                }
                break;
            }
            case 4:
            {
                std::string familiya;
                std::cout << "Введите фамилию автора: ";
                std::getline(std::cin, familiya);

                std::list<Book> results = my_library.FindByAuthor(familiya);
                if(results.empty())
                {
                    std::cout << "Книг этого автора не найдено" << std::endl;
                }
                else
                {
                    std::cout << "Найдено " << results.size() << " книг:" << std::endl;
                    for(const auto& book: results)
                    {
                        book.book_print_info();
                    }
                }
                break;
            }
            case 5:
            {
                std::string title;
                std::cout << "Введите название книги:";
                std::getline(std::cin, title);

                Author new_author = new_author_from_user();
                my_library.AddAuthor(title, new_author);
                break;
            }
            case 6:
            {
                std::string title;
                std::cout << "Введите название книги:";
                std::getline(std::cin, title);

                Author removing_author = new_author_from_user();
                my_library.DeleteAuthor(title, removing_author);
                break;
            }
            case 7:
            {
                my_library.SaveToFile(outputfile);
                break;
            }
            case 0:
            {
                my_library.SaveToFile(outputfile);
                break;
            }
            default:
            {
                std::cout << "Введите верное значение!" << std::endl;
                break;
            }
            }
        } while(menu_choosed != 0);

        return 0;
    }
    catch(const char* msg)
    {
        std::cerr << msg << std::endl;
        return 1;
    }
    catch(...)
    {
        std::cerr << "Unexpected error!" << std::endl;
        return 1;
    }
}
