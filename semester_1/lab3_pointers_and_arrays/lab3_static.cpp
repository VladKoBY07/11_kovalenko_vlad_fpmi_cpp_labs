
// solve task with usage of
// static arrays

#include <iostream>
#include <cmath>
#include <time.h>

void bubbleSort(double arr[], int n);
void Swap (double &a, double &b);

int main() {
    const int MAX = 100;
    int leng, from, to;
    double a[MAX]; // rand: [from; to]

    std::cout << "Enter the length of the array (1-100): ";
    if( (!(std::cin >> leng)) || (leng < 1) || (leng > MAX))
    {
        std::cout << "Error. Enter the right number!" << std::endl;
        return 1;
    }

    char mode;
    std::cout << "How do you want to fill the array Manual/Auto (Enter M/A)? ";
    while( (!(std::cin >> mode)) || ((mode != 'M') && (mode != 'A')) )
    {
        std::cout << "Error. Enter the right mode!" << std::endl;
        std::cout << "Please try again: ";
    }

    switch (mode)
    {
        case 'M':
            std::cout << "Enter the array values: " << std::endl;
            for(int i=0; i < leng; i++)
            {
                if(!(std::cin >> a[i]))
                {
                    std::cout << "Error. Wrong type" << std::endl;
                    return 1;
                }
            }
            break;

        case 'A':
            std::cout << "Enter the range of the array values [A, B]:" << std::endl;
            std::cout << "A: ";
            if(!(std::cin >> from))
            {
                std::cout << "Error. Enter the right number!" << std::endl;
                return 1;
            }
            std::cout << "B: ";
            if(!(std::cin >> to))
            {
                std::cout << "Error. Enter the right number!" << std::endl;
                return 1;
            }

            // filling the array
            srand(time(0));
            for(int i=0; i < leng; i++)
            {
                a[i] = from + rand() % (to - from + 1);
            }
            break;

    }

    // Вывод массива
    std::cout << "array:" << std::endl;
    for(int i=0; i < leng; i++)
    {
        std::cout << a[i] << " ";
    }

    // 1. Локальные минимумы
    std::cout << std::endl << "Local minimums (Positions of minimums in array): ";
    if(leng < 3)
    {
        std::cout << "Can't find the minimums" << std::endl;
    }
    else
    {
        if(a[0] < a [1]) std::cout << "1 ";
        for(int i=1; i < leng-1; i++)
        {
            if((a[i-1] > a[i]) && (a[i] < a[i+1]))
            std::cout << i+1 << " ";
        }
        if(a[leng-2] > a[leng-1]) std::cout << leng;
    }

    // 2. Сумма элементов после первого минимального элемента
    int start = 0;
    double sum = 0, min = a[0];
    for(int i = 1; i < leng; i++)
    {
        if((a[i] < a[i-1]) && (a[i] < min))
        {
            min = a[i];
            start = i;
        }
    }
    if(start != leng)
    {
        start++;
        for(int i = start; i < leng; i++)
        {
            sum += a[i];
        }
    }
    std::cout << std::endl << "Summary after " << start << " element: " << sum << std::endl;

    // сортировка по модулю
    bubbleSort(a, leng);
    std::cout << "Abs-sorted array:" << std::endl;
    for(int i=0; i < leng; i++)
    {
        std::cout << a[i] << " ";
    }

    return 0;
}

void bubbleSort(double *arr, int n) // сортировка пузырьком по модулю
{
    for (int i = 0; i < n-1; i++)
    {
        bool swapping = false;
        for (int j = 0; j < n-i-1; j++)
        {
            if (fabs(arr[j]) > fabs(arr[j+1]))
            {
            Swap(arr[j], arr[j+1]);
            swapping = true;
            }
        }
        if(!swapping)
        {
            break;
        }
    }
}

void Swap (double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}