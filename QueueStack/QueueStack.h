#pragma once

#include <limits>
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
	T mSum;
	T mMax;
	T mMin;
	std::queue<std::stack<T>> mNumbers;
};

template<typename T>
inline QueueStack<T>::QueueStack(const unsigned int maxStackSize)
	: mMaxStackSize(maxStackSize)
	, mCount(0)
	, mSum(0)
	, mMax(std::numeric_limits<T>::lowest())
	, mMin(std::numeric_limits<T>::max())
{
}

template<typename T>
inline void QueueStack<T>::Enqueue(const T number)
{
	if (mNumbers.empty() || mNumbers.back().size() >= mMaxStackSize)
	{
		std::stack<T> s;
		s.push(number);
		
		mNumbers.push(s);
	}
	else
	{
		mNumbers.back().push(number);
	}
	
	if (mMax < number)
	{
		mMax = number;
	}
	if (mMin > number)
	{
		mMin = number;
	}
	
	mCount++;
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

	if (mNumbers.empty())
	{
		mMax = std::numeric_limits<T>::lowest();
		mMin = std::numeric_limits<T>::max();
	}
	else
	{
		if (dequeuedNumber >= mMax)
		{
			mMax = std::numeric_limits<T>::lowest();
			std::queue<std::stack<T>> temp(mNumbers);
			while (!temp.empty())
			{
				while (!temp.front().empty())
				{
					if (mMax < temp.front().top())
					{
						mMax = temp.front().top();
					}
					temp.front().pop();
				}
				temp.pop();
			}
		}

		if (dequeuedNumber <= mMin)
		{
			mMin = std::numeric_limits<T>::max();
			std::queue<std::stack<T>> temp(mNumbers);
			while (!temp.empty())
			{
				while (!temp.front().empty())
				{
					if (mMin > temp.front().top())
					{
						mMin = temp.front().top();
					}
					temp.front().pop();
				}
				temp.pop();
			}
		}
	}

	return dequeuedNumber;
}

template<typename T>
inline T QueueStack<T>::Max() const
{
	return mMax;
}

template<typename T>
inline T QueueStack<T>::Min() const
{
	return mMin;
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
