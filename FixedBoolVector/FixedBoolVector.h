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

template <unsigned int N>
FixedVector<bool, N>::FixedVector()
    : mSize(0)
{
    const unsigned int ARR_SIZE = (N + 31) / NUM_OF_BIT;
    for (unsigned int i = 0; i < ARR_SIZE; i++)
    {
        mArr[i] = 0;
    }
}

template <unsigned int N>
bool FixedVector<bool, N>::Add(const bool b)
{
    if (mSize >= N)
    {
        return false;
    }

    if (b)
    {
        mArr[mSize / NUM_OF_BIT] |= (b << (mSize % NUM_OF_BIT));
    }
    mSize++;
    return true;
}

template <unsigned int N>
bool FixedVector<bool, N>::Get(const unsigned int index) const
{
    return mArr[index / 32] & (1 << (index % 32));
}

template <unsigned int N>
size_t FixedVector<bool, N>::GetSize() const
{
    return mSize;
}