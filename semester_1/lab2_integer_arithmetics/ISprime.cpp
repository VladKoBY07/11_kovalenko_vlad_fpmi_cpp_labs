#include <iostream>
#include <cmath>

bool isprime(int x)
{
    int i, n;
    bool flag;
    if((x == 2) || (x == 3))
    {
        return true;
    }
    else
    {
        i = 2;
        flag = 1;
        n = sqrt(x);
        while((i <= n) && (flag))
            if(!(x%i))
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

int main()
{
    int a;
    std::cin>>a;
    if (isprime(a))
    {
        std::cout<<"Prime"<<std::endl;
    }
    else
    {
        std::cout<<"Typical"<<std::endl;
    }
    return 0;
}
