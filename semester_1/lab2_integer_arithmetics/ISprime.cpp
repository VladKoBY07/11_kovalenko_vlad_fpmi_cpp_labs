#include <iostream>

int main()
{
    int n;
    std::cin>>n;
    if (((n * n) % 24 == 1)||(n==2)||(n==3))
    {
        std::cout<<"Prime";
    }
    return 0;
}