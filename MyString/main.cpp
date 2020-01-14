#include <assert.h>
#include <iostream>
#include "MyString.h"

int main()
{
	MyString s1("Hello");
	assert(s1.IndexOf("lo") == 3);

	for (unsigned int i = 0; i < s1.GetLength() + 1; i++)
	{
		assert(s1.GetCString()[i] == "Hello"[i]);
	}

	s1.ToUpper();
	for (unsigned int i = 0; i < s1.GetLength() + 1; i++)
	{
		assert(s1.GetCString()[i] == "HELLO"[i]);
	}

	s1.ToLower();
	for (unsigned int i = 0; i < s1.GetLength() + 1; i++)
	{
		assert(s1.GetCString()[i] == "hello"[i]);
	}

	s1.Append(" World!");
	for (unsigned int i = 0; i < s1.GetLength() + 1; i++)
	{
		assert(s1.GetCString()[i] == "hello World!"[i]);
	}
	assert(s1.GetLength() == 12);

	MyString s2("Kim");
	MyString s3(" Taeri");
	MyString s4 = s2 + s3;
	for (unsigned int i = 0; i < s4.GetLength() + 1; i++)
	{
		assert(s4.GetCString()[i] == "Kim Taeri"[i]);
	}

	MyString s5(" taeri");
	assert((s3 == s3) == true);
	assert((s3 == s5) == false);

	s3.Reverse();
	for (unsigned int i = 0; i < s3.GetLength() + 1; i++)
	{
		assert(s3.GetCString()[i] == "ireaT "[i]);
	}
	s3.Reverse();

	s3.RemoveAt(1);
	for (unsigned int i = 0; i < s3.GetLength() + 1; i++)
	{
		assert(s3.GetCString()[i] == " aeri"[i]);
	}

	char* p = nullptr;
	MyString s6(p);

	MyString s7(s4);
	assert((s7 == s4) == true);

	MyString s8("ABCDEFG");
	MyString s9("1234567");
	s8.Interleave(s9.GetCString());
	for (unsigned int i = 0; i < s8.GetLength() + 1; i++)
	{
		assert(s8.GetCString()[i] == "A1B2C3D4E5F6G7"[i]);
	}
	assert(s8.GetLength() == 14);

	MyString s10("to be or not to be");
	assert(s10.IndexOf("to") == 0);
	assert(s10.LastIndexOf("to") == 13);
	assert(s10.IndexOf("be") == 3);
	assert(s10.LastIndexOf("be") == 16);
	assert(s10.IndexOf("o") == 1);
	assert(s10.LastIndexOf("o") == 14);

	MyString s11("Taeri");
	s11.PadLeft(10);
	for (unsigned int i = 0; i < s11.GetLength() + 1; i++)
	{
		assert(s11.GetCString()[i] == "     Taeri"[i]);
	}

	MyString s12("Taeri");
	s12.PadLeft(10, '*');
	for (unsigned int i = 0; i < s12.GetLength() + 1; i++)
	{
		assert(s12.GetCString()[i] == "*****Taeri"[i]);
	}

	MyString s13("Taeri");
	s13.PadRight(10);
	for (unsigned int i = 0; i < s13.GetLength() + 1; i++)
	{
		assert(s13.GetCString()[i] == "Taeri     "[i]);
	}

	MyString s14("Taeri");
	s14.PadRight(10, '*');
	for (unsigned int i = 0; i < s14.GetLength() + 1; i++)
	{
		assert(s14.GetCString()[i] == "Taeri*****"[i]);
	}

	std::cout << s14 << std::endl;
}