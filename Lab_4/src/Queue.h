#pragma once
#include "LinkedList.h"

const int SIZELIMITQ = 5;

class Queue
{
public:
	Queue () : queueSize(0), testing(true) {}
	 ~Queue() {}

	 bool push(int id);
	 bool empty();
	 int pop();
	 int front();
	 int size();
	 bool exist(int id);

protected:
	 int queueSize;
	 bool testing;
	 LinkedList<int> ll;
};
