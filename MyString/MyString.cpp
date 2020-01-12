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
	/*char* p = new char[mLength + 1];
	for (size_t i = 0; i < mLength + 1; i++)
	{
		p[i] = mCString[i];
	}
	return p;*/
	return mCString;
}

void MyString::Append(const char* s)
{
	const char* p = s;
	unsigned int otherLength = 0;
	while (*p != '\0')
	{
		otherLength += 1;
		p += 1;
	}

	unsigned int newLength = mLength + otherLength;
	char* newCString = new char[newLength + 1];
	for (size_t i = 0; i < mLength; i++)
	{
		newCString[i] = mCString[i];
	}
	for (size_t i = 0; i < otherLength; i++)
	{
		newCString[mLength + i] = s[i];
	}
	newCString[newLength] = '\0';

	delete[] mCString;
	mCString = newCString;
	mLength = newLength;
}

MyString MyString::operator+(const MyString& other) const
{
	unsigned int newLength = mLength + other.mLength;
	char* newCString = new char[newLength + 1];
	for (size_t i = 0; i < mLength; i++)
	{
		newCString[i] = mCString[i];
	}
	for (size_t i = 0; i < other.mLength; i++)
	{
		newCString[mLength + i] = other.mCString[i];
	}
	newCString[newLength] = '\0';

	return MyString(newCString);
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

void MyString::Reverse()
{
	char temp;
	for (size_t i = 0; i < mLength / 2; i++)
	{
		temp = mCString[i];
		mCString[i] = mCString[mLength - 1 - i];
		mCString[mLength - 1 - i] = temp;
	}
}

bool MyString::operator==(const MyString& rhs) const
{
	for (size_t i = 0; i < mLength + 1; i++)
	{
		if (mCString[i] != rhs.mCString[i])
		{
			return false;
		}
	}
	return true;
}
