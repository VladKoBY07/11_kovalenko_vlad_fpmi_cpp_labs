#include <iostream>

int main()
{
    unsigned int n, m, i;
    std::cin>>n>>m;
    std::cout<<"Общие делители:"<<std::endl;
    for(i=1;i<=n;i++)
    {
        if((!(n%i))&&(!(m%i)))
        {
            std::cout<<i<<std::endl;
        }
    }
    return 0;
}