/*
 * Player.h
 *
 *  Created on: Jan 24, 2018
 *      Author: fvergara
 */

#include "BasePlayer.h"

#ifndef MODEL_PLAYER_H_
#define MODEL_PLAYER_H_

class Player :
	public BasePlayer
{
public:
	Player();
	Player(std::string);
	int picks_race(std::vector<FantasyRaceBanner*>) override;
	Region& conquers(Region*) override;
	int scores() override;
	void setName(std::string);
	FantasyRaceBanner* getFantasyRaceBanner();
	FantasyRaceBanner* getSecondFantasyRaceBanner();
	int goInDecline(std::vector<FantasyRaceBanner*>) override;
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

protected:
	std::string name;
	FantasyRaceBanner* fantasyRaceBanner;
	FantasyRaceBanner* secondFantasyRaceBanner;
	SummarySheet* summarySheet;
	Dice* rollingDiceFacility;
	std::vector<Coin*> coins;
	std::vector<MatchingRaceToken*> raceTokens;
	int score;
	bool isSelectingObserver;
	Observer* obs;
};




#endif /* MODEL_PLAYER_H_ */
