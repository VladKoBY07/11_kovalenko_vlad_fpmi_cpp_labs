#include <iostream>

int main()
{
    unsigned int n, s=0, z=1;
    if((std::cin>>n)&&(n>0))
    {
        for(int i=0; i<n; i++, z+=2)
        {
            s+=z;
        }
        std::cout<<"Sum: "<<s<<std::endl;
        return 0;
    }
    else
    {
        std::cout<<"Error. Enter right number"<<std::endl;
        return 1;
    }
}