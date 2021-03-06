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
	WIZARDS,
	NONE
};

enum class Utils {
	NUMBER_OF_RACES = 14,
	NUMBER_OF_SPECIAL_POWER_BADGES = 20
};

class Race
{
public:
	Race(RaceType);
	Race();
	~Race();
	unsigned int getPriority();
	RaceType getRaceType();
	std::string toString();
private:
	std::string raceName;
	RaceType race;
	int priority; //lower better
};

