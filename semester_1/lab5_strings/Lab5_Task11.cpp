#include <iostream>
#include <string>

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

        std::cout << "Your string:" << std::endl << inputStr;
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