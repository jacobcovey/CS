//============================================================================
// Name        : Lab3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <locale>
#include "ExpressionManagerInterface.h"
#include "ExpresionManger.h"

using namespace std;

bool isOpen(char bracket) {

	for (int x = 0; x < 3; x++){
		if (bracket == OPEN[x])
			return true;
	}
	return false;
}
bool isClose(char bracket) {

	for (int x = 0; x < 3; x++){
		if (bracket == CLOSE[x])
			return true;
	}
	return false;
}
string determineCharType (char input){
	string charType = "";
	if (isdigit(input))
		charType = "operand";
	else if (isOpen(input) || isClose(input))
		charType = "bracket";
	else {
		for (int x = 0; x < OPERATOR.length(); x++){
			if (input == OPERATOR[x])
				charType = "operator";
		}
	if (charType == "")
		charType = "other";
	}
	return charType;
}

int main() {

	const string OPEN = "([{";
	const string CLOSE = ")]}";
	const string OPERATOR ="+-*/%";
	const string IMMEDIATE =")]}";
	const string HIGH ="*/%";
	const string LOW ="+-";
	const string WILD ="([{";

	ExpressionManager em;

//	cout << determineCharType('3') << endl;
//	cout << determineCharType('399') << endl;
//	cout << determineCharType('[')<< endl;
//	cout << determineCharType('*')<< endl;
//	cout << determineCharType('+')<< endl;
//	cout << determineCharType('$')<< endl;
//
//	cout << em.postfixEvaluate("4 5 + 6 0 * /") << endl;
//	cout << em.postfixEvaluate("4 7 *") << endl;
//	cout << em.postfixEvaluate("3 4 7 * 2 / +") << endl;
//	cout << em.postfixEvaluate("40 2 4 + 1 1 + - * 4 2 / 1 / - 7 %") << endl;
//	cout << em.postfixEvaluate("+ 3 4 +") << endl;
//	cout << em.postfixEvaluate("4 5 2 + * 2 /") << endl;
//	cout << em.infixToPostfix("4 * 7") << endl;
//	cout << em.infixToPostfix("1 + ( 2 * 3 - 1 ) - 2") << endl;
//	cout << em.infixToPostfix("-") << endl;
	cout << em.infixToPostfix("40 * ( 2 + 4 - ( 2 + 2 ) ) - 4 / 5 / 6") << endl;
	cout << em.infixToPostfix("( ( 3 + 4 ) * ( 3 - 2 ) - ( 2 / 2 ) ) + 24 / 3") << endl;
//	cout << em.infixToPostfix("(4 * 7) - 20") << endl;



	return 0;
}
