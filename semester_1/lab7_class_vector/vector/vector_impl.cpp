#include "vector_impl.h"
#include <iostream>

int main()
{
    Vector vector1 (5);
    Vector vector2 (7, 3);
    Vector vector3;
    vector3 = vector2;
    vector3.Swap(vector1);

    std::cout << "vector 1: " << vector1 << std::endl;
    std::cout << "vector 2: " << vector2 << std::endl;
    std::cout << "vector 3: " << vector3 << std::endl;
    return 0;
}