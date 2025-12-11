#include <iostream>
#include "MyString.h"

int main()
{
    String str('a', 10);
    String str1(str);

    String str2;
    str2 = str1;
    return 0;
}