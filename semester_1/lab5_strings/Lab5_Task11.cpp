#include <iostream>
#include <string>

bool IsLetter(char x)
{
    return (x >= 'A' && x <= 'Z')||(x >= 'a' && x <= 'z');
}

bool IsVovel(char x)
{
    return (x == 'a')||(x == 'A')||
           (x == 'e')||(x == 'E')||
           (x == 'i')||(x == 'I')||
           (x == 'o')||(x == 'O')||
           (x == 'u')||(x == 'U')||
           (x == 'y')||(x == 'Y');
}

int main()
{
    try
    {
        std::cout << "Enter your string:" << std::endl;
        std::string inputStr;
        getline(std::cin, inputStr);
        if(inputStr.empty())
        {
            throw("Error. Input string is empty!");
        }

        size_t length = inputStr.length();
        double MaxPercentage = -1;
        std::string result;

        for(size_t index = 0; index < length; ++index)
        {
            std::string word;
            size_t numberOfVovels = 0, numberOfLetters = 0;
            while(IsLetter(inputStr[index])&&(index < length))
            {
                word.push_back(inputStr[index]);
                if(IsVovel(inputStr[index]))
                {
                    numberOfVovels++;
                }
                numberOfLetters++;
                index++;
            }
            //std::cout << numberOfLetters << std::endl << numberOfVovels << std::endl;
            //std::cout << word << std::endl << std::endl;
            if(numberOfLetters > 0)
            {
                double percentage = numberOfVovels / numberOfLetters * 100;
                if(percentage == MaxPercentage)
                {
                    result.push_back(' ');
                    result.append(word);
                }
                if(percentage > MaxPercentage)
                {
                    MaxPercentage = percentage;
                    result.clear();
                    result.append(word);
                }
            }
            word.clear();
        }

        std::cout << "Result:" << std::endl << result;
        return 0;
    }
    catch(const char * err)
    {
        std::cerr << err;
        return 1;
    }
    catch(...)
    {
        std::cerr << "Unexpected error!" << std::endl;
        return 1;
    }
}