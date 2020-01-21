#include <cassert>
#include <limits>
#include <queue>
#include <stack>

#include "QueueStack.h"

int main()
{
	QueueStack<int> qs(3);
	qs.Enqueue(4);
	assert(qs.Peek() == 4);
	assert(qs.Max() == 4);
	assert(qs.Min() == 4);
	qs.Enqueue(6);
	assert(qs.Peek() == 6);
	assert(qs.Max() == 6);
	assert(qs.Min() == 4);
	qs.Enqueue(3);
	assert(qs.Peek() == 3);
	assert(qs.Max() == 6);
	assert(qs.Min() == 3);
	qs.Enqueue(5);
	assert(qs.Peek() == 3);
	assert(qs.Max() == 6);
	assert(qs.Min() == 3);
	qs.Enqueue(7);
	assert(qs.Peek() == 3);
	assert(qs.Max() == 7);
	assert(qs.Min() == 3);
	/*
		top	  3
			  6		  7
			  4		  5
			front	back
	*/

	assert(qs.Dequeue() == 3);
	assert(qs.Max() == 7);
	assert(qs.Min() == 4);
	qs.Enqueue(1);
	assert(qs.Max() == 7);
	assert(qs.Min() == 1);
	/*
		top			 1
			 6		 7
			 4		 5
			front	back
	*/
	assert(qs.Dequeue() == 6);
	assert(qs.Max() == 7);
	assert(qs.Min() == 1);
	assert(qs.Dequeue() == 4);
	assert(qs.Max() == 7);
	assert(qs.Min() == 1);
	assert(qs.Dequeue() == 1);
	assert(qs.Max() == 7);
	assert(qs.Min() == 5);
	assert(qs.Dequeue() == 7);
	assert(qs.Max() == 5);
	assert(qs.Min() == 5);
}