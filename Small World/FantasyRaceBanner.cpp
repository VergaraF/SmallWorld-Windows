#include "FantasyRaceBanner.h"



FantasyRaceBanner::FantasyRaceBanner(Race* race, UniqueSpecialPowerBadge* power)
{
	this->status = Status::ACTIVE;
	this->race = race;
	this->power = power;
}

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

UniqueSpecialPowerBadge* FantasyRaceBanner::getPower()
{
	return this->power;
}

void FantasyRaceBanner::setRace(Race* race)
{ 
	delete this->race;
	this->race = race;
}

void FantasyRaceBanner::setSpecialPower(SpecialPowerType powerType)
{
	delete this->power;
	this->power = new UniqueSpecialPowerBadge(powerType);
}
