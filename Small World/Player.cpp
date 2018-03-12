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
	this->gameTurnMarkerPosition = 0;

}

Player::Player(std::string name) {
	this->name = name;
	this->fantasyRaceBanner = new FantasyRaceBanner(RaceType::NONE, SpecialPowerType::BLANK);
	//picks_race();
	this->rollingDiceFacility = new Dice();
	this->summarySheet = new SummarySheet();
	this->gameTurnMarkerPosition = 0;
}

int Player::picks_race(std::vector<FantasyRaceBanner*> banners) {
	std::cout << "Pick a race from the following. Enter the number for desired race: " << std::endl;
	std::stringstream temp;
	for (int i = 0; i < banners.size(); ++i) {
		temp << "[" << i << "] " << banners[i]->getRace()->toString() << " : " << banners[i]->getPower()->toString() << std::endl;
	}
	std::cout << temp.str() << std::endl;
	int userInput;
	std::cin >> userInput;

	this->fantasyRaceBanner = banners[userInput];
	return userInput;
}

void Player::conquers(Region* regionConquered) {
	this->conqueredRegions.push_back(regionConquered);
	regionConquered->hasBeenConquered(true);
	regionConquered->ownedBy = this->name;
	std::cout << "Congratulations, you have conquered a region! How many tokens do you want to put in it ? " << std::endl;
	int userInput;
	std::cin >> userInput;
	std::cout << "Tokens placed." << std::endl;
	//TODO: Put player tokens in that region and remove tokens from player's hand
	//Check if user has enough tokens to put on
}

void Player::scores() {

}

void Player::setName(std::string name) {
	this->name = name;
}

FantasyRaceBanner* Player::getFantasyRaceBanner() {
	return this->fantasyRaceBanner;
}

FantasyRaceBanner * Player::getSecondFantasyRaceBanner()
{
	return this->secondFantasyRaceBanner;
}

int Player::goInDecline(std::vector<FantasyRaceBanner*> banners)
{
	this->fantasyRaceBanner->setStatus(Status::DECLINE);

	std::cout << "Pick a race from the following. Enter the number for desired race: " << std::endl;
	std::stringstream temp;
	for (int i = 0; i < banners.size(); ++i) {
		temp << "[" << i << "] " << banners[i]->getRace()->toString() << " : " << banners[i]->getPower()->toString() << std::endl;
	}
	std::cout << temp.str() << std::endl;
	int userInput;
	std::cin >> userInput;

	this->fantasyRaceBanner = banners[userInput];
	return userInput;
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

std::string Player::getName()
{
	return this->name;
}

