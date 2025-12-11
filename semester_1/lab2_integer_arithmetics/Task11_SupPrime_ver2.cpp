#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

void Swap(unsigned &, unsigned &);
bool is_supprime(unsigned);
bool isprime(unsigned);
int length(unsigned);

int main()
{
    unsigned a, b;
    std::cout << "Enter two numbers ( range: from .. to .. )" << std::endl;

    if (!(std::cin >> a) || !(std::cin >> b))
    {
        std::cout << "Error. Enter right numbers" << std::endl;
        return 1;
    }

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

void Swap(unsigned &a, unsigned &b)
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
    int i, n;
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