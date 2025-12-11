#include "SupPrimeHeader.h"
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

unsigned EnterUnsigned()
{
    unsigned input;
    if (!(std::cin >> input))
    {
        throw "Error. Input number is incorrect!";
    }
    return input;
}

void Swap(unsigned& a, unsigned& b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}

bool is_supprime(unsigned number)
{
    if (!(isprime(number)))
    {
        return false;
    }

    std::string str_number = std::to_string(number);
    while (std::next_permutation(str_number.begin(), str_number.end()))
    {
        unsigned int_number = std::stoi(str_number);
        if (!(isprime(int_number)))
        {
            return false;
        }
    }

    return true;
}

bool isprime(unsigned x)
{
    unsigned i, n;
    bool flag;
    if ((x == 2) || (x == 3))
    {
        return true;
    }
    else
    {
        i = 2;
        flag = 1;
        n = sqrt(x);
        while ((i <= n) && (flag))
            if (!(x % i))
            {
                flag = 0;
            }
            else
            {
                ++i;
            }
        return flag;
    }
}

int length(unsigned x)
{
    int i = 0;
    for (i; x; x /= 10, ++i);
    return i;
}