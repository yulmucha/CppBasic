#include <assert.h>
#include "MyString.h"
#include <iostream>
int main()
{
	//MyString s("Hello");
	//assert(s.IndexOf("lo") == 3);
	//const char* cstring = s.GetCString();
	//assert(*cstring == 'H');
	//assert(*(cstring + 1) == 'e');
	//assert(cstring[2] == 'l');
	//assert(cstring[3] == 'l');
	//assert(cstring[4] == 'o');
	//s.ToUpper();
	//std::cout << s.GetCString() << std::endl;
	//s.ToLower();
	//std::cout << s.GetCString() << std::endl;
	//s.Append(" World!");
	//std::cout << s.GetCString() << std::endl;
	//std::cout << s.GetLength() << std::endl;
	MyString s1("Hello");
	MyString s2(" World!");
	MyString s3 = s1 + s2;
	std::cout << s3.GetCString() << std::endl;
	MyString s4(" World!!");
	assert((s2 == s2) == true);
	assert((s2 == s4) == false);
	s1.Reverse();
	for (unsigned int i = 0; i < s1.GetLength() + 1; i++)
	{
		assert(s1.GetCString()[i] == "olleH"[i]);
	}
	s1.Reverse();
	s1.RemoveAt(1);
	for (unsigned int i = 0; i < s1.GetLength() + 1; i++)
	{
		assert(s1.GetCString()[i] == "Hllo"[i]);
	}
	char* p = nullptr;
	MyString ss(p);
}