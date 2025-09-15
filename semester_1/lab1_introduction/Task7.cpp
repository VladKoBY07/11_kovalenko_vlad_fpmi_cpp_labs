#include <iostream>

int main()
{
    int n;
    double s, x, max, min;
    if(std::cin>>n>>x)
    {
        max=x;
        min=x;
        s=x;
        for(int i=1; i<n; i++)
        {
            std::cin>>x;
            if(x<min) min=x;
            if(x>max) max=x;
            s=s+x;
        }
        s=s/n;
        std::cout<<"Mid: "<<s<<std::endl;
        std::cout<<"Min: "<<min<<std::endl;
        std::cout<<"Max: "<<max<<std::endl;
        return 0;
    }
    else
    {
        std::cout<<"Error. Enter right numbers"<<std::endl;
        return 1;
    }
}