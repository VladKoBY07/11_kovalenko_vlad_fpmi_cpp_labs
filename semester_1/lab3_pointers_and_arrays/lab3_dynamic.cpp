
// solve task with usage of
// dymanic arrays

#include <iostream>
#include <time.h>

int main() {
    int leng, from, to; // rand: [from; to]

    std::cout << "Enter the length of the array (1-100): ";
    if( (!(std::cin >> leng)) || (leng < 1))
    {
        std::cout << "Error. Enter the right number!" << std::endl;
        return 1;
    }

    int* arr = new int [leng];

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
                if(std::cin >> arr[i]) {}
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
                arr[i] = from + rand() % (to - from + 1);
            }
            break;

    }

    // Вывод массива
    std::cout << "array:" << std::endl;
    for(int i=0; i < leng; i++)
    {
        std::cout << arr[i] << " ";
    }

    // произведение между первым и последним отрицательным элементом
    int lastPosition = -1, firstPosition = -1, product = 1;
    for(int i=0; lastPosition == -1, i < leng; i++)
    {
        if(arr[i] < 0) lastPosition = i;
    }
    for(int i = (leng-1); firstPosition == -1, i >= 0; i--)
    {
        if(arr[i] < 0) firstPosition = i;
    }
    std::cout << std::endl << "FirstPos: " << firstPosition << " " << "LastPos: "<< lastPosition;
    if((lastPosition == -1) || (firstPosition == -1) || (lastPosition == firstPosition))
    {
        std::cout << "Can't find numbers between first and last negative";
    }
    else
    {
        for(int i = (firstPosition+1); i < lastPosition; i++)
        {
            product *= (arr[i]);
        }
        std::cout << std::endl << "Product between first and last negative: " << product;
    }
    

    delete [] arr;
    arr = nullptr;
    return 0;
}