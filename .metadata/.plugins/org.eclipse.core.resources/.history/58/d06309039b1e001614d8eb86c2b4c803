//============================================================================
// Name        : Lab_4.cpp
// Author      : Jacob Covey
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "StationInterface.h"
#include "Factory.h"
#include "Station.h"
#include "Stack.h"
using namespace std;

int main() {
	bool testing = true;
	bool quite = false;
	int response = 0;
	string structureType = "";
	Station st;

	while (!quite){
		cout << "1. Add a car to the station\n2. Remove a car from the station\n";
		cout << "3. Add a car from the station to a storage facility\n4. Remove car from a storage facility and add it to the station\n";
		cout << "5. Display the cars currently accessible in the station and storage facilities\n6. Quit" << endl;
		cin >> response;
		 if (cin.fail()) {
			cin.clear();
			string sentinel;
			getline(cin, sentinel);
		 }
		switch(response){
			case 1 : {
					int carToAdd = -1;
					cin >> carToAdd;
					if (cin.fail()) {
						cin.clear();
						string sentinel;
						getline(cin, sentinel);
						cout << "ERROR: Invalid input. Car could not be added to station." << endl;
						 }
					else{
						bool sucess = st.addToStation(carToAdd);
						if (!sucess)
							cout << "ERROR: Car was not added to station." << endl;
						}
					}
					break;
			case 2 : st.removeFromStation();
					break;
			case 3 : {
				 	 cin >> structureType;
				 	 if (structureType == "stack")
				 			st.addToStack();
				 		 else if (structureType == "queue") {
				 			 st.addToQueue();
				 		 }
				 		else if (structureType == "deque"){

				 		}
				 		else
				 			cout << "ERROR: Inputed structure type was not recognized. Don't use capital letters." << endl;
				 	 }
					break;
			case 4 :{
				cin >> structureType;
				 if (structureType == "stack")
						st.removeFromStack();
					 else if (structureType == "queue") {
						 st.removeFromQueue();
					 }
					else if (structureType == "deque"){

					}
					else
						cout << "ERROR: Inputed structure type was not recognized. Don't use capital letters." << endl;
			}
					break;
			case 5 :
					cout << "Stack Top: " << st.showTopOfStack() << " Stack Size: "<< st.showSizeOfStack() <<endl;
					cout << "Queue Top: " << st.showTopOfQueue() << " Queue Size: "<< st.showSizeOfQueue() <<endl;
					break;
			case 6 : quite = true;
					break;
			default: cout << "ERROR: Invalid response" << endl;
					break;
			}
	}

	return 0;
}
