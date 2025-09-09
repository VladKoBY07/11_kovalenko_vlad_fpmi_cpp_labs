#include <iostream>

int main()
{
    int n, s, p, i;
    std::cin>>n;
    s=0;
    for(n;n>=1;n--)
    {
        p=1;
        for(i=0;i<n;i++)
        {
            p=p*n;
        }
        s=s+p;
    }
    std::cout<<"Сумма: "<<s<<std::endl;
    return 0;
}