/*
 * Playet.cpp
 *
 *  Created on: Jan 24, 2018
 *      Author: fvergara
 */

#include "Player.h"

Player::Player() 
{
	this->name = "No name";
	this->fantasyRaceBanner = new FantasyRaceBanner(RaceType::NONE, SpecialPowerType::BLANK);
	this->rollingDiceFacility = new Dice();
	this->summarySheet = new SummarySheet();
	this->gameTurnMarkerPosition = 0;

}

Player::Player(std::string name) 
{
	this->name = name;
	this->fantasyRaceBanner = new FantasyRaceBanner(RaceType::NONE, SpecialPowerType::BLANK);
	//picks_race();
	this->rollingDiceFacility = new Dice();
	this->summarySheet = new SummarySheet();
	this->gameTurnMarkerPosition = 0;
}

int Player::picks_race(std::vector<FantasyRaceBanner*> banners) 
{
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

Region& Player::conquers(Region* regionConquered) 
{
	this->conqueredRegions.push_back(regionConquered);
	regionConquered->hasBeenConquered(true);
	regionConquered->ownedBy = this->name;
	std::cout << "Congratulations, you have conquered a region! How many tokens do you want to put in it ? " << std::endl;
	int userInput;
	std::cin >> userInput;
	if (userInput <= this->raceTokens.size()) {
		for (int i = 0; i < userInput; ++i) {
			this->raceTokens.pop_back();
			regionConquered->raceTokens.push_back(new MatchingRaceToken(this->fantasyRaceBanner->getRace()->getRaceType()));
		}
	}
	else {
		std::cout << "You don't have enough tokens to perform this action";
	}
	std::cout << "Tokens placed." << std::endl;
	return *regionConquered;
}

void Player::scores() 
{
	//TODO: getr score from special powers
	int temp = 0;
	for (int region = 0; region < this->conqueredRegions.size(); ++region) {
		temp += this->conqueredRegions[region]->raceTokens.size();


	}

	this->score = temp;
}

void Player::setName(std::string name) 
{
	this->name = name;
}

FantasyRaceBanner* Player::getFantasyRaceBanner() 
{
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

SummarySheet* Player::getSummarySheet() 
{
	return this->summarySheet;
}

Dice* Player::getRollingDiceFacility() 
{
	return this->rollingDiceFacility;
}

std::vector<Region*> Player::getConqueredRegions() 
{
	return this->conqueredRegions;
}

std::vector<Coin*> Player::getCoins() 
{
	return this->coins;
}

std::vector<MatchingRaceToken*> Player::getRaceTokens() 
{
	return this->raceTokens;
}

std::string Player::getName()
{
	return this->name;
}

void Player::giveRaceTokens(RaceType raceType)
{
	this->raceTokens.push_back(new MatchingRaceToken(raceType));
}

