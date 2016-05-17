/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fighter.h
 * Author: jcovey
 *
 * Created on April 30, 2016, 3:24 PM
 */

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "FighterInterface.h"
using namespace std;

class Fighter : public FighterInterface
{
public:
    Fighter(string name_in, int Hp_in, int strength_in, int speed_in, int magic_in):
        name(name_in), maxHp(Hp_in), maxStrength(strength_in), maxSpeed(speed_in), maxMagic(magic_in), currentHp(Hp_in),
		currentStrength(strength_in), currentSpeed(speed_in), currentMagic(magic_in), testing(false) { }

        virtual ~Fighter();
                
            string getName();

            int getMaximumHP();

            int getCurrentHP();

            int getStrength();

            int getSpeed();

            int getMagic();
            


            void takeDamage(int damage);
            
            virtual int getDamage() = 0;

            virtual void reset() = 0;

            virtual void regenerate() = 0;

            virtual bool useAbility() = 0;    
            
            

protected:
    string name;
    int maxHp;
    int currentHp;
    int maxStrength;
    int currentStrength;
    int maxSpeed;
    int currentSpeed;
    int maxMagic;
    int currentMagic;
    bool testing;

};
