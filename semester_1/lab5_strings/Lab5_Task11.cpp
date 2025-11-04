#include <iostream>
#include <string>
#include <cmath>

bool IsLetter(char x)
{
    return (x >= 'A' && x <= 'Z')||(x >= 'a' && x <= 'z');
}

bool IsVovel(char x)
{
    return (x == 'a')||(x == 'A')||(x == 'e')||(x == 'E')||(x == 'i')||(x == 'I')
    ||(x == 'o')||(x == 'O')||(x == 'u')||(x == 'U')||(x == 'y')||(x == 'Y');
}

bool AreDoublesEqual(double a, double b, double epsilon)
{
    double diff = fabs(a - b);
    return (diff < epsilon);
}

bool Is_A_more_than_B(double a, double b, double epsilon)
{
    double diff = fabs(a - b);
    return (diff > epsilon)&&((a-b) > 0.0);
}

int main()
{
    try
    {
        std::cout << "Enter your string:" << std::endl;
        std::string inputStr;
        getline(std::cin, inputStr);
        if(inputStr.empty())
        {
            throw("Error. Input string is empty!");
        }

        std::cout << "Enter precision of comparing percentage of vovels: " << std::endl;
        double epsilon;
        if(!(std::cin >> epsilon))
        {
            throw("Precision value error!");
        }

        size_t length = inputStr.length();
        double percentage = 0;
        double MaxPercentage = 0;
        std::string result;

        for(size_t index = 0; index < length; ++index)
        {
            std::string word;
            double numberOfVovels = 0, numberOfLetters = 0;
            while(IsLetter(inputStr[index])&&(index < length))
            {
                word.push_back(inputStr[index]);
                if(IsVovel(inputStr[index]))
                {
                    numberOfVovels++;
                }
                numberOfLetters++;
                index++;
            }
            //std::cout << numberOfLetters << std::endl << numberOfVovels << std::endl;
            //std::cout << word << std::endl << std::endl;
            if(numberOfLetters > 0)
            {
                percentage = numberOfVovels / numberOfLetters * 100;
                //std::cout << "Percentage of vovels: " << percentage << std::endl;
                if(AreDoublesEqual(percentage, MaxPercentage, epsilon))
                {
                    result.push_back(' ');
                    result.append(word);
                }
                if(Is_A_more_than_B(percentage, MaxPercentage, epsilon))
                {
                    MaxPercentage = percentage;
                    result.clear();
                    result.append(word);
                }
            }
            word.clear();
        }

        std::cout << "Result:" << std::endl << result << std::endl;
        std::cout << "Vovel Percentage: " << MaxPercentage << " %" << std::endl;
        return 0;
    }
    catch(const char * err)
    {
        std::cerr << err;
        return 1;
    }
    catch(...)
    {
        std::cerr << "Unexpected error!" << std::endl;
        return 1;
    }
}