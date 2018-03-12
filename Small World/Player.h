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

#ifndef MODEL_PLAYER_H_
#define MODEL_PLAYER_H_

class Player
{
public:
	Player();
	Player(std::string);
	int picks_race(std::vector<FantasyRaceBanner*>);
	void conquers(Region*);
	void scores();
	void setName(std::string);
	FantasyRaceBanner* getFantasyRaceBanner();
	FantasyRaceBanner* getSecondFantasyRaceBanner();
	int goInDecline(std::vector<FantasyRaceBanner*>);
	SummarySheet* getSummarySheet();
	Dice* getRollingDiceFacility();
	std::vector<Region*> getConqueredRegions();
	std::vector<Coin*> getCoins();
	std::vector<MatchingRaceToken*> getRaceTokens();
	int gameTurnMarkerPosition;
	std::string getName();
	void giveRaceTokens(RaceType);

private:
	std::string name;
	FantasyRaceBanner* fantasyRaceBanner;
	FantasyRaceBanner* secondFantasyRaceBanner;
	SummarySheet* summarySheet;
	Dice* rollingDiceFacility;
	std::vector<Region*> conqueredRegions;
	std::vector<Coin*> coins;
	std::vector<MatchingRaceToken*> raceTokens;
	int score;
};




#endif /* MODEL_PLAYER_H_ */
