#include "Fractions.h"
#include <algorithm>

fraction& fraction::operator = (const fraction& rhs)
{
    if(this == &rhs)
    return *this;

    divisible_ = rhs.divisible_;
    divisor_ = rhs.divisor_;
    return *this;
}

int NOD(const int& x, const int& y) {
    int a = x, b = y;
    if (a < b) {
        std::swap(a, b);
    }
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int NOK (const int& x, const int& y)
{
    int a = x, b = y;
    return a / NOD(a, b) * b;
}

fraction& fraction::operator + (const fraction& rhs)
{
    if(divisor_ == rhs.divisor_)
    {
        divisible_ = divisible_ + rhs.divisible_;
        return *this;
    }

    int new_divisor = NOK(divisor_, rhs.divisor_);
    int new_divisible_ = divisible_ * (new_divisor / divisor_);
    int new_rhs_divisible_ = rhs.divisible_ * (new_divisible_ / rhs.divisor_);
    divisible_ = new_divisible_ + new_rhs_divisible_;
    divisor_ = new_divisor;
    return *this;
}

fraction& fraction::operator - (const fraction& rhs)
{
    if(divisor_ == rhs.divisor_)
    {
        divisible_ = divisible_ - rhs.divisible_;
        return *this;
    }

    int new_divisor = NOK(divisor_, rhs.divisor_);
    int new_divisible_ = divisible_ * (new_divisor / divisor_);
    int new_rhs_divisible_ = rhs.divisible_ * (new_divisible_ / rhs.divisor_);
    divisible_ = new_divisible_ - new_rhs_divisible_;
    divisor_ = new_divisor;
    return *this;
}

fraction& fraction::operator * (const fraction& rhs)
{
    divisible_ = divisible_ * rhs.divisible_;
    divisor_ = divisor_ * rhs.divisor_;
    return *this;
}

fraction& fraction::operator / (const fraction& rhs)
{
    int rev_divisible = rhs.divisor_;
    int rev_divisor = rhs.divisible_;
    divisible_ = divisible_ * rev_divisible;
    divisor_ = divisor_ * rev_divisor;
    return *this;
}

bool fraction::operator < (const fraction& rhs)
{
    if(this == &rhs)
    {
        return false;
    }

    int new_divisor = NOK(divisor_, rhs.divisor_);
    int new_divisible_ = divisible_ * (new_divisor / divisor_);
    int new_rhs_divisible_ = rhs.divisible_ * (new_divisible_ / rhs.divisor_);
    
    return new_divisible_ < new_rhs_divisible_;
}

bool fraction::operator > (const fraction& rhs)
{
    if(this == &rhs)
    {
        return false;
    }

    int new_divisor = NOK(divisor_, rhs.divisor_);
    int new_divisible_ = divisible_ * (new_divisor / divisor_);
    int new_rhs_divisible_ = rhs.divisible_ * (new_divisible_ / rhs.divisor_);
    
    return new_divisible_ > new_rhs_divisible_;
}

bool fraction::operator == (const fraction& rhs)
{
    if(this == &rhs)
    {
        return true;
    }

    int new_divisor = NOK(divisor_, rhs.divisor_);
    int new_divisible_ = divisible_ * (new_divisor / divisor_);
    int new_rhs_divisible_ = rhs.divisible_ * (new_divisible_ / rhs.divisor_);
    
    return new_divisible_ == new_rhs_divisible_;
}

fraction& fraction::operator ++ ()
{
    divisible_ = divisible_ + divisor_;
    return *this;
}

fraction& fraction::operator -- ()
{
    divisible_ = divisible_ - divisor_;
    return *this;
}