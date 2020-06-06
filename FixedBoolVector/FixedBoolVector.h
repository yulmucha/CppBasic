#pragma once

#include <iostream>

template <typename T, unsigned int N>
class FixedVector
{
    FixedVector() { std::cout << "Normal Fixed Vector" << std::endl; };
};

template <unsigned int N>
class FixedVector<bool, N>
{
public:
    FixedVector();
    bool Add(const bool b);
    bool Remove(const bool b);
    bool Get(const unsigned int index) const;
    bool operator[](const unsigned int index);
    int GetIndex(const bool b) const;
    size_t GetSize() const;
    size_t GetCapacity() const;

private:
    enum
    {
        NUM_OF_BIT = 32
    };
    int32_t mArr[(N + 31) / NUM_OF_BIT];
    size_t mSize;
};