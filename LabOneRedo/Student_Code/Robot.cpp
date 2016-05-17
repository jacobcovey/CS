/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Robot.cpp
 * Author: jcovey
 * 
 * Created on May 2, 2016, 6:57 AM
 */

#include "Robot.h"
#include <math.h>
#include <stdio.h>

Robot::Robot(string name_in, int Hp_in, int strength_in, int speed_in, int magic_in)
:Fighter(name_in, Hp_in, strength_in, speed_in, magic_in)
{
    currentBonusDamage = 0;
    maxEnergy = maxMagic * 2;
    currentEnergy = maxEnergy;
}

Robot::~Robot() {
}
                /*
		 *	getDamage()
		 *
		 *	Returns the amount of damage a fighter will deal.
		 *
		 *	Robot:
		 *	This value is equal to the Robot's strength plus any additional damage added for having just used its special ability.
		 */
    int Robot::getDamage(){
        int damageDelt = currentStrength + currentBonusDamage;
        currentBonusDamage = 0;

        return damageDelt;

    }
                /*
		 *	reset()
		 *
		 *	Restores a fighter's current hit points to its maximum hit points.
		 *
		 *	Robot:
		 *	Also restores a Robot's current energy to its maximum value (which is 2 times its magic).
		 *	Also resets a Robot's bonus damage (calculated when a Robot uses its ability) to 0.
		 */
    void Robot::reset(){
        currentHp = maxHp;
        currentEnergy = maxEnergy;
        currentBonusDamage = 0;
    }
                /*
		 *	regenerate()
		 *
		 *	Increases the fighter's current hit points by an amount equal to one sixth of
		 *	the fighter's strength.  This method must increase the fighter's current hit 
		 *	points by at least one.  Do not allow the current hit points to exceed the 
		 *	maximum hit points.
		 */
    void Robot::regenerate(){
        if ((currentStrength/6) < 1){
            currentHp += 1;
         //cout << "1st option" << endl;
        }
        else{
            currentHp += (currentStrength/6);
           // cout << (currentStrength/6) << endl;
        }
        
        if (currentHp > maxHp)
            currentHp = maxHp;
    }
                /*
		 *	useAbility()
		 *	
		 *	Attempts to perform a special ability based on the type of fighter.  The 
		 *	fighter will attempt to use this special ability just prior to attacking 
		 *	every turn.
		 *
		 *	Robot: Shockwave Punch
		 *	Adds bonus damage to the Robot's next attack (and only its next attack) equal to (strength  * ((current_energy/maximum_energy)^4)).
		 *	Can only be used if the Robot has at least [ROBOT_ABILITY_COST] energy.
		 *	Decreases the Robot's current energy by [ROBOT_ABILITY_COST] (after calculating the additional damage) when used.
		 *		Examples:
		 *		strength=20, current_energy=20, maximum_energy=20		=> bonus_damage=20
		 *		strength=20, current_energy=15, maximum_energy=20		=> bonus_damage=6
		 *		strength=20, current_energy=10, maximum_energy=20		=> bonus_damage=1
		 *		strength=20, current_energy=5,  maximum_energy=20		=> bonus_damage=0
		 *	Robot Note:
		 *	The bonus damage formula should be computed using double arithmetic, and only 
		 *	the final result should be cast into an integer.
		 */
    bool Robot::useAbility(){
        if (currentEnergy < ROBOT_ABILITY_COST) {
            return false;
        }
        else {
            currentBonusDamage = ((double)currentStrength * pow(((double)currentEnergy/ (double)maxEnergy) , 4.0));
            currentEnergy -= ROBOT_ABILITY_COST;            
            cout << "Current Bonus Damage: " << currentBonusDamage << endl;
            return true;
        }
    }

