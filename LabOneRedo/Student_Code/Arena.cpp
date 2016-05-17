/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arena.cpp
 * Author: jcovey
 * 
 * Created on April 30, 2016, 2:05 PM
 */
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>
#include "Arena.h"

using namespace std;

//Arena::Arena(){}
/*
		 *	addFighter(string)
		 *
		 *	Adds a new fighter to the collection of fighters in the arena. Do not allow 
		 *	duplicate names.  Reject any string that does not adhere to the format 
		 *	outlined in the lab specs.
		 *
		 *	Return true if a new fighter was added; false otherwise.
		 */
		bool Arena::addFighter(string info) {
                    bool updated = false;
                    char type;
                    string name = "";
                    int hp = 0;
                    int strength = 0;
                    int speed = 0;
                    int magic = 0;
                    int garbage = 0;

                    istringstream iss(info);
                    iss >> name >> type >> hp >> strength >> speed >> magic;
                    if (iss.fail()) {
                        iss.clear();
                        string sentinel;
                        getline(iss, sentinel);
                        cout << "ERROR: Bad input" << endl;
                    }
                    assert(name != "" && type != NULL && hp != 0 && strength != 0 && speed != 0 && magic != 0);
                    iss >> garbage;
                    assert(iss.fail());
                        if (hp > 0 && strength > 0 && speed > 0 && magic > 0){
                            if (!CheckIfNameExist(Fighters, name)) {
                                if (type == 'A') {
                                    Fighters.push_back(new Archer(name, hp, strength, speed, magic));
                                    updated = true;
                                }
                                else if (type == 'C') {
                                    Fighters.push_back(new Cleric(name, hp, strength, speed, magic));
                                    updated = true;
                                }
                                else if (type == 'R') {
                                    Fighters.push_back(new Robot(name, hp, strength, speed, magic));
                                    updated = true;
                                }
                                else
                                    cout << "ERROR: Did not recognize type." << endl;
                            }
                            else
                                cout << "ERROR: Name already exists." << endl;
                        }
                    else 
                        cout << "ERROR: All stats must be positive numbers." << endl;

                    return updated;
                    }
                
		bool Arena::removeFighter(string name) {
                 
                    int positionOfMatch = 0;
                    if (CheckIfNameExist(Fighters, name)){
                        positionOfMatch = FindPositionOfMatch(Fighters, name);
                            for (int x = positionOfMatch + 1; x < Fighters.size(); x++) {
                                Fighters[x - 1] = Fighters[x];
                            }
                        Fighters.pop_back();
                        cout << "Fighter " << name << " was removed" << endl;
                        return true;
                    }
                    else 
                        //cout << "ERROR: Name does not exist" << endl;
                        return false;
                    
                }

		FighterInterface* Arena::getFighter(string name) {
                    if (!CheckIfNameExist(Fighters, name)) {
                        cout << "ERROR: Fighter not found." << endl;
                        return NULL;   
                    }
                    else {
                        return Fighters[FindPositionOfMatch(Fighters, name)];
                    }
                }
		
		int Arena::getSize() {
                    return Fighters.size();
                }
 
                bool Arena::CheckIfNameExist(vector<Fighter*> Fighters, string name) {
                   
                    bool CheckIfNameExist = false;

                    for (int x = 0; x < Fighters.size(); x++) {

                            if (Fighters[x]->getName() == name)
                                    CheckIfNameExist = true;

                    }
                    return CheckIfNameExist;
                }
                
                int Arena::FindPositionOfMatch(vector<Fighter*> Fighters, string name){
                  
                    int position;
	
                    for (int x = 0; x < Fighters.size(); x++) {
                            if (Fighters[x]->getName() == name)
                                    position = x;
                    }

                    return position;
                }
                
			   ostream& operator<<(ostream& os, const Fighter& fighter){
							os << "Name:" << "Current HP: " << '\n';
							os << "Current Strength: " <<  '\n' << "Current Speed: " << '\n';
							os << "Current Magic: " << '\n';
						return os;
					}
