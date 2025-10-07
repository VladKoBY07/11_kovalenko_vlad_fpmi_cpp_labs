#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

bool isprime(int x);
int length(int z);

int main()
{
    unsigned int a, b, leng, ncomb;
    if((std::cin >> a) && (a>0) && (std::cin>>b) && (b>0))
    {
        if(a>b) //swap
        {
            a=a+b;
            b=a-b;
            a=a-b;
        }

        for(a; a<=b; a++)
        {
            if(isprime(a))
            {
                /*leng=length(a); //length
                ncomb=1;
                for(int i=1; i<=leng; i++) //number of combinations
                {
                    ncomb *= i;
                }
                std::cout << "Prime number: " << a << std::endl;
                std::cout << "Length of numder: " << leng << std::endl;
                std::cout << "Possible combinations: "<< ncomb << std::endl;*/

                std::string number = std::to_string(a);
                bool flag = 1;
                while(std::next_permutation(number.begin(), number.end()))
                {
                    int int_number = std::stoi(number);
                    if(!(isprime(int_number)))
                    {
                        flag = 0;
                    }
                }
                if(flag) std::cout << "Number is super prime!" << std::endl;
                /*if(leng == 2)
                {
                    int number = a;
                    std::cout << "Combinations: " << number;
                    char pos2 = number / 10 % 10;
                    char pos1 = number % 10;
                    number = pos1*10 + pos2;
                    std::cout << " " << number << std::endl;
                    if(isprime(number))
                    {
                        std::cout << "Number is super prime!" << std::endl;
                    }
                }*/
                std::cout << std::endl;
            }
            else
            {
                continue;
            }
        }
        return 0;
    }
    else
    {
        std::cout<<"Error. Enter right number"<<std::endl;
        return 1;
    }
}

bool isprime(int x)
{
    int i, n;
    bool flag;
    if((x == 2) || (x == 3))
    {
        return true;
    }
    else
    {
        i = 2;
        flag = 1;
        n = sqrt(x);
        while((i <= n) && (flag))
            if(!(x%i))
            {
                flag = 0;
            }
            else
            {
                ++i;
            }
        return flag;
    }
}

int length(int y)
{
    int i=0;
    while(y) {y=y/10; i++;}
    return i;
}