#include <iostream>

int main()
{
    int k, f=1, i;
    if((std::cin>>k)&&(k>=1))
    {
        if(k%2) i=1;
        else    i=2;
        
        for(;i<=k;i+=2)
        {
            f=f*i;
        }
        std::cout<<"Fact: "<<f<<std::endl;
        return 0;
    }
    else
    {
        std::cout<<"Error. Enter right number"<<std::endl;
        return 1;
    }
}