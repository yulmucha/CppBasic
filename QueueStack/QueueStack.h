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
	const unsigned int mMaxStackSize;
	unsigned int mCount;
	//T mMax;
	//T mMin;
	T mSum;
	std::queue<std::stack<T>> mNumbers;
};

template<typename T>
inline QueueStack<T>::QueueStack(const unsigned int maxStackSize)
	: mMaxStackSize(maxStackSize)
	//, mMax(0)
	//, mMin(0)
	, mCount(0)
	, mSum(0)
{
}

template<typename T>
inline void QueueStack<T>::Enqueue(const T number)
{
	if (mNumbers.empty())
	{
		std::stack<T> s;
		s.push(number);
		mNumbers.push(s);
		mCount++;
		//mMax = number;
		//mMin = number;
	}
	else
	{
		if (mNumbers.back().size() < mMaxStackSize)
		{
			mNumbers.back().push(number);
			mCount++;
		}
		else
		{
			std::stack<T> s;
			s.push(number);
			mNumbers.push(s);
			mCount++;
		}
		
		//if (mMax < number)
		//{
		//	mMax = number;
		//}
		//if (mMin > number)
		//{
		//	mMin = number;
		//}
	}
	mSum += number;
}

template<typename T>
inline T QueueStack<T>::Peek() const
{
	return mNumbers.front().top();
}

template<typename T>
inline T QueueStack<T>::Dequeue()
{
	T dequeuedNumber = mNumbers.front().top();
	mNumbers.front().pop();
	mCount--;
	mSum -= dequeuedNumber;
	if (mNumbers.front().empty())
	{
		mNumbers.pop();
	}
	return dequeuedNumber;
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
	return mSum;
}

template<typename T>
inline double QueueStack<T>::Average() const
{
	return static_cast<double>(mSum) / static_cast<double>(mCount);
}

template<typename T>
inline unsigned int QueueStack<T>::Count() const
{
	return mCount;
}

template<typename T>
inline unsigned int QueueStack<T>::StackCount() const
{
	return mNumbers.size();
}
