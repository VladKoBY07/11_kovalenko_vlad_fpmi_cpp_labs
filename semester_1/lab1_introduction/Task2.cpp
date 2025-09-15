#include <iostream>

int main()
{
    int n, s=0, p=1, i;
    if((std::cin>>n)&&(n>=1)) 
    {
        for(i=2;i<=n;i+=2)
        {
            s=s+i;
        }
        for(i=1;i<=n;i+=2)
        {
            p=p*i;
        }
    std::cout<<"Сумма: "<<s<<std::endl;
    std::cout<<"Произведение: "<<p<<std::endl;
    return 0;
    }
    else
    {
        std::cout<<"Error. Enter right number";
        return 1;
    }
}