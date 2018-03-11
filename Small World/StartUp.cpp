#include "StartUp.h"
#include <stdlib.h>


StartUp::StartUp()
{
	this->deck = new Deck(true);
	StartPlug* startPlug = new StartPlug();
	executeStartPlug();
	this->raceBanners = getRaceBannersFromDeck();
	//this->gameMap.getGameMap()[0].setTokens(1000);
	setLostTribeTokens();
	std::cout << "test" << std::endl;
}
void StartUp::executeStartPlug() {
	this->gameMap = this->startPlug->loadMap();
	std::cout << "Enter number of players : " << std::endl;
	int numOfPlayers = 0;
	std::cin >> numOfPlayers;
	//startPlug->createPlayers(numOfPlayers);
}

std::vector<FantasyRaceBanner*> StartUp::getRaceBannersFromDeck() {
	// we need 5 racebanner with 5 random races and 5 random powers
	std::vector<FantasyRaceBanner*> banners;

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
		this->deck->fantasyRaceBanners.pop_back();
		banners.push_back(new FantasyRaceBanner(race, specialPowerBadge));
		takenRaces.push_back(randomRace);
		takenSpecialPowers.push_back(randomPower);
	}

	return banners;
}
void StartUp::setLostTribeTokens()
{
	typedef graph_traits<Graph>::vertex_descriptor vertex_d;
	Graph map = *(this->gameMap->getGameMap());
	// get the property map for vertex indices
	typedef boost::property_map<Graph, boost::vertex_index_t>::type IndexMap;
	Region region;
	IndexMap index = get(vertex_index, map);

	std::cout << "vertices(this->graph) = ";
	typedef graph_traits<Graph>::vertex_iterator vertex_iter;
	std::pair<vertex_iter, vertex_iter> vp;
	
	for (vp = vertices(*(this->gameMap->getGameMap())); vp.first != vp.second; ++vp.first) {
		vertex_d ver = *vp.first;
		this->vertex_descriptors.push_back(ver);
		map[ver].setTokens(100);
		std::cout << index[ver] << " ";
	
	}
	std::cout << std::endl;

	
	this->gameMap->setGameMap(map);
}
StartUp::~StartUp()
{
}

