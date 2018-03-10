#pragma once
#include "Token.h"
#include "Race.h"
class MatchingRaceToken :
	public Token
{
public:
	MatchingRaceToken(RaceType);
	~MatchingRaceToken();
	Race* getRace();

private:
	Race* race;
};

