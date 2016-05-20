#include <iostream>
#include <string>
#include <sstream>
#include <locale>
#include <exception>
#include <assert.h>
#include <stdexcept>
#include "deque.h"


using namespace std;

bool Deque::pushLeft(int id){
	if (dequeSize >= SIZELIMITD){
		cout << "ERROR: deque is already full. Car was not added to Deque. Car was not removed from station" << endl;
		return false;
	}
	else {
		ll.insertHead(id);
		dequeSize++;
		if (testing)
			cout << "Car added to deque." << endl;
		return true;
		}
}
bool Deque::pushRight(int id){
	if (dequeSize >= SIZELIMITD){
		cout << "ERROR: deque is already full. Car was not added to deque. Car was not removed from station" << endl;
		return false;
	}
	else {
		ll.insertTail(id);
		dequeSize++;
		if (testing)
			cout << "Car added to deque." << endl;
		return true;
		}
}
bool Deque::empty(){
	if (ll.size()== 0)
		return true;
	return false;
}
int Deque::popLeft(){
	if (dequeSize <= 0){
		if (testing)
			cout << "ERROR: deque is already empty";
		return -1;
	}
	int FrontValue = left();
	ll.remove(FrontValue);
	dequeSize--;
	if (testing)
		cout << "Car removed from deque. ID: " << FrontValue << endl;
	return FrontValue;
}
int Deque::popRight(){
	if (dequeSize <= 0){
		if (testing)
			cout << "ERROR: Deque is already empty";
		return -1;
	}
	int RightValue = Right();
	ll.remove(RightValue);
	dequeSize--;
	if (testing)
		cout << "Car removed from deque. ID: " << RightValue << endl;
	return RightValue;
}

int Deque::left(){
	if (dequeSize == 0)
		return -1;
	return ll.at(0);
}
int Deque::Right(){
	if (dequeSize == 0)
		return -1;
	return ll.at(dequeSize - 1);
}

int Deque::size(){
	return dequeSize;
}
