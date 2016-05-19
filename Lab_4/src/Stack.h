#pragma once
#include "LinkedList.h"

const int SIZELIMIT = 5;

class Stack
{
public:
	Stack () : stackSize(0), testing(true) {}
	 ~Stack() {}

	 bool push(int id);
	 bool empty();
	 int pop();
	 int top();
	 int size();

protected:
	 int stackSize;
	 bool testing;
	 LinkedList<int> ll;
};
