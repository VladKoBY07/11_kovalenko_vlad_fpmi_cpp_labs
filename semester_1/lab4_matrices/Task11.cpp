
#include <iostream>
#include <cmath>
#include <time.h>
#include <random>

int **AllocateMatrix(int, int);
void DeleteMatrix(int **, int);
int Enter_check_int(const int, const int);
int Enter_check_int();
void FillMatrix(int **&, int, int, char);
int GenerateRandom(const int, const int);
void PrintMatrix(int **, int, int);
void ClearCin();

int Count_colums_without_zero(int **, int, int);

int main() {

    int rows, cols;
    const int  max_rows = 1000, max_cols = 1000;   // Max size of matrix
    std::cout << "Creating matrix (rows x cols)" << std::endl;
    std::cout << "Enter rows: ";
    rows = Enter_check_int(1, max_rows);
    std::cout << "Enter cols: ";
    cols = Enter_check_int(1, max_cols);
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
    PrintMatrix(matrix, rows, cols);

    std::cout << "Number of colums without zero: " << Count_colums_without_zero(matrix, rows, cols) << std::endl;

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

int Enter_check_int(const int from, const int to) // Entering int number in [from, to]
{
    int number;
    while(!(std::cin >> number)||(number < from)||(number > to))
    {
        ClearCin();
        std::cout << std::endl << "Enter right number! (type: int, from " << from << " to " << to << ")" << std::endl;
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
                    std::cin >> matrix[row][col];
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

int Count_colums_without_zero(int **matrix, int rows, int cols)
{
    int amount = 0;
    bool ColHasZero;
    for(int col = 0; col < cols; ++col)
    {
        ColHasZero = 0;
        for(int row = 0; row < rows; ++row)
        {
            if(matrix[row][col] == 0)
            {
                ColHasZero = 1;
                break;                
            }
        }
        if(ColHasZero)
        {
            continue;
        }
        amount++;
    }
    return amount;
}