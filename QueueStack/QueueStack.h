#pragma once

#include <queue>
#include <stack>

template<typename T>
class QueueStack
{
public:
	QueueStack(const unsigned int maxStackSize);
	void Enqueue(const T number);
	T Peek() const;
	T Dequeue();
	T Max() const;
	T Min() const;
	T Sum() const;
	double Average() const;
	unsigned int Count() const;
	unsigned int StackCount() const;
private:
	unsigned int mMaxStackSize;
	unsigned int mCount;
	std::queue<std::stack> mNumbers;
};

template<typename T>
inline QueueStack<T>::QueueStack(const unsigned int maxStackSize)
{
}

template<typename T>
inline void QueueStack<T>::Enqueue(const T number)
{
}

template<typename T>
inline T QueueStack<T>::Peek() const
{
	return T();
}

template<typename T>
inline T QueueStack<T>::Dequeue()
{
	return T();
}

template<typename T>
inline T QueueStack<T>::Max() const
{
	return T();
}

template<typename T>
inline T QueueStack<T>::Min() const
{
	return T();
}

template<typename T>
inline T QueueStack<T>::Sum() const
{
	return T();
}

template<typename T>
inline double QueueStack<T>::Average() const
{
	return 0.0;
}

template<typename T>
inline unsigned int QueueStack<T>::Count() const
{
	return 0;
}

template<typename T>
inline unsigned int QueueStack<T>::StackCount() const
{
	return 0;
}
