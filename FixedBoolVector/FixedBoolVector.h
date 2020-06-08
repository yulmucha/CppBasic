#pragma once

#include <iostream>

template <typename T, size_t N>
class FixedVector
{
    FixedVector() { std::cout << "Normal Fixed Vector" << std::endl; };
};

template <size_t N>
class FixedVector<bool, N>
{
public:
    FixedVector();
    bool Add(const bool b);
    bool Remove(const bool b);
    bool Get(const unsigned int index) const;
    bool operator[](const unsigned int index) const;
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

template <size_t N>
FixedVector<bool, N>::FixedVector()
    : mSize(0)
{
    const unsigned int ARR_SIZE = (N + 31) / NUM_OF_BIT;
    for (unsigned int i = 0; i < ARR_SIZE; i++)
    {
        mArr[i] = 0;
    }
}

template <size_t N>
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

template <size_t N>
bool FixedVector<bool, N>::Remove(const bool b)
{
    int index = GetIndex(b);
    if (index < 0)
    {
        return false;
    }
    for (size_t i = index; i < mSize - 1; i++)
    {
        bool nextElement = Get(i + 1);
        if (nextElement == true)
        {
            mArr[i / NUM_OF_BIT] |= (1 << (i % NUM_OF_BIT));
        }
        else
        {
            mArr[i / NUM_OF_BIT] &= ~(1 << (i % NUM_OF_BIT));
        }
    }
    mSize--;
    return true;
}

template <size_t N>
bool FixedVector<bool, N>::Get(const unsigned int index) const
{
    return mArr[index / NUM_OF_BIT] & (1 << (index % NUM_OF_BIT));
}

template <size_t N>
bool FixedVector<bool, N>::operator[](const unsigned int index) const
{
    return Get(index);
}

template <size_t N>
int FixedVector<bool, N>::GetIndex(bool b) const
{
    for (size_t i = 0; i < mSize; i++)
    {
        bool e = (mArr[i / NUM_OF_BIT] & (1 << (i % NUM_OF_BIT))) > 0 ? true : false;
        if (e == b)
        {
            return i;
        }
    }

    return -1;
}

template <size_t N>
size_t FixedVector<bool, N>::GetSize() const
{
    return mSize;
}

template <size_t N>
size_t FixedVector<bool, N>::GetCapacity() const
{
    return N;
}