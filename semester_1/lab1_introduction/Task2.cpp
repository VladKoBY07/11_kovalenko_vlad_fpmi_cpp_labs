#include <iostream>

int main()
{
    int n, s, p, i;
    std::cin>>n;
    s=0;
    p=1;
    if(n<1){std::cout<<"Error. Enter right number"}
else{
    for(i=2;i<=n;i=i+2)
    {
        s=s+i;
    }
    for(i=1;i<=n;i=i+2)
    {
        p=p*i;
    }
    std::cout<<"Сумма: "<<s<<std::endl;
    std::cout<<"Произведение: "<<p<<std::endl;
}
    return 0;
}