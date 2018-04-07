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
	this->score = 0;
	this->obs = new Observer();

}

Player::Player(std::string name) 
{
	this->name = name;
	this->fantasyRaceBanner = new FantasyRaceBanner(RaceType::NONE, SpecialPowerType::BLANK);
	//picks_race();
	this->rollingDiceFacility = new Dice();
	this->summarySheet = new SummarySheet();
	this->gameTurnMarkerPosition = 0;
	this->score = 0;
	this->obs = new Observer();
}

//automatic is a flag that let's the player choose race automatic or manually (AI or manual player)
int Player::picks_race(std::vector<FantasyRaceBanner*> banners, bool automatic) 
{
	this->obs->notifyAction("Player [" + this->name + "] is picking a race");
	if (!automatic) {
		std::cout << "Pick a race from the following. Enter the number for desired race: " << std::endl;
		std::stringstream temp;
		for (int i = 0; i < banners.size(); ++i) {
			temp << "[" << i << "] " << banners[i]->getRace()->toString() << " : " << banners[i]->getPower()->toString() << std::endl;
		}
		std::cout << temp.str() << std::endl;
		int userInput;
		std::cin >> userInput;

		this->fantasyRaceBanner = banners[userInput];
		std::string handStringRepresentation = banners[userInput]->getRace()->toString() + " " + banners[userInput]->getPower()->toString();
		this->getObserver()->notifyHand(handStringRepresentation);
		return userInput; //race picked
	}
	else {
		// random selected race
		std::cout << "Races available : " << std::endl;
		std::stringstream temp;
		for (int i = 0; i < banners.size(); ++i) {
			temp << "[" << i << "] " << banners[i]->getRace()->toString() << " : " << banners[i]->getPower()->toString() << std::endl;
		}
		std::cout << temp.str() << std::endl;
	}
}

Region& Player::conquers(Region* regionConquered) 
{
	regionConquered->hasBeenConquered(true);
	regionConquered->ownedBy = this->name;
	regionConquered->setTokens(0);
	regionConquered->raceTokens.clear();
	std::cout << "Congratulations, you have conquered a region! How many tokens do you want to put in it ? " << std::endl;
	int userInput;
	std::cin >> userInput;
	if (userInput <= this->raceTokens.size()) {
		for (int i = 0; i < userInput; ++i) {
			this->raceTokens.pop_back();
			regionConquered->raceTokens.push_back(new MatchingRaceToken(this->fantasyRaceBanner->getRace()->getRaceType()));
			
		}
		regionConquered->setTokens(userInput);
		std::cout << "Tokens placed." << std::endl;
	}
	else {
		std::cout << "You don't have enough tokens to perform this action. " << "You have " << this->raceTokens.size() << " available." << std::endl;
		if (this->raceTokens.size() == 1) {
			regionConquered->raceTokens.push_back(new MatchingRaceToken(this->fantasyRaceBanner->getRace()->getRaceType()));
			this->raceTokens.pop_back();
		}
		else {
			for (int i = 0; i < this->raceTokens.size(); ++i) {
				this->raceTokens.pop_back();
				regionConquered->raceTokens.push_back(new MatchingRaceToken(this->fantasyRaceBanner->getRace()->getRaceType()));

			}
			regionConquered->setTokens(userInput);
			std::cout << "You placed your remaining tokens in this region." << std::endl;
		}
	}
	
	return *regionConquered;
}

int Player::scores() 
{
	//TODO: getr score from special powers
	int temp =  this->score;
	for (int region = 0; region < this->conqueredRegions.size(); ++region) {
		temp += this->conqueredRegions[region].raceTokens.size();
	}

	this->score = temp;
	return temp;
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
	this->secondFantasyRaceBanner = this->fantasyRaceBanner;
	std::cout << "Pick a race from the following. Enter the number for desired race: " << std::endl;
	std::stringstream temp;
	for (int i = 0; i < banners.size(); ++i) {
		temp << "[" << i << "] " << banners[i]->getRace()->toString() << " : " << banners[i]->getPower()->toString() << std::endl;
	}
	std::cout << temp.str() << std::endl;
	int userInput;
	std::cin >> userInput;
	this->fantasyRaceBanner = banners[userInput];
	banners.erase(banners.begin() + userInput);
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

std::vector<Region> Player::getConqueredRegions() 
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

Observer* Player::getObserver() {
	return this->obs;
}

void Player::selectObserver()
{
}

void Player::setObserver(Observer* obs) {
	this->obs = obs;
}


