/*
 * Playet.cpp
 *
 *  Created on: Jan 24, 2018
 *      Author: fvergara
 */

#include "Player.h"

Player::Player(){
	this->name = "No name";
	this->fantasyRaceBanner = new FantasyRaceBanner(RaceType::NONE, SpecialPowerType::BLANK);
	this->rollingDiceFacility = new Dice();
	this->summarySheet = new SummarySheet();

}

Player::Player(std::string name) {
	this->name = name;
	this->fantasyRaceBanner = new FantasyRaceBanner(RaceType::NONE, SpecialPowerType::BLANK);
	picks_race();
	this->rollingDiceFacility = new Dice();
	this->summarySheet = new SummarySheet();
}

void Player::picks_race() {
	std::cout << "Pick a race from the following. Enter the number for desired race: " << std::endl;
	//Logic to pick available races

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

