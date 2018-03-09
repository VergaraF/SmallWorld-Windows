/*
 * Dice.cpp
 *
 *  Created on: Feb 16, 2018
 *      Author: fvergara
 */

//#include <Dice.h>;
#include "Dice.h"
#include <stdlib.h>
#include <random>



Dice::Dice(){
	this->currentNumber = 0;
}

int Dice::roll(){
	this->currentNumber = numbersOnDice[rand() % 6 + 1];
	return this->currentNumber;
}

int Dice::getCurrentNumber(){
	return this->currentNumber;
}

