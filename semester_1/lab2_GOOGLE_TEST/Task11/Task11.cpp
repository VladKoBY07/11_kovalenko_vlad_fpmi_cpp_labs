#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

#include "SupPrimeHeader.h"

int main()
{
    unsigned a, b;
    std::cout << "Enter two numbers ( range: from .. to .. )" << std::endl;

    try
    {
        a = EnterUnsigned();
        b = EnterUnsigned();

        std::cout << "Super prime numbers from " << a << " to " << b << ":" << std::endl;
        if (a > b)
        {
            Swap(a, b);
        }
        for (unsigned number = a; number <= b; ++number)
        {
            if (is_supprime(number))
            {
                std::cout << number << std::endl;
            }
        }
        return 0;
    }
    catch (const char* msg)
    {
        std::cerr << msg;
    }
    catch (...)
    {
        std::cerr << "Unknown Error!";
    }
}