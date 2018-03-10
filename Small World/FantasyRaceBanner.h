#pragma once

#include "Race.h"
#include "UniqueSpecialPowerBadge.h"
enum class Status {
	ACTIVE,
	DECLINE
};

class FantasyRaceBanner
{
public:
	FantasyRaceBanner(RaceType, SpecialPowerType);
	~FantasyRaceBanner();
	void setStatus(Status);
	Status getStatus();
	Race* getRace();
	SpecialPowerType getPower();

private:
	Race* race;
	UniqueSpecialPowerBadge* power;
	Status status;

};

