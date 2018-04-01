#include "StartUp.h"
#include <stdlib.h>


StartUp::StartUp()
{
	this->deck = new Deck(true);
	this->startPlug = new StartPlug();
	executeStartPlug();
	//this->gameMap.getGameMap()[0].setTokens(1000);
	setTokensOnRegions();
//	int indexToStart = this->getStartingPlayer();
//	std::cout << "Player " << indexToStart << " will start the match, as it has the most pointed ears" << std::endl;
	this->mapConquerer = new MapConquerer(this->gameMap);

}
void StartUp::executeStartPlug() {
	this->gameMap = this->startPlug->loadMap();
	std::cout << "Enter number of players : " << std::endl;
	int numOfPlayers = 0;
	std::cin >> numOfPlayers;
	this->startPlug->createPlayers(numOfPlayers);
	
}

void StartUp::setCoinsToPlayers() {
	for (int player = 0; player < this->startPlug->players.size(); ++player) {
		for (int i = 0; i < 3; ++i) {
			this->startPlug->players[player]->getCoins().push_back(new Coin(1));
			this->deck->coinsWithValueOne.pop_back();
		}
	}
}

//std::vector<FantasyRaceBanner*> StartUp::getRaceBannersFromDeck(std::vector<int> racesToAvoid, std::vector<int> powersToAvoid) {
std::vector<FantasyRaceBanner*> StartUp::getRaceBannersFromDeck() {
	// we need 5 racebanner with 5 random races and 5 random powers
	std::vector<FantasyRaceBanner*> banners;

	//takenRaces = racesToAvoid;
	//takenSpecialPowers = powersToAvoid;
	takenRaces;
	takenSpecialPowers;

	bool keepLookingForRace = true;
	bool keepLookingForSpecialPower = true;
	for (int raceOnBanner = 0; raceOnBanner < 5; ++raceOnBanner) {
		if (this->deck->fantasyRaceBanners.size() == 0) {
			break;
		}
		int randomRace; 
		int randomPower;

		while (keepLookingForRace) {
			std::srand(std::time(0));
			randomRace = (rand() % (int)Utils::NUMBER_OF_RACES);
			if (raceOnBanner == 0 || std::find(takenRaces.begin(), takenRaces.end(), randomRace) == takenRaces.end()) {
				keepLookingForRace = false;
			}
		}

		while (keepLookingForSpecialPower) {
			std::srand(std::time(0));
			randomPower = (rand() % (int)Utils::NUMBER_OF_SPECIAL_POWER_BADGES);
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
	this->raceBanners = banners;
	return banners;
}
Deck * StartUp::getDeck()
{
	return this->deck;
}
void StartUp::setTokensOnRegions()
{
	typedef graph_traits<Graph>::vertex_descriptor vertex_d;
	Graph map = *(this->gameMap->getGameMap());
	// get the property map for vertex indices
	typedef boost::property_map<Graph, boost::vertex_index_t>::type IndexMap;
	Region region;
	IndexMap index = get(vertex_index, map);

	typedef graph_traits<Graph>::vertex_iterator vertex_iter;
	std::pair<vertex_iter, vertex_iter> vp;
	
	for (vp = vertices(*(this->gameMap->getGameMap())); vp.first != vp.second; ++vp.first) {
		vertex_d ver = *vp.first;
		this->vertex_descriptors.push_back(ver);
		if (map[ver].containsLostTribe()) {
			map[ver].setTokens(map[ver].getTokens() + 1);
			map[ver].raceTokens.push_back(new LostTribeToken());
			this->deck->lostTribeTokens.pop_back();
		}

		if (map[ver].isMountain()) {
			map[ver].propertyTokens.push_back(new GamePiece(GamePieceType::MOUNTAIN));
			//TODO: do not forget to remove mountain tokens from the deck
		}
	
	}
	std::cout << std::endl;

	this->gameMap->setGameMap(map);
}
StartUp::~StartUp()
{
}

std::vector<Player*> StartUp::getPlayers()
{
	return this->startPlug->players;
}

int StartUp::getIndexStartingPlayer()
{
	return this->indexPlayerStartingGame;
}

int StartUp::getStartingPlayer()
{
	//the lower the temp, the first to start and then we go clockwise
	unsigned int temp = 20;
	unsigned int tempIndex = 0;
	for (unsigned int i = 0; i < this->startPlug->players.size(); ++i) {
		if (this->startPlug->players[i]->getFantasyRaceBanner()->getRace()->getPriority() < temp) {
			temp = this->startPlug->players[i]->getFantasyRaceBanner()->getRace()->getPriority();
			tempIndex = i;
		}
	}
	this->indexPlayerStartingGame = temp;
	return tempIndex;
}

GameMap * StartUp::getGameMap()
{
	return this->gameMap;
}

