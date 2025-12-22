#include <iostream>
#include <set>
#include <cmath>

std::set<int> reshetoEratosphena(int n)
{
    std::set<int> prime_numbers;
    for(int i = 2; i <= n; ++i)
    {
        prime_numbers.insert(i);
    }

    int limit = sqrt(n);
    for(int p = 2; p < limit; ++p)
    {
        if(prime_numbers.find(p) != prime_numbers.end())
        {
            int multiple = p * p;
            while(multiple <= n)
            {
                prime_numbers.erase(multiple);
                multiple += p;
            }
        }
    }
    return prime_numbers;
}

int main() {
    try
    {
        int n;
        std::cout << "Enter N value: ";
        if(!(std::cin >> n))
        {
            throw "Error! Wrong N value";
        }

        std::set<int> prime_numbers = reshetoEratosphena(n);

        std::cout << "Prime numbers before N: " << std::endl;
        for(int number: prime_numbers)
        {
            std::cout << number << " ";
        }
        std::cout << std::endl;
        return 0;
    }
    catch(const char* msg)
    {
        std::cerr << msg << std::endl;
        return 1;
    }
    catch(...)
    {
        std::cerr << "Unexpected error!" << std::endl;
        return 1;
    }
}