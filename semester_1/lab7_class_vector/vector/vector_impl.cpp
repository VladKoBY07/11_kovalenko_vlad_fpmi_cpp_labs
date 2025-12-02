#include "vector_impl.h"
#include <iostream>

// конструктор по умолчанию
Vector::Vector() {};

// конструктор заполнения нулями
Vector::Vector(std::size_t amount)
{
    size_ = amount;
    capacity_ = size_;
    arr_ = new int [capacity_];
    for(std::size_t i = 0; i < amount; ++i)
    {
        arr_[i] = 0;
    }
}

// конструктор для заполнения списком
Vector::Vector(std::initializer_list<int> elements): size_(elements.size()), capacity_(size_), arr_(new int [capacity_])
{
    std::copy(elements.begin(), elements.end(), arr_);
}

// конструктор заполнения числом
Vector::Vector(int number, std::size_t amount): size_(amount), capacity_(size_), arr_(new int [capacity_])
{
    for(std::size_t i = 0; i < amount; ++i)
    {
        arr_[i] = number;
    }
}

// деструктор
Vector::~Vector()
{
    delete [] arr_;
}

// конструктор копирования
Vector::Vector(const Vector& other)
{
    size_ = other.size_;
    capacity_ = other.capacity_;
    arr_ = new int [capacity_];

    for(size_t i = 0; i < size_; ++i)
    {
        arr_[i] = other.arr_[i];
    }
}

// конструктор копирования через присваивание
Vector& Vector::operator = (const Vector& other)
{
    if(this == &other)
    {
        return *this;
    }

    delete [] arr_;

    size_ = other.size_;
    capacity_ = other.capacity_;
    arr_ = new int [capacity_];

    for(size_t i = 0; i < size_; ++i)
    {
        arr_[i] = other.arr_[i];
    }

    return *this;
}

// swap векторов
Vector& Vector::Swap(Vector& second)
{
    std::swap(arr_, second.arr_);
    std::swap(size_, second.size_);
    std::swap(capacity_, second.capacity_);

    return *this;
}

// оператор индексирования (константный)
const int& Vector::operator [](const std::size_t& index) const
{
    if(index >= size_)
    {
        throw std::out_of_range("Out of range!");
    }

    return arr_[index];
}

// оператор индексирования
int& Vector::operator [](const std::size_t& index)
{
    if(index >= size_)
    {
        throw std::out_of_range("Out of range!");
    }

    return arr_[index];
}

// метод At константный
const int& Vector::At (const std::size_t& index) const
{
    if(index >= size_)
    {
        throw std::out_of_range("Index is out of range");
    }

    return arr_[index];
}

// метод At
int& Vector::At (const std::size_t& index)
{
    if(index >= size_)
    {
        throw std::out_of_range("Index is out of range");
    }

    return arr_[index];
}

// метод size
std::size_t Vector::Size() const
{
    return size_;
}

// метод capacity
std::size_t Vector::Capacity() const
{
    return capacity_;
}

// метод PushBack
Vector& Vector::PushBack (int number)
{
    if(size_ == capacity_)
    {
        // reallocate
        std::size_t new_capacity;
        if(capacity_ == 0)
        {
            new_capacity = 1;
        }
        else
        {
            new_capacity = capacity_ * 2;
        }

        int* new_arr = new int [new_capacity];
        for(std::size_t i = 0; i < size_; ++i)
        {
            new_arr[i] = arr_[i];
        }

        delete [] arr_;
        arr_ = new_arr;
        capacity_ = new_capacity;
    }

    arr_[size_] = number;
    size_++;

    return *this;
}

// метод PopBack
Vector& Vector::PopBack()
{
    if(size_ > 0)
    {
        size_ --;
    }

    return *this;
}

// метод clear
Vector& Vector::Clear()
{
    if(size_ == 0)
    {
        return *this;
    }
    for(std::size_t i = 0; i < size_; ++i)
    {
        arr_[i] = 0;
    }

    size_ = 0;
    return *this;
}

// метод Reserve
Vector& Vector::Reserve(std::size_t new_capacity)
{
    if(new_capacity <= capacity_)
    {
        return *this;
    }

    int* new_arr = new int [new_capacity];

    for(std::size_t i = 0; i < size_; ++i)
    {
        new_arr[i] = arr_[i];
    }
    delete [] arr_;

    arr_ = new_arr;
    capacity_ = new_capacity;

    return *this;
}

std::ostream& operator << (std::ostream& outstream, const Vector& vec)
{
    outstream << "[";
    for(std::size_t i = 0; i < vec.Size(); ++i)
    {
        if(i > 0)
        {
            outstream << ", ";
        }
        outstream << vec[i];
    }
    outstream << "]";
    return outstream;
}