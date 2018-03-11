#include "Race.h"



Race::Race(RaceType race)
{
	this->race = race;
	switch (race) {
	case RaceType::ELVES:{
		this->priority = 1;
		break;
	}
	case RaceType::ORCS: {
		this->priority = 2;
		break;
	}
	case RaceType::RATMEN: {
		this->priority = 3;
		break;
	}
	case RaceType::TROLLS: {
		this->priority = 4;
		break;
	}
	case RaceType::HALFLINGS: {
		this->priority = 5;
		break;
	}
	case RaceType::WIZARDS: {
		this->priority = 6;
		break;
	}
	case RaceType::AMAZON: {
		this->priority = 7;
		break;
	}
	case RaceType::SORCERERS: {
		this->priority = 8;
		break;
	}
	case RaceType::DWARVES: {
		this->priority = 9;
		break;
	}
	case RaceType::GHOULS: {
		this->priority = 10;
		break;
	}
	case RaceType::TRITONS: {
		this->priority = 11;
		break;
	}
	case RaceType::GIANTS: {
		this->priority = 12;
		break;
	}
	case RaceType::HUMANS: {
		this->priority = 13;
		break;
	}
	case RaceType::SKELETONS: {
		this->priority = 14;
		break;
	}
	}
}

Race::Race() {}

Race::~Race()
{
}

unsigned int Race::getPriority()
{
	return this->priority;
}
