#pragma once
#include <iostream>

class MyString
{
public:
	MyString(const char* s);
	MyString(const MyString& other);
	~MyString();
	unsigned int GetLength() const;
	const char* GetCString();
	void Append(const char* s);
	MyString operator+(const MyString& other) const;
	int IndexOf(const char* s);
	int LastIndexOf(const char* s);
	void Interleave(const char* s);
	bool RemoveAt(unsigned int i);
	void PadLeft(unsigned int totalLength);
	void PadLeft(unsigned int totalLength, const char c);
	void PadRight(unsigned int totalLength);
	void PadRight(unsigned int totalLength, const char c);
	void Reverse();
	bool operator==(const MyString& rhs) const;
	void ToLower();
	void ToUpper();
	friend std::ostream& operator<<(std::ostream& os, MyString& s);
private:
	unsigned int mLength;
	char* mCString;
};