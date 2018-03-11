/*
 * Dice.cpp
 *
 *  Created on: Feb 16, 2018
 *      Author: fvergara
 */

#include "Dice.h"
#include <stdlib.h>
#include <random>


Dice::Dice() {
	this->currentNumber = 0;
	this->totalNumberOfRolls = 0;
	this->numbersRolled[4] = { 0 };
}

int Dice::roll() {
	std::cout << "Rolling dice" << std::endl;
	this->totalNumberOfRolls++;
	this->currentNumber = numbersOnDice[rand() % 7];
	this->numbersRolled[this->currentNumber]++;
	return this->currentNumber;
}

int Dice::getCurrentNumber() {
	return this->currentNumber;
}

std::string Dice::getStatistics() {
	std::stringstream temp;
	temp << "Player has rolled the dice " << this->totalNumberOfRolls << " times" << std::endl;
	double tempDouble = 0.0;
	for (unsigned int i = 0; i < 4; i++) {
		tempDouble = ((double)this->numbersRolled[i] / (double)this->totalNumberOfRolls) * 100;
		temp << "Number rolled [" << i << "] = " << tempDouble << "%" << std::endl;
	}

	return temp.str();
}

