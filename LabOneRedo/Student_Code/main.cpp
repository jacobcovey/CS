/*
 * main.cpp
 *
 *  Created on: May 5, 2016
 *      Author: jcovey
 */

#include <iostream>
#include "FighterInterface.h"
#include "ArenaInterface.h"
#include "Factory.h"
#include "Arena.h"
#include "Fighter.h"
#include "Archer.h"
#include "Robot.h"
#include "Cleric.h"

using namespace std;

int main() {
	Arena arena1;

	cout <<arena1.addFighter("Fumblemore C 100 10 10 100") << endl;
	cout <<arena1.addFighter("Israphel A 90 12 16 4") << endl;
//
//	archer1.takeDamage(10);
//	archer1.regenerate();
//
	cout << arena1.getFighter("Fumblemore") << endl;

	cout << arena1.getSize() << endl;

	cout << arena1.removeFighter("Fumblemore") << endl;

	cout << arena1.getSize() << endl;

	arena1.Fighters[1]->takeDamage(10);
	arena1.Fighters[1]->regenerate();
//	cout << arena1;
	return 0;
}


