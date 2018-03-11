#include "StartUp.h"
#include <stdlib.h>


StartUp::StartUp()
{
	this->deck = new Deck(true);
}

std::vector<FantasyRaceBanner*> StartUp::getRaceBannersFromDeck() {
	// we need 5 racebanner with 5 random races and 5 random powers
	std::vector<FantasyRaceBanner*> banners;
	std::vector<int> takenRaces;
	std::vector<int> takenSpecialPowers;

	bool keepLookingForRace = true;
	bool keepLookingForSpecialPower = true;
	for (int raceOnBanner = 0; raceOnBanner < 5; ++raceOnBanner) {
		int randomRace; 
		int randomPower;

		while (keepLookingForRace) {
			randomRace = rand() % (int)Utils::NUMBER_OF_RACES;
			if (raceOnBanner == 0 || std::find(takenRaces.begin(), takenRaces.end(), randomRace) == takenRaces.end()) {
				keepLookingForRace = false;
			}
		}

		while (keepLookingForSpecialPower) {
			randomPower = rand() % (int)Utils::NUMBER_OF_SPECIAL_POWER_BADGES;
			if (raceOnBanner == 0 || std::find(takenSpecialPowers.begin(), takenSpecialPowers.end(), randomPower) == takenSpecialPowers.end()) {
				keepLookingForSpecialPower = false;
			}
		}
		keepLookingForRace = true;
		keepLookingForSpecialPower = true; 

		Race* race = new Race((RaceType)randomRace);
		UniqueSpecialPowerBadge* specialPowerBadge = new UniqueSpecialPowerBadge((SpecialPowerType)randomPower);
		banners.push_back(new FantasyRaceBanner(race, specialPowerBadge));
		takenRaces.push_back(randomRace);
		takenSpecialPowers.push_back(randomPower);
	}
	return banners;
}
StartUp::~StartUp()
{
}

