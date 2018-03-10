#pragma once

#include "Race.h"
enum class Status {
	ACTIVE,
	DECLINE
};

class FantasyRaceBanner
{
public:
	FantasyRaceBanner(RaceType);
	~FantasyRaceBanner();
	void setStatus(Status);
	Status getStatus();
	Race* getRace();

private:
	Race* race;
	Status status;

};

