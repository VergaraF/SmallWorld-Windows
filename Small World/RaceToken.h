#pragma once
#include "Token.h"
#include "Race.h"
class RaceToken :
	public Token
{
public:
	RaceToken(RaceType);
	~RaceToken();
	Race* getRace();

private:
	Race* race;
};

