#include "MyString.h"

MyString::MyString(const char* s)
	: mLength(0)
	, mCString(nullptr)
{
	const char* p = s;
	unsigned int length = 0;
	while (*p != '\0')
	{
		length += 1;
		p += 1;
	}

	mCString = new char[length + 1];
	mLength = length;
	for (size_t i = 0; i < mLength + 1; i++)
	{
		mCString[i] = s[i];
	}
}

MyString::~MyString()
{
	mLength = 0;
	delete[] mCString;
}

unsigned int MyString::GetLength() const
{
	return mLength;
}

const char* MyString::GetCString()
{
	char* p = new char[mLength + 1];
	for (size_t i = 0; i < mLength + 1; i++)
	{
		p[i] = mCString[i];
	}
	return p;
}

int MyString::IndexOf(const char* s)
{
	const char* p = s;
	unsigned int targetLength = 0;
	while (*p != '\0')
	{
		targetLength += 1;
		p += 1;
	}

	for (size_t i = 0; i < mLength - targetLength + 1; i++)
	{
		bool isEqual = false;
		size_t k = 0;
		for (size_t j = i; j < i + targetLength; j++)
		{
			if (mCString[j] != s[k])
			{
				isEqual = false;
				break;
			}
			isEqual = true;
			k++;
		}
		if (isEqual)
		{
			return i;
		}
	}
	return -1;
}

void MyString::ToLower()
{
	for (size_t i = 0; i < mLength; i++)
	{
		if (mCString[i] >= 65 && mCString[i] <= 90)
		{
			mCString[i] += 32;
		}
	}
}

void MyString::ToUpper()
{
	for (size_t i = 0; i < mLength; i++)
	{
		if (mCString[i] >= 97 && mCString[i] <= 122)
		{
			mCString[i] -= 32;
		}
	}
}
