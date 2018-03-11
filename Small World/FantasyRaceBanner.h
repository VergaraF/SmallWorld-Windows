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
	FantasyRaceBanner(Race*, UniqueSpecialPowerBadge*);
	FantasyRaceBanner(RaceType, SpecialPowerType);
	~FantasyRaceBanner();
	void setStatus(Status);
	Status getStatus();
	Race* getRace();
	UniqueSpecialPowerBadge* getPower();
	void setRace(Race*);
	void setSpecialPower(SpecialPowerType);
private:
	Race* race;
	UniqueSpecialPowerBadge* power;
	Status status;


};

