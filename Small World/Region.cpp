/*
 * Region.cpp
 *
 *  Created on: Jan 24, 2018
 *      Author: fvergara
 */

#include <iostream>
#include "Player.h"
#include "Region.h"

Region::Region(){
	this->index = 0;
	this->tokens = 0;
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

unsigned int Region::getIndex() {
	return this->index;
}

void Region::setOwnerPlayer(Player& pl){
	this->ownedBy = pl;
}

void Region::setTokens(unsigned int token){
	this->tokens = token;
}

void Region::setRegionIndex(unsigned int index) {
	this->index = index;
}
