#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    int n = 123;
    std::string number = std::to_string(n);
    while(std::next_permutation(number.begin(), number.end()))
    {
        std::cout << number << std::endl;
    }
    return 0;
}