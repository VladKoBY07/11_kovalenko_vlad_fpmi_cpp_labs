#include <iostream>

int nod(int a, int b);

int main()
{
    unsigned int n, m, Nod;
    if((std::cin>>n>>m)&&(n)&&(m))
    {
        Nod = nod(n, m);
        std::cout<<"Nod: "<<Nod<<std::endl;
        std::cout<<"Dividers: ";
        for(int i=1; i<=Nod; i++)
        {
            if(!(Nod%i))
            {
                std::cout<<i<<" ";
            }
        }
        return 0;
    }
    else
    {
        std::cout<<"Error. Enter right numbers"<<std::endl;
        return 1;
    }
}

int nod(int a, int b)
{
    do
    {
        if(a>b)
        a=a%b;
        else
        b=b%a;
    } while ((a!=0)&&(b!=0));
    return a;
}