#include <iostream>

int main()
{
    int n, s, p;
    std::cin>>n;
    s=0;
    p=1;
    for(n;n>=1;n--)
    {
        s=s+n;
        p=p*n;
    }
    std::cout<<"Сумма: "<<s<<std::endl;
    std::cout<<"Произведение: "<<p<<std::endl;
    return 0;
}