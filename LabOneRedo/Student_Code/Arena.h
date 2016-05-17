/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arena.h
 * Author: jcovey
 *
 * Created on April 30, 2016, 2:05 PM
 */

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <assert.h>
#include "ArenaInterface.h"
#include "Fighter.h"
#include "Archer.h"
#include "Cleric.h"
#include "Robot.h"

using namespace std;

class Arena : public ArenaInterface
{
public:
    Arena(){}
        virtual ~Arena(){}
    
    bool addFighter(string info);
    bool removeFighter(string name);
    FighterInterface* getFighter(string name);
    int getSize();
    bool CheckIfNameExist(vector<Fighter*> fighterNames, string name);
    int FindPositionOfMatch(vector<Fighter*> fighterNames, string name);
    friend ostream& operator<<(ostream&, const Fighter&);

//private:
    vector<Fighter*> Fighters;
    
};
