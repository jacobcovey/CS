/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cleric.cpp
 * Author: jcovey
 * 
 * Created on May 2, 2016, 6:57 AM
 */

#include "Cleric.h"

Cleric::Cleric(string name_in, int Hp_in, int strength_in, int speed_in, int magic_in)
:Fighter(name_in, Hp_in, strength_in, speed_in, magic_in)
{
    maxMana = magic_in * 5;
    currentMana = maxMana;
}

Cleric::~Cleric() {
}
/*
		 *	getDamage()
		 *
		 *	Returns the amount of damage a fighter will deal.
		 *
		 *	Robot:
		 *	This value is equal to the Robot's strength plus any additional damage added for having just used its special ability.
                 * 
		 *	Cleric:
		 *	This value is equal to the Cleric's magic.
		 */
    int Cleric::getDamage(){
        return currentMagic;
    }
                /*
		 *	reset()
		 *
		 *	Restores a fighter's current hit points to its maximum hit points.
		 *
		 *	Robot:
		 *	Also restores a Robot's current energy to its maximum value (which is 2 times its magic).
		 *	Also resets a Robot's bonus damage (calculated when a Robot uses its ability) to 0.
		 *
		 *	Cleric:
		 *	Also restores a Cleric's current mana to its maximum value (which is 5 times its magic).
		 */
    void Cleric::reset(){
        currentHp = maxHp;
        currentMana = maxMana;
    }
                /*
		 *	regenerate()
		 *
		 *	Increases the fighter's current hit points by an amount equal to one sixth of
		 *	the fighter's strength.  This method must increase the fighter's current hit 
		 *	points by at least one.  Do not allow the current hit points to exceed the 
		 *	maximum hit points.
		 *
		 *	Cleric:
		 *	Also increases a Cleric's current mana by an amount equal to one fifth of the 
		 *	Cleric's magic.  This method must increase the Cleric's current mana by at 
		 *	least one.  Do not allow the current mana to exceed the maximum mana (again, 5 times its magic).
		 */
    void Cleric::regenerate(){
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

        if (currentMagic/5 < 1)
            currentMana += 1;
        else 
            currentMana += currentMagic/5;
        
        if (currentMana > maxMana)
            currentMana = maxMana;
    }
                /*
		 *	useAbility()
		 *	
		 *	Attempts to perform a special ability based on the type of fighter.  The 
		 *	fighter will attempt to use this special ability just prior to attacking 
		 *	every turn.
		 *
		 *	Cleric: Healing Light
		 *	Increases the Cleric's current hit points by an amount equal to one third of its magic.
		 *	Can only be used if the Cleric has at least [CLERIC_ABILITY_COST] mana.
		 *	Will be used even if the Cleric's current HP is equal to their maximum HP.
		 *	Decreases the Cleric's current mana by [CLERIC_ABILITY_COST] when used.
		 *	Cleric Note:
		 *	This ability, when successful, must increase the Cleric's current hit points 
		 *	by at least one, unless doing so would given the Cleric more hit points than its maximum hit points.  
		 *	Do not allow the current hit points to exceed the maximum hit points.
		 *
		 *	Return true if the ability was used; false otherwise.
		 */
    bool Cleric::useAbility(){
        if (currentMana < CLERIC_ABILITY_COST)
            return false;
        else {
            currentMana -= CLERIC_ABILITY_COST;
            if (currentMagic/3 < 1)
                currentHp += 1;
            else 
                currentHp += currentMagic/3;

            if (currentHp > maxHp)
                currentHp = maxHp;
            
            cout << "Current HP: " << currentHp << endl;
            return true;
        }
    }
