/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fighter.cpp
 * Author: jcovey
 * 
 * Created on April 30, 2016, 3:24 PM
 */

#include <iostream>
#include <string>
#include <vector>
#include "Fighter.h"

using namespace std;
//---------------------------------------------------------------------------------------
//Fighter::Fighter(string name_in, int Hp_in, int strength_in, int speed_in, int magic_in) :
//    name(name_in), maxHp(Hp_in), maxStrength(strength_in), maxSpeed(speed_in), maxMagic(magic_in) {
//    currentHp = maxHp;
//    currentStrength = maxStrength;
//    currentSpeed = maxSpeed;
//    currentMagic = maxMagic;
//}
//

Fighter::~Fighter(){}
//---------------------------------------------------------------------------------------
            string Fighter::getName() {
                return name;
            }

            int Fighter::getMaximumHP(){
                return maxHp;               
            }

            int Fighter::getCurrentHP(){
                return currentHp;                
            }

            int Fighter::getStrength(){
                return currentStrength;
            }
            int Fighter::getSpeed(){
                return currentSpeed;
            }

            int Fighter::getMagic(){
                return currentMagic;
            }

            void Fighter::takeDamage(int damage){
                
                if (damage - (currentSpeed/4) > 1)
                    currentHp -= (damage - (currentSpeed/4));
                else
                    currentHp -= 1;
                
               // if(currentHp < 0)
               //     currentHp = 0;
            }
            

//           ostream& operator<<(ostream& os, const Fighter& fighter){
//                        os << "Name:"  << "Current HP: " << '\n';
//                        os << "Current Strength: " <<  '\n' << "Current Speed: " << '\n';
//                        os << "Current Magic: " << '\n';
//                    return os;
//                }

