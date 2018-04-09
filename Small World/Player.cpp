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
	this->isSelectingObserver = true;
	this->isHuman = false;

}

Player::Player(std::string name, bool isHuman = false) 
{
	this->name = name;
	this->fantasyRaceBanner = new FantasyRaceBanner(RaceType::NONE, SpecialPowerType::BLANK);
	//picks_race();
	this->rollingDiceFacility = new Dice();
	this->summarySheet = new SummarySheet();
	this->gameTurnMarkerPosition = 0;
	this->score = 0;
	this->obs = new Observer();
	this->isSelectingObserver = true;
	this->isHuman = isHuman;
}

//automatic is a flag that let's the player choose race automatic or manually (AI or manual player)
int Player::picks_race(std::vector<FantasyRaceBanner*> banners) 
{
	this->obs->notifyPlayerAction(" [" + this->name + "] is picking a race");
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
		this->getObserver()->notifyPlayerHand(handStringRepresentation);
		return userInput; //race picked
}

Region& Player::conquers(Region* regionConquered) 
{
	this->obs->notifyPlayerAction("[" + this->name + "] conquered a region");
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
	this->obs->notifyPlayerConquest("Conquered Region " + regionConquered->getIndex());
	return *regionConquered;
}

int Player::scores() 
{
	//TODO: getr score from special powers
	this->obs->notifyPlayerAction("[" + this->name + "] is scoring some points");
	int temp =  this->score;
	for (int region = 0; region < this->conqueredRegions.size(); ++region) {
		temp += this->conqueredRegions[region].raceTokens.size();
	}

	this->score = temp;
	this->obs->notifyPlayerCoins(temp);
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
	this->obs->notifyRegionsOwned(this->conqueredRegions.size());
	this->obs->notifyPlayerAction("[" + this->name + "] is going in decline and choosing his new race");
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
	std::string handStringRepresentation = banners[userInput]->getRace()->toString() + " " + banners[userInput]->getPower()->toString();
	this->getObserver()->notifyPlayerHand(handStringRepresentation);
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
	if (!this->isSelectingObserver) {
		return;
	}

	this->obs->notifyPlayerAction(" is choosing what information to display. ");
	std::cout << "Enter the number of the desired information you want to be displayed : " << std::endl;
	std::cout << "[0] Basic game information " << std::endl;
	std::cout << "[1] Map occupancy " << std::endl;
	std::cout << "[2] Hands of players " << std::endl;
	std::cout << "[3] Scored coins " << std::endl;
	std::cout << "[4] Quit displaying this menu." << std::endl;

	int userInput;
	std::cin >> userInput;

	if (userInput >= 0 && userInput < 5) {
		switch (userInput) {
		case (1): {
			Observer* newObserver = new MapOwnershipObserver(this->obs);
			this->obs = newObserver;
			break;
		}case (2): {
			Observer* newObserver = new PlayerHandObserver(this->obs);
			this->obs = newObserver;
			break;
		}case (3): {
			Observer* newObserver = new PlayerCoinObserver(this->obs);
			this->obs = newObserver;
			break;
		}case (4): {
			this->isSelectingObserver = false;
			break;
		}
		}
	}
	else {
		std::cout << "Invalid entry, please make sure you enter a number from 0 to 4." << std::endl;
	}
}

void Player::setObserver(Observer* obs) {
	this->obs = obs;
}


