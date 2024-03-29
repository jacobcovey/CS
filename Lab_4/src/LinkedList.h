#pragma once
#include "LinkedListInterface.h"
#include <string>
#include <iostream>
#include <exception>

using namespace std;

template<typename T>
class LinkedList : public LinkedListInterface<T> {

private:

	struct Node {
		Node(T input) : value(input), next(NULL){}
		Node() : value(0), next(NULL){}
		~Node(){}

		T value;
		Node* next;
	};
		int counter;
		Node* head;
		bool testing;

public:
	LinkedList() : counter(0), head(NULL), testing(false) {}

	~LinkedList(){
		clear();
	}


		/*
			insertHead

			A node with the given value should be inserted at the beginning of the list.

			Do not allow duplicate values in the list.
		 */
		void insertHead(T value) {
			if (testing)
				cout << "entering insterHead()" << endl;
			bool duplicateValue = checkIfValueExists(value);
			if (!duplicateValue){
				Node* temp = head;
							Node* newNode = new Node(value);
				if (head == NULL) {
					head = newNode;
					counter++;
					if (testing)
						cout << "Node added to empty list" << endl;
				}
				else {
					head = newNode;
					newNode->next = temp;
					counter++;
					if (testing)
						cout << "Node added to existing list" << endl;
				}
				if (testing) {
					cout << "Exiting insterHead()\nLocation of Head: " << head << "\nValue of new Node: " << newNode->value << endl;
				}
			}
			else{
				if (testing)
					cout << "Value already in list. No node was added." << endl;
			}
		}

		/*
			insertTail

			A node with the given value should be inserted at the end of the list.

			Do not allow duplicate values in the list.
		 */
		void insertTail(T value){
			if (testing)
				cout << "entering insterTail()" << endl;
			bool duplicateValue = checkIfValueExists(value);
			if (!duplicateValue){
				Node* temp = head;
				Node* newNode = new Node(value);
				if (counter == 0) {//empty list
					head = newNode;
					counter++;
					if (testing)
						cout << "Node added to tail empty list" << endl;
				}
				else if (counter == 1){//list of just 1
					head->next = newNode;
					counter++;
					if (testing)
						cout << "Node added to tail of list of 1" << endl;
				}
				else {//list of 1+
						while (temp->next != NULL){
						temp = temp->next;
						}
					temp->next = newNode;
					counter++;
					if (testing)
						cout << "Node added to tail of list of 1+" << endl;
				}
				if (testing)
					cout << "Exiting insertTail()\n Location of Head: " << head << "\nLocation of new Node: " << newNode << endl;
			}
			else {
				if (testing)
					cout << "Value already in list. No node was added." << endl;
			}

		}
		/*
			insertAfter

			A node with the given value should be inserted immediately after the
			node whose value is equal to insertionNode.

			A node should only be added if the node whose value is equal to
			insertionNode is in the list. Do not allow duplicate values in the list.
		 */
		void insertAfter(T value, T insertionNode) {
			if (testing)
				cout << "Entering insterAfter()" << endl;
		bool duplicateValue = checkIfValueExists(value);
		if (!duplicateValue){
				int position = find(insertionNode);
				if (position >= 0){
					Node* tempPosition = head;
					Node* tempNext = NULL;
					Node* newNode = new Node(value);
	//				if (position == counter){// the insertion node is at the end of the list
	//					if (testing)
	//						cout << "Call the insert tail function and add value." << endl;
	//					insertTail(value);
	//				}
	//				else {// the insertion node is somewhere not at the end of the list
	//					if (testing)
	//						cout << "Add node to somewhere not at the tail of the list" << "\nLocation of new Node: " << newNode <<  endl;
						for (int x = 1; x < position; x++){
							tempPosition = tempPosition->next;
						}
						tempNext = tempPosition->next;
						tempPosition->next = newNode;
						newNode->next = tempNext;
						counter++;
						if (testing)
							cout << "Exiting insertAfter(value, insertionNode)\nLocation of Head: " << head << "\nLocation of newNode: " << newNode << endl;
	//				}
				}
				else{
					if (testing)
						cout << "Insertion value does not exist. Node was not added\nPosition: " << position << endl;
				}
			}
			else {
				if (testing)
					cout << "Value already in list. No node was added." << endl;
			}
		}
		/*
			remove

			The node with the given value should be removed from the list.

			The list may or may not include a node with the given value.
		 */
		void remove(T value) {
		bool duplicateValue = checkIfValueExists(value);
			if (duplicateValue){
				int position = find(value);
				if (position == 1){// Remove the first node in the list
					Node* temp = head;
					head = temp->next;
					if (testing)
						cout << "Fist node in the list was deleted. Location of deleted Node: " << temp << "\nLocaton of new head: " << head << endl;
					delete temp;
				}
				else if (position == counter){//Remove last node of the list
					Node* tempPosition = NULL;
					Node* tempPrevious = head;
					for (int x = 2; x < position; x++){
						tempPrevious = tempPrevious->next;
					}
					tempPosition = tempPrevious->next;
					tempPrevious->next = NULL;
					if (testing)
						cout << "Node at the end of list was deleted. Location of deleted Node: " << tempPosition << endl;
					delete tempPosition;
				}
				else {//Remove node other than the first or last node in the list
					Node* tempPosition = NULL;
					Node* tempPrevious = head;
					for (int x = 2; x < position; x++){
						tempPrevious = tempPrevious->next;
					}
					tempPosition = tempPrevious->next;
					tempPrevious->next = tempPosition->next;
					if (testing)
						cout << "Node in middle of list was deleted. Location of deleted Node: " << tempPosition << endl;
					delete tempPosition;
				}
			counter--;
			}
			else{
				if (testing)
					cout << "There is no node in the list with the given value of " << value << ". NO NODE WAS DELETED." << endl;
			}
		}
		/*
			clear

			Remove all nodes from the list.
		 */
		void clear() {
			int numberDeleted = 0;
//			for (int x = 0; x < counter; x++){
			while (head != NULL){
				Node* temp = head;
				head = temp->next;
				delete temp;
				numberDeleted++;
			}
			counter = 0;
			if (testing)
				cout << "Function clear() was run.\nNumber of nodes deleted: " << numberDeleted << endl;
		}
		/*
			at

			Returns the value of the node at the given index. The list begins at
			index 0.

			If the given index is out of range of the list, throw an out of range exception.
		 */
		T at(int index) {
			if (index >= counter || index < 0){
				throw out_of_range("OUT OF RANGE");
				return head->value;
			}
			else {
			Node* temp = head;
				for (int x = 0; x < index; x++){
					temp = temp->next;
				}
				return temp->value;
			}
		}
		/*
			size

			Returns the number of nodes in the list.
		 */
		int size() {
			if (testing){
				cout << "Counter: " << counter << endl;
				Node* temp = head;
				int count = 0;
				while (temp != NULL){
					cout << "[" << at(count) << "] ";
					count++;
					temp = temp->next;
				}
				cout << endl;
			}
			return counter;
		}
		/*
		 	 find

		 	 Returns the position of the matched node. If no match is found then -1 is returned.
		 */
		int find(T value_in){
			int position = -1;
			int count = 1;
			Node* temp = head;
			while (temp != NULL){
				if (temp->value == value_in){
					position = count;
				}
//
//				if (testing)
//					cout << "Loop: " << count << " Temp Value: " << temp->value << "\nValue_in: "<< value_in <<endl;
//
				temp = temp->next;
				count++;
			}
			if (testing)
				cout << "Exiting find\nPosition: " << position << endl;
			return position;
		}
		/*
		 	 CheckIfValueExists

		 	 Returns a bool value of whether or not a value is aready in a existing node.
		 */
		bool checkIfValueExists(T value_in){
			bool present = false;
			Node* temp = head;
				while (temp != NULL){
					if (temp->value == value_in){
						present = true;
					}
					temp = temp->next;
				}

			return present;
		}
//
//		void printList(){
//			Node* temp = head;
//			while(temp != NULL){
//				cout << "[" << temp->value << "] ";
//				temp = temp->next;
//			}
//			cout << endl;
//		}

};
