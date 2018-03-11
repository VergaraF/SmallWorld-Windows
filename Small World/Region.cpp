/*
 * Region.cpp
 *
 *  Created on: Jan 24, 2018
 *      Author: fvergara
 */

#include <iostream>
//#include "Player.h"
#include "Region.h"

Region::Region(){
	this->index = 0;
	this->tokens = 0;
	this->isEdge = false;
	this->isMountain = false;
	this->isWater = false;
	this->containsLostTribe = false;
}

Region::Region(unsigned int index, unsigned int tokens = 0){
	this->index = index;
	this->tokens = tokens;
	this->isEdge = false;
	this->isMountain = false;
	this->isWater = false;
	this->containsLostTribe = false;
}

//Player* Region::getOwnerPlayer(){
//	return this->ownedBy;
//}

unsigned int Region::getTokens(){
	return this->tokens;
}

unsigned int Region::getIndex() {
	return this->index;
}

//void Region::setOwnerPlayer(Player* pl){
//	this->ownedBy = pl;
//}

void Region::setTokens(unsigned int token) {
	this->tokens = token;
}

void Region::setRegionIndex(unsigned int index) {
	this->index = index;
}
