#pragma once

#include "Deck.h"
#include "StartPlug.h"
#include <vector>
#include <stdlib.h>
#include <random>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/undirected_graph.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include "MapConquerer.h"

using namespace boost;
typedef property_map<Graph, vertex_index_t>::type IndexMap;

class StartUp
{
public:
	StartUp();
	~StartUp();
	std::vector<FantasyRaceBanner*> raceBanners;
	std::vector<Player*> getPlayers();
	int getIndexStartingPlayer();
	int getStartingPlayer();
	GameMap* getGameMap();
	//std::vector<FantasyRaceBanner*> getRaceBannersFromDeck(std::vector<int>, std::vector<int>);
	std::vector<FantasyRaceBanner*> getRaceBannersFromDeck();
	std::vector<int> takenRaces;
	std::vector<int> takenSpecialPowers;
	MapConquerer* mapConquerer;
	Deck* getDeck();
private:
	Deck * deck;
	StartPlug* startPlug;
	GameMap* gameMap;
	void executeStartPlug();
	void setTokensOnRegions();
	void setCoinsToPlayers();

	std::vector<vertex_d> vertex_descriptors;
	int indexPlayerStartingGame;

};

