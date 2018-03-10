#include "MatchingRaceToken.h"



MatchingRaceToken::MatchingRaceToken(RaceType race)
{
	this->race = new Race(race);
}

Race* MatchingRaceToken::getRace() {
	return this->race;
}


MatchingRaceToken::~MatchingRaceToken()
{
}
