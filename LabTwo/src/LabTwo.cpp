//============================================================================
// Name        : LabTwo.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "LinkedListInterface.h"
#include "LinkedList.h"

using namespace std;

int main() {
	LinkedList<int> list;
	LinkedList<string> slist;


	list.insertHead(0);
	list.insertHead(16);
	list.insertHead(4);
	list.insertHead(0);
	list.insertHead(15);

	cout << "Size: " << list.size() << endl;
//	list.insertTail(4);
//	list.insertTail(5);
//	list.insertAfter(6,2);
//	list.insertAfter(7,1);
//	cout << "Value: " <<list.at(8) << endl;
//	list.clear();

//	slist.insertHead("Jacob");
//	slist.insertHead("Paul");
//	slist.insertHead("Covey");
//	slist.insertTail("Elisa");
//	slist.insertTail("Anne");
//	slist.insertAfter("Woolley","Anne");
//	slist.insertAfter("Jake","Jacob");
//	cout << "Value: " <<slist.at(2) << endl;
//	slist.clear();

	return 0;
}
