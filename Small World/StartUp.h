#pragma once

#include "Deck.h"
#include <vector>
#include <stdlib.h>
#include <random>

class StartUp
{
public:
	StartUp();
	~StartUp();
	std::vector<FantasyRaceBanner> raceBanners;
private:
	Deck * deck;
	std::vector<FantasyRaceBanner*> getRaceBannersFromDeck();

};

