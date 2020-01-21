#include <cassert>
#include <stack>
#include <queue>

#include "QueueStack.h"

int main()
{
	QueueStack<int> qs(3);
	qs.Enqueue(5);
	assert(qs.Peek() == 5);
	assert(qs.Sum() == 5);
	qs.Enqueue(4);
	assert(qs.Peek() == 4);
	assert(qs.Sum() == 9);
	qs.Enqueue(3);
	assert(qs.Peek() == 3);
	assert(qs.Sum() == 12);
	qs.Enqueue(2);
	assert(qs.Peek() == 3);
	assert(qs.Sum() == 14);
	/*
		top	  3
			  4	
			  5		  2
			front	back
	*/

	assert(qs.Dequeue() == 3);
	assert(qs.Sum() == 11);
	qs.Enqueue(1);
	assert(qs.Sum() == 12);
	/*	
		top	 4		 1
			 5		 2
			front	back
	*/

	assert(qs.Dequeue() == 4);
	assert(qs.Sum() == 8);
	assert(qs.Dequeue() == 5);
	assert(qs.Sum() == 3);
	assert(qs.Dequeue() == 1);
	assert(qs.Sum() == 2);
}