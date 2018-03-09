/*
 * GameMap.h
 *
 *  Created on: Feb 7, 2018
 *      Author: fvergara
 */

#ifndef MODEL_GAMEMAP_H_
#define MODEL_GAMEMAP_H_

#include <iostream>
#include "Region.h"
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/undirected_graph.hpp>

typedef boost::adjacency_list<boost::listS,
                              boost::listS,
                              boost::undirectedS,
                              Region,
							 boost::no_property> Graph;

enum Players{ TWO = 2,
			  THREE = 3,
			  FOUR = 4,
			  FIVE = 5};

enum Regions{ FOR_TWO_PLAYERS = 23,
			  FOR_THREE_PLAYERS = 30,
			  FOR_FOUR_PLAYERS = 39,
			  FOR_FIVE_PLAYERS = 48};

class GameMap{

private:
	Graph* gameMap;

public:
	GameMap();
	GameMap(int);
	GameMap(Players);
	//GameMap(int, Region*, Graph::vertex_descriptor*);
	~GameMap();
	Graph::vertex_descriptor addRegion(Region);
	Graph* getGameMap();
	void makeRegionConnection(Graph::vertex_descriptor, Graph::vertex_descriptor);
	void createMapForTwoPlayers(Graph::vertex_descriptor*);
	void createMapForThreePlayers(Graph::vertex_descriptor*);
	void createMapForFourPlayers(Graph::vertex_descriptor*);
	void createMapForFivePlayers(Graph::vertex_descriptor*);

};



#endif /* MODEL_GAMEMAP_H_ */
