/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Robot.h
 * Author: jcovey
 *
 * Created on May 2, 2016, 6:57 AM
 */

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include "Fighter.h"
using namespace std;

class Robot : public Fighter
{
public:
    Robot(string name_in, int Hp_in, int strength_in, int speed_in, int magic_in);
        virtual ~Robot();
                

             int getDamage();
             void reset();
             void regenerate();
             bool useAbility();  

private:
    int currentBonusDamage;
    int maxEnergy;
    int currentEnergy;
};