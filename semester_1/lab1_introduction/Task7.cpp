#include <iostream>

int main()
{
    int n, i;
    double s, x, max, min;
    std::cin>>n;
    std::cin>>x;
    max=x;
    min=x;
    s=x;
    for(i=1;i<n;i++)
    {
        std::cin>>x;
        if(x<min) min=x;
        if(x>max) max=x;
        s=s+x;
    }
    s=s/n;
    std::cout<<"Среднее арифметическое: "<<s<<std::endl;
    std::cout<<"Минимальное число: "<<min<<std::endl;
    std::cout<<"Максимальное число: "<<max<<std::endl;
    return 0;
}