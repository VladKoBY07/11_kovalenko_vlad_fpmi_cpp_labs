#include <iostream>

int findmin(int x);
int length(int y);
int digit(int z);

int main()
{
    int n;
    if((std::cin >> n) && (n > 0))
    {
        int min = findmin(n);
        //std::cout << "min: " << min << std::endl;
        int leng = length(n);
        //std::cout << "length: " << leng << std::endl;
        int current, temp;
        for(int i=0; i < leng; i++)
        {
            current = (n / (digit(i))) % 10;
            if(current == min)
            {
                if(i == 0)
                {
                    n = n/10;
                }
                else
                {
                    temp = n % digit(i);
                    n /= digit(i+1);
                    n *= digit(i);
                    n += temp;
                    leng--;
                    i = 0;
                }
            }
        }
        std::cout << n << std::endl;
        return 0;
    }
    else
    {
        std::cout << "Error. Enter right number" << std::endl;
        return 1;
    }
}

int findmin(int x)
{
    int minimal = 9;
    while(x)
    {
        if ((x % 10) < (minimal))
        {
            minimal = x % 10;
        }
        x /= 10;
    }
    return minimal;
}

int length(int y)
{
    int i=0;
    while(y) {y=y/10; i++;}
    return i;
}

int digit(int z)
{
    int p=1;
    for(int c = 0; c<z; c++)
    {
        p *= 10;
    }
    return p;
}