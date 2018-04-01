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
	this->edgeType = false;
	this->mountainType = false;
	this->waterType = false;
	this->hasLostTribe = false;
	//this->isConquered = false;
}

Region::Region(unsigned int index, unsigned int tokens = 0){
	this->index = index;
	this->tokens = tokens;
	this->edgeType = false;
	this->mountainType = false;
	this->waterType = false;
	this->hasLostTribe = false;
	//this->isConquered = false;
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

void Region::setRegionType(RegionType type)
{
	switch (type) {
	case RegionType::WATER: {
		this->waterType = true;
		return;
		break;
	}
	case RegionType::EDGE: {
		this->edgeType = true;
		return;
		break;
	}
	case RegionType::MOUNTAIN: {
		this->mountainType = true;
		return;
		break;
	}
	}
}

void Region::setEdgeRegion(bool edgy)
{
	this->edgeType = edgy;
}

void Region::setTribeOnRegion(bool value)
{
	this->hasLostTribe = value;
}

bool Region::containsLostTribe()
{
	return this->hasLostTribe;
}

bool Region::isMountain()
{
	return this->mountainType;
}

bool Region::isWater()
{
	return this->waterType;
}

bool Region::isEdge()
{
	return this->edgeType;
}

bool Region::isConquered()
{
	return (this->hasLostTribe || !this->raceTokens.empty());
}

bool Region::hasBeenConquered(bool value)
{
	this->conquered = true;
	return this->conquered;
}
