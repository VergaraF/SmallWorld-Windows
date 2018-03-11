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
	void picks_race();
	void conquers();
	void scores();
	void setName(std::string);
	FantasyRaceBanner* getFantasyRaceBanner();
	SummarySheet* getSummarySheet();
	Dice* getRollingDiceFacility();
	std::vector<Region*> getConqueredRegions();
	std::vector<Coin*> getCoins();
	std::vector<MatchingRaceToken*> getRaceTokens();
	bool hasGameTurnMarker;
private:
	std::string name;
	FantasyRaceBanner* fantasyRaceBanner;
	SummarySheet* summarySheet;
	Dice* rollingDiceFacility;
	std::vector<Region*> conqueredRegions;
	std::vector<Coin*> coins;
	std::vector<MatchingRaceToken*> raceTokens;
};




#endif /* MODEL_PLAYER_H_ */
