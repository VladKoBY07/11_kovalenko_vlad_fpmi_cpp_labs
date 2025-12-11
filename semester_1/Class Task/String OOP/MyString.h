#pragma once

class String
{
private:
    size_t size_ = 0;
    char* arr_ = nullptr;

public:
    String(){};
    String(char ch, size_t amount): size_(amount + 1), arr_(new char [size_])
    // порядок не как написано а как инициализированы в private
    {
        //arr_ = new char [amount+1];
        for(size_t i = 0; i < amount; ++i)
        {
            arr_[i] = ch;
        }
        arr_[amount] = '\0';
        //size_ = amount + 1;
    }
    ~String()  // destructor
    {
        delete [] arr_;
    }

    String(const String& other) // copy
    {
        //arr_ = other.arr_;    // обычное присваивание но в динам массиве скопируется ссылка и копирование будет не корректно
        //size_ = other.size_;

        size_ = other.size_;
        arr_ = new char [size_];

        for(size_t i = 0; i < size_; ++i)
        {
            arr_[i] = other.arr_[i];
        }
    }

    String& operator = (const String& other) // copy with operator =
    {
        if(this == &other)
        {
            return *this;
        }

        delete [] arr_;       // delete memory of old object before copying

        size_ = other.size_;
        arr_ = new char [size_];

        for(size_t i = 0; i < size_; ++i)
        {
            arr_[i] = other.arr_[i];
        }

        return *this;
    }
};