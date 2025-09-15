#include <iostream>

int main()
{
    unsigned long long p, s=0;
    int n, i;
    if((std::cin>>n)&&(n>=1))
    {
        for(;n>=1;n--)
        {
            p=1;
            for(i=0;i<n;i++)
            {
                p=p*n;
            }
            s=s+p;
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

/*При вводе больших чисел программа выдаёт очевидно неверные отрицательные значения,
вероятно это вызвано ограниченным диапазоном переменной int. Для увеличения максимального
числа можно воспользоваться типом long long и применить модификатор unsigned, предполагая что
ответ всегда будет положительным (ограничение - 18 446 744 073 709 551 615)*/