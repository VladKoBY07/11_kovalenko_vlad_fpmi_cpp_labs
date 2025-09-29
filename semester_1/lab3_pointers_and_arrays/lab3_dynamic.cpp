
// solve task with usage of
// dymanic arrays

#include <iostream>
#include <time.h>

void bubbleSort(double *arr, int n);
void Swap (double &a, double &b);

int main() {
    int leng, from, to; // rand: [from; to]

    std::cout << "Enter the length of the array (1-100): ";
    if( (!(std::cin >> leng)) || (leng < 1))
    {
        std::cout << "Error. Enter the right number!" << std::endl;
        return 1;
    }
    int PlusLeng = leng + 1;
    double* arr = new double [PlusLeng];

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
                arr[i] = from + rand()/3 % (to - from + 1);
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
    int lastPosition = -1, firstPosition = -1;
    double product = 1;
    for(int i=0; lastPosition == -1, i < leng; i++)
    {
        if(arr[i] < 0) lastPosition = i;
    }
    for(int i = (leng-1); firstPosition == -1, i >= 0; i--)
    {
        if(arr[i] < 0) firstPosition = i;
    }
    //std::cout << std::endl << "FirstPos: " << firstPosition << " " << "LastPos: "<< lastPosition;
    if((lastPosition == -1) || (firstPosition == -1) || (lastPosition == firstPosition))
    {
        std::cout << std::endl << "Can't find numbers between first and last negative" << std::endl;
    }
    else
    {
        for(int i = (firstPosition+1); i < lastPosition; i++)
        {
            product *= (arr[i]);
        }
        std::cout << std::endl << "Product between first and last negative: " << product << std::endl;
    }


    // сортировка по возрастанию
    bubbleSort(arr, leng);
    std::cout << "Sorted array:" << std::endl;
    for(int i=0; i < leng; i++)
    {
        std::cout << arr[i] << " ";
    }

    //вставка элемента X
    std::cout << std::endl << "Enter X value: ";
    double X;
    if(!(std::cin >> X))
    {
        std::cout << "Error. Enter the right number!" << std::endl;
        return 1;
    }

    if((X <= arr[0]) || (X >= arr[leng-1]))
    {
        if(X <= arr[0])
        {
            for(int i = (PlusLeng-1); i > 0; i--)
            {
                arr[i] = arr[i-1];
            }
            arr[0] = X;
        }
        else
        {
            arr[PlusLeng-1] = X;
        }
    }
    else
    {
        int posx;
        for(posx=0; X > arr[posx]; posx++);
        for(int i = (PlusLeng-1); i > posx; i--)
        {
            arr[i] = arr[i-1];
        }
        arr[posx] = X;
    }

    std::cout << "Final array:" << std::endl;
    for(int i=0; i < PlusLeng; i++)
    {
        std::cout << arr[i] << " ";
    }
    

    delete [] arr;
    arr = nullptr;
    return 0;
}


void bubbleSort(double *arr, int n) // сортировка пузырьком
{
    for (int i = 0; i < n-1; i++)
    {
        bool swapping = false;
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
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