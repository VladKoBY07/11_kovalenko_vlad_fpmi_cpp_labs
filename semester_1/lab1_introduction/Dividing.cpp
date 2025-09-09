#include <iostream>

int main()
{
    int a, b, c, d;
    std::cin>>a>>b;
    if(b)
    {
    c=a/b;
    d=a%b;
    std::cout<<"Zelaya chast: "<<c<<std::endl;
    std::cout<<"Ostatok: "<<d;
    }
    else
    {
        std::cout<<"Na nol delit nelzya!"<<std::endl;
    }
    return 0;
}