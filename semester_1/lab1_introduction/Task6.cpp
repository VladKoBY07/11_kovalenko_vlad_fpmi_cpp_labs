#include <iostream>

int main()
{
    unsigned int n, s, i;
    std::cin>>n;
    s=0;
    for(i=1;n>0;i=i+2)
    {
        n--;
        s=s+i;
    }
    std::cout<<"Сумма: "<<s<<std::endl;
    return 0;
}