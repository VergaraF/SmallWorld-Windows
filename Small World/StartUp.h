#pragma once

#include "Deck.h"
#include "StartPlug.h"
#include <vector>
#include <stdlib.h>
#include <random>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/undirected_graph.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

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
private:
	Deck * deck;
	StartPlug* startPlug;
	GameMap* gameMap;
	std::vector<FantasyRaceBanner*> getRaceBannersFromDeck();
	void executeStartPlug();
	void setTokensOnRegions();
	void setCoinsToPlayers();
	std::vector<int> takenRaces;
	std::vector<int> takenSpecialPowers;
	std::vector<vertex_d> vertex_descriptors;
	int indexPlayerStartingGame;

};

