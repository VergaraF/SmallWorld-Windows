/*
 * Dice.h
 *
 *  Created on: Feb 16, 2018
 *      Author: fvergara
 */

#ifndef MODEL_INC_DICE_H_
#define MODEL_INC_DICE_H_

#include<iostream>
#include<string>
#include <sstream>
#include <ctime>

const static int numbersOnDice[6] = {0, 0, 0, 1 ,2 ,3};
//static int numbersRolled[4] = { 0,0,0,0 };

class Dice{

private:
	unsigned int currentNumber;
	unsigned int totalNumberOfRolls;
	unsigned int numbersRolled[4] = { 0 };

public:
	Dice();
	int roll();
	int getCurrentNumber();
	std::string getStatistics();

};



#endif /* MODEL_INC_DICE_H_ */
