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

MyString::MyString(const MyString& other)
	: mLength(other.mLength)
	, mCString(nullptr)
{
	mCString = new char[mLength + 1];
	for (unsigned int i = 0; i < mLength + 1; i++)
	{
		mCString[i] = other.mCString[i];
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

int MyString::LastIndexOf(const char* s)
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

	for (unsigned int i = mLength - 1; i >= targetLength - 1; i--)
	{
		bool isEqual = false;
		unsigned int k = targetLength - 1;
		for (unsigned int j = i; j > i - targetLength; j--)
		{
			if (mCString[j] != s[k])
			{
				isEqual = false;
				break;
			}
			isEqual = true;
			k--;
		}
		if (isEqual)
		{
			return i - targetLength + 1;
		}
	}
	return -1;
}

void MyString::Interleave(const char* s)
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

	unsigned int totalLegnth = mLength + otherLength;
	char* interleavedCString = new char[totalLegnth + 1];
	for (unsigned int i = 0; i < mLength + 1; i++)
	{
		interleavedCString[i * 2] = mCString[i];
	}
	for (unsigned int i = 0; i < otherLength; i++)
	{
		interleavedCString[i * 2 + 1] = s[i];
	}

	delete[] mCString;
	mCString = interleavedCString;
	mLength = totalLegnth;
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

void MyString::PadLeft(unsigned int totalLength)
{
	if (totalLength < mLength)
	{
		return;
	}

	char* p = new char[totalLength + 1];
	unsigned int spaceLength = totalLength - mLength;
	for (unsigned int i = 0; i < spaceLength; i++)
	{
		p[i] = ' ';
	}
	for (unsigned int i = spaceLength; i < totalLength + 1; i++)
	{
		p[i] = mCString[i - spaceLength];
	}

	delete[] mCString;
	mCString = p;
	mLength = totalLength;
}

void MyString::PadLeft(unsigned int totalLength, const char c)
{
	if (totalLength < mLength)
	{
		return;
	}

	char* p = new char[totalLength + 1];
	unsigned int spaceLength = totalLength - mLength;
	for (unsigned int i = 0; i < spaceLength; i++)
	{
		p[i] = c;
	}
	for (unsigned int i = spaceLength; i < totalLength + 1; i++)
	{
		p[i] = mCString[i - spaceLength];
	}

	delete[] mCString;
	mCString = p;
	mLength = totalLength;
}

void MyString::PadRight(unsigned int totalLength)
{
	if (totalLength < mLength)
	{
		return;
	}

	char* p = new char[totalLength + 1];
	for (unsigned int i = 0; i < mLength; i++)
	{
		p[i] = mCString[i];
	}
	for (unsigned int i = mLength; i < totalLength; i++)
	{
		p[i] = ' ';
	}
	p[totalLength] = '\0';

	delete[] mCString;
	mCString = p;
	mLength = totalLength;
}

void MyString::PadRight(unsigned int totalLength, const char c)
{
	if (totalLength < mLength)
	{
		return;
	}

	char* p = new char[totalLength + 1];
	for (unsigned int i = 0; i < mLength; i++)
	{
		p[i] = mCString[i];
	}
	for (unsigned int i = mLength; i < totalLength; i++)
	{
		p[i] = c;
	}
	p[totalLength] = '\0';

	delete[] mCString;
	mCString = p;
	mLength = totalLength;
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

std::ostream& operator<<(std::ostream& os, MyString& s)
{
	os << s.GetCString();
	return os;
}