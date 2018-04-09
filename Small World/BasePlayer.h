#pragma once
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
#include "Decorator.h"

class BasePlayer
{
public:
	virtual int picks_race(std::vector<FantasyRaceBanner*>) = 0;
	virtual Region& conquers(Region*) = 0;
	virtual int goInDecline(std::vector<FantasyRaceBanner*>) = 0;
};

