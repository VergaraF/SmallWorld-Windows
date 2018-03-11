/*
 * Playet.cpp
 *
 *  Created on: Jan 24, 2018
 *      Author: fvergara
 */

#include "Player.h"

Player::Player(){
	this->coins.push_back(nullptr);
	this->conqueredRegions.push_back(nullptr);
	//this->fantasyRaceBanner.push_back(new FantasyRaceBanner(RaceType::NONE, SpecialPowerType::BLANK));

}

Player::Player(std::string name) {
	this->name = name;
}

void Player::picks_race() {

}

void Player::conquers() {

}

void Player::scores() {

}

void Player::setName(std::string name) {
	this->name = name;
}

FantasyRaceBanner* Player::getFantasyRaceBanner() {
	return this->fantasyRaceBanner;
}

SummarySheet* Player::getSummarySheet() {
	return this->summarySheet;
}

Dice* Player::getRollingDiceFacility() {
	return this->rollingDiceFacility;
}

std::vector<Region*> Player::getConqueredRegions() {
	return this->conqueredRegions;
}

std::vector<Coin*> Player::getCoins() {
	return this->coins;
}

std::vector<MatchingRaceToken*> Player::getRaceTokens() {
	return this->raceTokens;
}

