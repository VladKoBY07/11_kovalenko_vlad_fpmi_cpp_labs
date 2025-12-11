#pragma once

struct fraction
{
    int divisible_;
    int divisor_;

    fraction(): divisible_(0), divisor_(1) {};
    ~fraction() {};

    fraction(const fraction& other)
    {
        divisible_ = other.divisible_;
        divisor_ = other.divisor_;
    };

    fraction(int divisible = 0, int divisor = 1): divisible_(divisible), divisor_(divisor) {};

    fraction& operator = (const fraction&);
    fraction& operator + (const fraction&);
    fraction& operator - (const fraction&);
    fraction& operator * (const fraction&);
    fraction& operator / (const fraction&);
    bool operator < (const fraction&);
    bool operator > (const fraction&);
    bool operator == (const fraction&);
    fraction& operator ++ ();
    fraction& operator -- ();
};