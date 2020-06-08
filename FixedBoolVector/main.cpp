#include <assert.h>
#include <iostream>

#include "FixedBoolVector.h"

int main()
{
    FixedVector<bool, 10> v;

	assert(v.GetCapacity() == 10);

	v.Add(true);
	v.Add(true);
	v.Add(true);
	v.Add(true);
	v.Add(false);
	v.Add(false);
	v.Add(true);

	assert(v.GetSize() == 7);
	assert(v.Get(0));
	assert(v.Get(1));
	assert(v.Get(2));
	assert(v.Get(3));
	assert(!v.Get(4));
	assert(!v.Get(5));
	assert(v.Get(6));

	v.Remove(false);

	assert(v.GetSize() == 6);
	assert(!v.Get(4));
	assert(v.Get(5));

	v.Remove(false);

	assert(v.GetSize() == 5);

	for (size_t i = 0; i < v.GetSize(); i++)
	{
		assert(v[i]);
	}

	v.Remove(true);

	assert(v.GetSize() == 4);

	for (size_t i = 0; i < v.GetSize(); i++)
	{
		assert(v[i]);
	}

	std::cout << "Done" << std::endl;
}