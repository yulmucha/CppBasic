#include "MyString.h"

MyString::MyString(const char* s)
	: mLength(0)
	, mCString(nullptr)
{
	if (s == nullptr)
	{
		return;
	}

	const char* p = s;
	unsigned int length = 0;
	while (*p != '\0')
	{
		length += 1;
		p += 1;
	}

	mCString = new char[length + 1];
	mLength = length;
	for (unsigned int i = 0; i < mLength + 1; i++)
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
	if (s == nullptr)
	{
		return;
	}

	const char* p = s;
	unsigned int otherLength = 0;
	while (*p != '\0')
	{
		otherLength += 1;
		p += 1;
	}

	unsigned int newLength = mLength + otherLength;
	char* newCString = new char[newLength + 1];
	for (unsigned int i = 0; i < mLength; i++)
	{
		newCString[i] = mCString[i];
	}
	for (unsigned int i = 0; i < otherLength; i++)
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
	if (other.mLength == 0)
	{
		return MyString(mCString);
	}

	unsigned int newLength = mLength + other.mLength;
	char* newCString = new char[newLength + 1];
	for (unsigned int i = 0; i < mLength; i++)
	{
		newCString[i] = mCString[i];
	}
	for (unsigned int i = 0; i < other.mLength; i++)
	{
		newCString[mLength + i] = other.mCString[i];
	}
	newCString[newLength] = '\0';

	return MyString(newCString);
}

int MyString::IndexOf(const char* s)
{
	if (s == nullptr)
	{
		return -1;
	}

	const char* p = s;
	unsigned int targetLength = 0;
	while (*p != '\0')
	{
		targetLength += 1;
		p += 1;
	}

	for (unsigned int i = 0; i < mLength - targetLength + 1; i++)
	{
		bool isEqual = false;
		unsigned int k = 0;
		for (unsigned int j = i; j < i + targetLength; j++)
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

bool MyString::RemoveAt(unsigned int index)
{
	if (index >= mLength)
	{
		return false;
	}

	char* p = new char[mLength];
	p[mLength - 1] = '\0';
	unsigned int j = 0;
	for (unsigned int i = 0; i < index; i++)
	{
		p[j] = mCString[i];
		j++;
	}
	for (unsigned int i = index + 1; i < mLength; i++)
	{
		p[j] = mCString[i];
		j++;
	}
	delete[] mCString;
	mCString = p;
	mLength--;
	return true;
}

void MyString::ToLower()
{
	for (unsigned int i = 0; i < mLength; i++)
	{
		if (mCString[i] >= 65 && mCString[i] <= 90)
		{
			mCString[i] += 32;
		}
	}
}

void MyString::ToUpper()
{
	for (unsigned int i = 0; i < mLength; i++)
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
	for (unsigned int i = 0; i < mLength / 2; i++)
	{
		temp = mCString[i];
		mCString[i] = mCString[mLength - 1 - i];
		mCString[mLength - 1 - i] = temp;
	}
}

bool MyString::operator==(const MyString& rhs) const
{
	unsigned int length = mLength > rhs.mLength ? mLength : rhs.mLength;

	for (unsigned int i = 0; i < length + 1; i++)
	{
		if (mCString[i] != rhs.mCString[i])
		{
			return false;
		}
	}
	return true;
}
