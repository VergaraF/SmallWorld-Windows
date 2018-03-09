/*
 * Region.cpp
 *
 *  Created on: Jan 24, 2018
 *      Author: fvergara
 */

#include <iostream>
#include "Player.h"
#include "Region.h"

Region::Region(){ // @suppress("Class members should be properly initialized")

	this->index = 0;
	std::cout << "Creating default region" << std::endl;
	this->tokens++;
}

Region::Region(unsigned int index, unsigned int tokens = 0){
	this->index = index;
	this->tokens = tokens;
}

Player Region::getOwnerPlayer(){
		return this->ownedBy;
}

unsigned int Region::getTokens(){
	return this->tokens;
}

void Region::setOwnerPlayer(Player& pl){
	this->ownedBy = pl;
}

void Region::setTokens(unsigned int token){
		this->tokens = token;
}
