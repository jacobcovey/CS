#include <iostream>
#include <string>
#include <sstream>
#include <locale>
#include <exception>
#include <assert.h>
#include <stdexcept>
#include "Stack.h"


using namespace std;

bool Stack::push(int id){
	if (stackSize >= SIZELIMIT){
		cout << "ERROR: Stack is already full. Car was not added to stack. Car was not removed from station" << endl;
		return false;
	}
	else {
		ll.insertTail(id);
		stackSize++;
		if (testing)
			cout << "Car added to stack. ID: " << top() << endl;
		return true;
		}
}
bool Stack::empty(){
	if (ll.size()== 0)
		return true;
	return false;
}
int Stack::pop(){
	if (stackSize <= 0){
		if (testing)
			cout << "ERROR: Stack is already empty";
		return -1;
	}
	int topValue = top();
	ll.remove(topValue);
	stackSize--;
	if (testing)
		cout << "Car removed from stack. ID: " << topValue << endl;
	return topValue;
}
int Stack::top(){
	if (stackSize == 0)
		return -1;
	return ll.at(stackSize - 1);
}
int Stack::size(){
	return stackSize;
}
