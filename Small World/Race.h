#pragma once

#include<string>;

enum class RaceType{ 
	AMAZON,
	DWARVES,
	ELVES,
	GHOULS,
	RATMEN,
	SKELETONS,
	SORCERERS,
	TRITONS,
	GIANTS,
	HALFLINGS,
	HUMANS,
	ORCS,
	TROLLS,
	WIZARDS
};

class Race
{
public:
	Race(RaceType);
	Race();
	~Race();
private:
	RaceType race;
};

