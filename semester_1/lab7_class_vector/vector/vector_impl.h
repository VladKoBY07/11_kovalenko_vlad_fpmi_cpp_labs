#pragma once
#include <cstdint>
#include <initializer_list>
#include <algorithm>
#include <iostream>
#include <stdexcept>

class Vector
{
friend std::ostream& operator << (std::ostream& outstream, const Vector& vec);

private:
    std::size_t size_ = 0;
    std::size_t capacity_ = 0;
    int* arr_ = nullptr;

public:
    // конструктор по умолчанию
    Vector();

    // конструктор заполнения нулями
    Vector(std::size_t amount);

    // конструктор для заполнения списком
    Vector(std::initializer_list<int> elements);

    // конструктор заполнения числом
    Vector(int number, std::size_t amount);

    // деструктор
    ~Vector();

    // конструктор копирования
    Vector(const Vector& other);

    // конструктор копирования через присваивание
    Vector& operator = (const Vector& other);

    // swap векторов
    Vector& Swap(Vector& second);

    // оператор индексирования (константный)
    const int& operator [](const std::size_t& index) const;

    // оператор индексирования
    int& operator [](const std::size_t& index);

    // метод At константный
    const int& At (const std::size_t& index) const;

    // метод At
    int& At (const std::size_t& index);

    // метод size
    std::size_t Size() const;

    // метод capacity
    std::size_t Capacity() const;

    // метод PushBack
    Vector& PushBack (int number);

    // метод PopBack
    Vector& PopBack();

    // метод clear
    Vector& Clear();

    // метод Reserve
    Vector& Reserve(std::size_t new_capacity);
};