#include <iostream>
#include <math.h>

void Array_enter(int *arr, int n);
void Print_array(int *arr, int n);
void Bubble_sort(int *arr, int n);

int main()
{
    const int MAX = 1000;
    int arr[MAX], n;
    std::cout << "Enter size of array: ";
    std::cin >> n;
    std::cout << std::endl;

    Array_enter(arr, n);

    Bubble_sort(arr, n);

    Print_array(arr, n);

    return 0;
}

void Array_enter(int *arr, int n)
{
    std::cout << "Enter array values:" << std::endl;
    for(int i = 0; i < n; ++i)
    {
        int number;
        if(std::cin >> number)
        {
            arr[i] = number;
        }
    }
}

void Print_array(int *arr, int n)
{
    std::cout << "Sorted array:" << std::endl;
    for(int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
}

void Bubble_sort(int *arr, int n)
{
    for(int i = 0; i < n-1; ++i)
    {
        bool swapping = false;
        for(int j = 0; j < n-i-1; ++j)
        {
            if(abs(arr[j]) > abs(arr[j+1]))
            {
                std::swap(arr[j], arr[j+1]);
                swapping = true;
            }
        }
        if(!swapping)
        {
            break;
        }
    }
}