#pragma once
#include "LinkedList.h"

const int SIZELIMITD = 5;

class Deque
{
public:
	Deque () : dequeSize(0), testing(true) {}
	 ~Deque() {}

	 bool pushLeft(int id);
	 bool pushRight(int id);
	 bool empty();
	 int popLeft();
	 int popRight();
	 int right();
	 int left();
	 int size();

protected:
	 int dequeSize;
	 bool testing;
	 LinkedList<int> ll;
};
