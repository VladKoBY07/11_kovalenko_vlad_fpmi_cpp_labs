
#include <iostream>
#include <cmath>
#include <time.h>
#include <random>

int **AllocateMatrix(int, int);
void DeleteMatrix(int **, int);
int Enter_check_int(const int); // from int to infinity
int Enter_check_int();          // checking only type
void FillMatrix(int **&, int, int, char);
int GenerateRandom(const int, const int);
void PrintMatrix(int **, int, int);
void ClearCin();

void BubbleSort(int **&, int, int, bool(*)(int, int));
void InsertionSort(int **&, int, int, bool(*)(int, int));
void MergeSort(int **&, int, int, int, int*);
void merge(int **&, int, int, int, int, int*);

bool A_more_than_B(int, int);
bool A_less_than_B(int, int);

int main() {

    int rows, cols;
    std::cout << "Creating matrix (rows x cols)" << std::endl;
    std::cout << "Enter rows: ";
    rows = Enter_check_int(1);
    std::cout << "Enter cols: ";
    cols = Enter_check_int(1);
    std::cout << std::endl;

    int ** matrix = AllocateMatrix(rows, cols);
    if(matrix == nullptr)
    {
        return 1;
    }

    char mode;
    std::cout << "How do you want to fill the matrix Manually/Auto?";
    while( (!(std::cin >> mode)) || !((mode == 'M') || (mode == 'A') || (mode == 'm') || (mode == 'a')) )
    {
        std::cout << "Error. Enter the right mode!" << std::endl;
        std::cout << "Please try again: ";
        ClearCin();
    }
    ClearCin();
    
    FillMatrix(matrix, rows, cols, mode);
    //std::cout << "Before Sorting:" << std::endl;
    //PrintMatrix(matrix, rows, cols);

    std::cout << "Before Sorting: " << std::endl;
    PrintMatrix(matrix, rows, cols);

    char sort_mode_char;
    std::cout << "How do you want to sort the matrix Bubble/Insertion/Merge" << std::endl;
    while( (!(std::cin >> sort_mode_char)) || !((sort_mode_char == 'B') || (sort_mode_char == 'b') || (sort_mode_char == 'I') || (sort_mode_char == 'i') || (sort_mode_char == 'M') || (sort_mode_char == 'm')) )
    {
        std::cout << "Error. Enter the right mode!" << std::endl;
        std::cout << "Please try again: ";
        ClearCin();
    }
    ClearCin();

    void (*sort_type)(int **&, int, int, bool(*)(int, int));
    switch (sort_mode_char)
    {
        case 'B':
        case 'b':
            sort_type = BubbleSort;
            break;

        case 'I':
        case 'i':
            sort_type = InsertionSort;
            break;

        case 'M':
        case 'm':
            //sort_type = MergeSort;
            break;
    }

    //comparing types
    bool (*comp)(int, int);
    char comparing_symbol;
    std::cout << "How do you want to sort the matrix a1>a2 or a1<a2? Enter >/<" << std::endl;
    while( (!(std::cin >> comparing_symbol)) || !((comparing_symbol == '>') || (comparing_symbol == '<')) )
    {
        std::cout << "Error. Enter the right mode!" << std::endl;
        std::cout << "Please try again: ";
        ClearCin();
    }
    if(comparing_symbol == '>')
    {
        comp = A_more_than_B;
    }
    else
    {
        comp = A_less_than_B;
    }


    //row changing and sorting
    int left = 0, right = cols;
    int *temp = new int[cols];
    for(int row = 0; row < rows; ++row)
    {
        sort_type(matrix, row, cols, comp);
    }
    PrintMatrix(matrix, rows, cols);

    delete [] temp;
    DeleteMatrix(matrix, rows);
    return 0;
}

int **AllocateMatrix(int rows, int cols)
{
    int **matrix = new int*[rows];
    for(int row = 0; row < rows; ++row)
    {
        matrix [row] = new int [cols];
    }
    return matrix;
}

void DeleteMatrix(int ** matrix, int rows)
{
    if(matrix != nullptr)
    {
        for(int row = 0; row < rows; ++row)
        {
            delete [] matrix[row];
        }
        delete [] matrix;
        matrix = nullptr;
    }
}

int Enter_check_int(const int from) // Entering int number in [from, ...]
{
    int number;
    while(!(std::cin >> number)||(number < from))
    {
        ClearCin();
        std::cout << std::endl << "Enter right number! (type: int, from " << from <<" )" << std::endl;
    }
    return number;
}

int Enter_check_int()
{
    int number;
    while(!(std::cin >> number))
    {
        ClearCin();
        std::cout << std::endl << "Enter right number! (type: int)" << std::endl;
    }
    return number;
}

void FillMatrix(int **&matrix, int rows, int cols, char mode)
{
    switch (mode)
    {
        case 'M':
        case 'm':
            // filling the matrix manually
            for(int row = 0; row < rows; ++row)
            {
                std::cout << "Enter row " << row+1 << " values (" << cols << " numbers): " << std::endl;
                for(int col = 0; col < cols; ++col)
                {
                    matrix[row][col] = Enter_check_int();
                }
                std::cout << std::endl;
            }
            break;

        case 'A':
        case 'a':
            std::cout << "Enter the range of the array values [A, B]:" << std::endl;
            std::cout << "A: ";
            int from = Enter_check_int();
            std::cout << "B: ";
            int to = Enter_check_int();

            if(from > to)
            {
                std::swap(from, to);
            }

            // filling the matrix with random numbers
            for(int row = 0; row < rows; ++row)
            {
                for(int col = 0; col < cols; ++col)
                {
                    matrix[row][col] = GenerateRandom(from, to);
                }
                std::cout << std::endl;
            }
            break;

    }
}

int GenerateRandom(const int from, const int to)
{
    // Random Generation
    static std::mt19937 gen(45218965);
    std::uniform_int_distribution<int> dist(from, to);
    return dist(gen);
}

void PrintMatrix(int **matrix, int rows, int cols)
{
    if(matrix != nullptr)
    {
        std::cout << "Your Matrix: " << std::endl;
        for(int row = 0; row < rows; ++row)
        {
            for(int col = 0; col < cols; col++)
            {
                std::cout << matrix[row][col] << "   ";
            }
            std::cout << std::endl;
        }
    }
}

void ClearCin()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


void BubbleSort(int **&matrix, int row, int cols, bool (*comp)(int, int))
{
    for(int i = 0; i < cols; ++i)
    {
        bool swapping = false;
        for(int j = 0; j < cols-i-1; ++j)
        {
            if(!comp(matrix[row][j], matrix[row][j+1]))
            {
                std::swap(matrix[row][j], matrix[row][j+1]);
                swapping = true;
            }
        }
        if(!swapping)
        {
            break;
        }
    }
}

void InsertionSort(int **&matrix, int row, int cols, bool (*comp)(int, int))
{
    int x, i, j;
    for(i = 1; i < cols; ++i)
    {
        x = matrix[row][i];
        for(j = i-1; (j >= 0) && (!comp(matrix[row][j], x)); j--)
        {
            matrix[row][j+1] = matrix[row][j];
        }
        matrix[row][j+1] = x;
    }
}

/*void MergeSort(int **&matrix, int row, int left, int right, int *temp)
{
    if(right - left <= 1) return;
    int mid = (left + right)/2;
    MergeSort(matrix, row, left, mid, temp);
    MergeSort(matrix, row, mid, right, temp);
    merge(matrix, row, left, mid, right, temp);
}

void merge(int **&matrix, int row, int left, int mid, int right, int *temp)
{
    int i = left, j = mid, k = left;
    while(i < mid && j < right)
    {
        if(matrix[row][i] <= matrix[row][j])
        {
            temp[k] = matrix[row][i];
            i++;
        }
        else
        {
            temp[k] = matrix[row][j];
            j++;
        }
        k++;
    }
    while(i < mid)
    {
        temp[k] = matrix[row][i];
        i++;
        k++;
    }
    while(j < right)
    {
        temp[k] = matrix[row][j];
        j++;
        k++;
    }
    for(int t = left; t < right; t++)
    {
        matrix[row][t] = temp[t];
    }
}
*/
bool A_more_than_B(int a, int b)
{
    return a > b;
}

bool A_less_than_B(int a, int b)
{
    return a < b;
}