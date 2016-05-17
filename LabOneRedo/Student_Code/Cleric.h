/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cleric.h
 * Author: jcovey
 *
 * Created on May 2, 2016, 6:57 AM
 */

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Fighter.h"
using namespace std;

class Cleric : public Fighter
{
public:
    Cleric(string name_in, int Hp_in, int strength_in, int speed_in, int magic_in);
        virtual ~Cleric();
                

             int getDamage();
             void reset();
             void regenerate();
             bool useAbility();    

private:
    int maxMana;
    int currentMana;
};