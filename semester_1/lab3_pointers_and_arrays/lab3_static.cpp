
// solve task with usage of
// static arrays

#include <iostream>
#include <time.h>

int main() {
    const int MAX = 100;
    int a[MAX], leng, from, to; // rand: [from; to]

    std::cout << "Enter the length of the array (1-100): ";
    if( (!(std::cin >> leng)) || (leng < 1) || (leng > MAX))
    {
        std::cout << "Error. Enter the right number!" << std::endl;
        return 1;
    }

    char mode;
    std::cout << "How do you want to fill the array M/A? ";
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
                if(std::cin >> a[i]) {}
                else
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
    int start = 0, sum = 0;
    for(int i = 1; i < leng; i++)
    {
        if(a[i] < a[i-1])
        {
            start = i;
        }
    }
    if(start != leng)
    {
        for(int i = start+1; i < leng; i++)
        {
            sum += a[i];
        }
    }
    std::cout << std::endl << "Summary after " << start+1 << " element: " << sum << std::endl;

    return 0;
}