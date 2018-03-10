#include "FantasyRaceBanner.h"



FantasyRaceBanner::FantasyRaceBanner(RaceType raceType, SpecialPowerType powerType)
{
	this->status = Status::ACTIVE;
	this->race = new Race(raceType);
	this->power = new UniqueSpecialPowerBadge(powerType);
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

SpecialPowerType FantasyRaceBanner::getPower()
{
	return this->power->getType();
}
