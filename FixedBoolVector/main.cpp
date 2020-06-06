#include <assert.h>
#include <iostream>

#include "FixedBoolVector.h"

int main()
{
    FixedVector<bool, 34> fbv;
    for (unsigned int i = 0; i < 32; i++)
    {
        fbv.Add(true);
    }
    fbv.Add(false);
    fbv.Add(true);

    // for (unsigned int i = 0; i < fbv.GetSize(); i++)
    // {
    //     std::cout << "#" << i << ": " << fbv.Get(i) << std::endl;
    // }
    assert(fbv.Get(31) == true);
    assert(fbv.Get(32) == false);
    assert(fbv.Get(33) == true);
}