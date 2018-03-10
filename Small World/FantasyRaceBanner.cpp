#include "FantasyRaceBanner.h"



FantasyRaceBanner::FantasyRaceBanner(RaceType raceType)
{
	this->status = Status::ACTIVE;
	this->race = new Race(raceType);
}

FantasyRaceBanner::~FantasyRaceBanner()
{
}

void FantasyRaceBanner::setStatus(Status stat)
{
	this->status = stat;
}

Status FantasyRaceBanner::getStatus() {
	return this->status;
}

Race* FantasyRaceBanner::getRace() {
	return this->race;
}
