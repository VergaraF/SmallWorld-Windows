#include "Race.h"



Race::Race(RaceType race)
{
	this->race = race;
	switch (race) {
	case RaceType::ELVES:{
		this->raceName = "Elves";
		this->priority = 1;
		break;
	}
	case RaceType::ORCS: {
		this->raceName = "Orcs";
		this->priority = 2;
		break;
	}
	case RaceType::RATMEN: {
		this->raceName = "Ratmen";
		this->priority = 3;
		break;
	}
	case RaceType::TROLLS: {
		this->raceName = "Trolls";
		this->priority = 4;
		break;
	}
	case RaceType::HALFLINGS: {
		this->raceName = "Halflings";
		this->priority = 5;
		break;
	}
	case RaceType::WIZARDS: {
		this->raceName = "Wizards";
		this->priority = 6;
		break;
	}
	case RaceType::AMAZON: {
		this->raceName = "Amazon";
		this->priority = 7;
		break;
	}
	case RaceType::SORCERERS: {
		this->raceName = "Sorcerer";
		this->priority = 8;
		break;
	}
	case RaceType::DWARVES: {
		this->raceName = "Dwarves";
		this->priority = 9;
		break;
	}
	case RaceType::GHOULS: {
		this->raceName = "Ghouls";
		this->priority = 10;
		break;
	}
	case RaceType::TRITONS: {
		this->raceName = "Tritons";
		this->priority = 11;
		break;
	}
	case RaceType::GIANTS: {
		this->raceName = "Giants";
		this->priority = 12;
		break;
	}
	case RaceType::HUMANS: {
		this->raceName = "Humans";
		this->priority = 13;
		break;
	}
	case RaceType::SKELETONS: {
		this->raceName = "Skeletons";
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

std::string Race::toString()
{
	return this->raceName;
}
