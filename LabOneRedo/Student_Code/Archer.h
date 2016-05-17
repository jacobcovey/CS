/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Archer.h
 * Author: jcovey
 *
 * Created on May 2, 2016, 6:57 AM
 */

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "Fighter.h"
using namespace std;

class Archer : public Fighter
{
public:
    Archer(string name_in, int Hp_in, int strength_in, int speed_in, int magic_in)
: Fighter(name_in, Hp_in, strength_in, speed_in, magic_in){ }
        virtual ~Archer();
                

            int getDamage();
            void reset();
            void regenerate();
            bool useAbility();    
           friend ostream& operator<<(ostream&, const Archer&);

private:
    
};
