#include <iostream>

int main()
{
    int a, b, d, i;
if(std::cin>>a>>b>>d)
{
    i = a;
    if((a>b)||(d<0))
    {
        a=b;
        b=i;
    }
    for(i;i<=b;i+=d)
    {
        if(!(i%3))
        {
            std::cout<<i<<" ";
        }
    }
    return 0;
}
else
{
    std::cout<<"Error"<<std::endl;
    return 1;
}
    
}