#include <iostream>

int main()
{
    int k, f, i;
    std::cin>>k;
    f=1;
    if(k%2) i=1;
    else    i=2;

    for(i;i<=k;i=i+2)
    {
    f=f*i;
    }
    std::cout<<"Факториал: "<<f<<std::endl;
    return 0;
}