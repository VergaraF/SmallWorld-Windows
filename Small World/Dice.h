/*
 * Dice.h
 *
 *  Created on: Feb 16, 2018
 *      Author: fvergara
 */

#ifndef MODEL_INC_DICE_H_
#define MODEL_INC_DICE_H_

#include<iostream>

const static int numbersOnDice[6] = {1, 2, 3, 0 ,0 ,0};

class Dice{

private:
	unsigned int currentNumber;

public:

	Dice();
	int roll();
	int getCurrentNumber();

};



#endif /* MODEL_INC_DICE_H_ */
