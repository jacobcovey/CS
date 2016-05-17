/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Archer.cpp
 * Author: jcovey
 * 
 * Created on May 2, 2016, 6:57 AM
 */

#include "Archer.h"

//Archer::Archer(string name_in, int Hp_in, int strength_in, int speed_in, int magic_in)
//:Fighter(name_in, Hp_in, strength_in, speed_in, magic_in)
//{
//}

Archer::~Archer() {
}
/*
		 *	getDamage()
		 *
		 *	Returns the amount of damage a fighter will deal.
		 *
		 *	Archer:
		 *	This value is equal to the Archer's speed.

		 */
    int Archer::getDamage(){
        return currentSpeed;
    }
/*
		 *	reset()
		 *
		 *	Restores a fighter's current hit points to its maximum hit points.
                 * 
		 *	Archer:
		 *	Also resets an Archer's current speed to its original value.
		 */
    void Archer::reset(){
        currentHp = maxHp;
        currentSpeed = maxSpeed;
    }
/*
		 *	regenerate()
		 *
		 *	Increases the fighter's current hit points by an amount equal to one sixth of
		 *	the fighter's strength.  This method must increase the fighter's current hit 
		 *	points by at least one.  Do not allow the current hit points to exceed the 
		 *	maximum hit points.
		 */
    void Archer::regenerate(){
    	if (testing)
    		cout << "entering Archer:: regenerate. Current HP: " << currentHp << endl;


			if ((currentStrength/6) < 1)
				currentHp += 1;
			else
				currentHp += currentStrength/6;

			if (currentHp > maxHp)
				currentHp = maxHp;

	    	if (testing)
	    		cout << "Exiting Archer:: regenerate. Current HP: " << currentHp << endl;
    }
/*
		 *	useAbility()
		 *	
		 *	Attempts to perform a special ability based on the type of fighter.  The 
		 *	fighter will attempt to use this special ability just prior to attacking 
		 *	every turn.
		 *
		 *	Archer: Quickstep
		 *	Increases the Archer's speed by one point each time the ability is used.
		 *	This bonus lasts until the reset() method is used.
		 *	This ability always works; there is no maximum bonus speed.
		 */
    bool Archer::useAbility(){
        currentSpeed += 1;
        cout << "Current Speed: " << currentSpeed << endl;
        return true;
    }

               ostream& operator<<(ostream& os, const Archer& archer){
                            os << "Name: " <<  archer.getName() << '\n' << "Current HP: " << '\n';
                            os << "Current Strength: " <<  '\n' << "Current Speed: " << '\n';
                            os << "Current Magic: " << '\n';
                        return os;
                    }
