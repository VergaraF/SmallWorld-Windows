#include "RaceToken.h"



RaceToken::RaceToken(RaceType race)
{
	this->race = new Race(race);
}

Race* RaceToken::getRace() {
	return this->race;
}


RaceToken::~RaceToken()
{
}
