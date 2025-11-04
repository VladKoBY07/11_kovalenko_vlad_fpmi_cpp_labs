
#include <iostream>
#include <cmath>
#include <time.h>
#include <random>

int **AllocateMatrix(int, int);
void DeleteMatrix(int **, int);
void FillMatrix(int **&, int, int, char);
int GenerateRandom(const int, const int);
void PrintMatrix(int **, int, int);
void ClearCin();

int Measure_characteristics_in_row(int **, int, int);
void BubbleSort_colums(int **&, int, int);
void Swap_rows(int **&, int, int);
int Count_colums_without_zero(int **, int, int);

int main() {
try{
    int rows, cols;
    std::cout << "Creating matrix (rows x cols)" << std::endl;
    std::cout << "Enter rows: ";
    if(!(std::cin >> rows)||(rows < 1))
    {
        throw("Rows value error!");
    }
    std::cout << "Enter cols: ";
    if(!(std::cin >> cols)||(cols < 1))
    {
        throw("Cols value error!");
    }
    std::cout << std::endl;

    int ** matrix = AllocateMatrix(rows, cols);
    if(matrix == nullptr)
    {
        throw("Matrix allocation error!");
    }

    char mode;
    std::cout << "How do you want to fill the matrix Manually/Auto?";
    std::cin >> mode;
    if((mode != 'M')&&(mode != 'm')&&(mode != 'A')&&(mode != 'a'))
    {
        throw("Mode value error!");
    }
    ClearCin();
    
    FillMatrix(matrix, rows, cols, mode);
    std::cout << "Before Sorting:" << std::endl;
    PrintMatrix(matrix, rows, cols);

    BubbleSort_colums(matrix, rows, cols);
    std::cout << "After Sorting: " << std::endl;
    PrintMatrix(matrix, rows, cols);

    std::cout << "Number of colums without zero: " << Count_colums_without_zero(matrix, rows, cols) << std::endl;
    DeleteMatrix(matrix, rows);
    return 0;
}
catch(const char* err)
{
    std::cerr << err;
    return 1;
}
catch(...)
{
    std::cerr << "Unknown error!";
    return 1;
}
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
                    if(!(std::cin >> matrix[row][col]))
                    {
                        throw("Matrix element error!");
                    }
                }
                std::cout << std::endl;
            }
            break;

        case 'A':
        case 'a':
            std::cout << "Enter the range of the array values [A, B]:" << std::endl;
            std::cout << "A: ";
            int from;
            if(!(std::cin >> from))
            {
                throw("Range value error!");
            }
            std::cout << "B: ";
            int to;
            if(!(std::cin >> to))
            {
                throw("Range value error!");
            }

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
        for(int row = 0; row < rows; ++row)
        {
            for(int col = 0; col < cols; col++)
            {
                std::cout << matrix[row][col] << "   ";
            }
            std::cout << std::endl;
        }
    }
    else
    {
        throw("Printing error: matrix is empty!");
    }
}

void ClearCin()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int Measure_characteristics_in_row(int **matrix, int row_number, int cols)
{
    if(cols < 1)
    {
        return 0;
    }
    int Characteristics = 0, number;
    for(int col = 0; col < cols; ++col)
    {
        number = matrix[row_number][col];
        if(number > 0)
        {
            Characteristics += number;
        }
    }
    return Characteristics;
}

void BubbleSort_colums(int **&matrix, int rows, int cols)
{
    for(int i = 0; i < rows-1; ++i)
    {
        bool swapping = false;
        for(int j = 0; j < rows-i-1; ++j)
        {
            if(Measure_characteristics_in_row(matrix, j, cols) > Measure_characteristics_in_row(matrix, j+1, cols))
            {
                Swap_rows(matrix, j, j+1);
                swapping = true;
            }
        }
        if(!swapping)
        {
            break;
        }
    }
}

void Swap_rows(int **&matrix, int row1, int row2)
{
    int *temp = matrix[row1];
    matrix[row1] = matrix[row2];
    matrix[row2] = temp;
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