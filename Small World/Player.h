/*
 * Player.h
 *
 *  Created on: Jan 24, 2018
 *      Author: fvergara
 */

#include <iostream>
#include <vector>
#include "Dice.h"
#include "GameMap.h"
#include "FantasyRaceBanner.h"
#include "SummarySheet.h"
#include "Coin.h"
#include "MatchingRaceToken.h"
#include "Region.h"
#include "Observer.h"

#ifndef MODEL_PLAYER_H_
#define MODEL_PLAYER_H_

class Player
{
public:
	Player();
	Player(std::string, bool);
	int picks_race(std::vector<FantasyRaceBanner*>, bool);
	Region& conquers(Region*);
	int scores();
	void setName(std::string);
	FantasyRaceBanner* getFantasyRaceBanner();
	FantasyRaceBanner* getSecondFantasyRaceBanner();
	int goInDecline(std::vector<FantasyRaceBanner*>);
	SummarySheet* getSummarySheet();
	Dice* getRollingDiceFacility();
	std::vector<Region> getConqueredRegions();
	std::vector<Coin*> getCoins();
	std::vector<MatchingRaceToken*> getRaceTokens();
	int gameTurnMarkerPosition;
	std::string getName();
	void giveRaceTokens(RaceType);
	std::vector<Region> conqueredRegions;
	void selectObserver();
	void setObserver(Observer* observer);
	Observer* getObserver();
	bool isHuman;

private:
	Observer * obs;
	std::string name;
	FantasyRaceBanner* fantasyRaceBanner;
	FantasyRaceBanner* secondFantasyRaceBanner;
	SummarySheet* summarySheet;
	Dice* rollingDiceFacility;
	std::vector<Coin*> coins;
	std::vector<MatchingRaceToken*> raceTokens;
	int score;
};




#endif /* MODEL_PLAYER_H_ */
