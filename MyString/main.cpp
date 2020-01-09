#include <assert.h>
#include "MyString.h"
#include <iostream>
int main()
{
	MyString s("Hello");
	
	assert(s.IndexOf("lo") == 3);
	const char* cstring = s.GetCString();
	assert(*cstring == 'H');
	assert(*(cstring + 1) == 'e');
	assert(cstring[2] == 'l');
	assert(cstring[3] == 'l');
	assert(cstring[4] == 'o');
	s.ToUpper();
	std::cout << s.GetCString() << std::endl;
	s.ToLower();
	std::cout << s.GetCString() << std::endl;
}