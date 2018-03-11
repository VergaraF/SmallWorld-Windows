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

typedef boost::adjacency_list<boost::vecS,
                              boost::vecS,
                              boost::undirectedS,
                              Region,
							  boost::no_property> Graph;

typedef boost::graph_traits<Graph>::vertex_descriptor vertex_d;
typedef boost::graph_traits<Graph>::edge_descriptor edge_d;

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
	Graph gameMap;

public:
	GameMap();
	//GameMap(int);
	GameMap(Players);
	//GameMap(int, Region*, Graph::vertex_descriptor*);
	~GameMap();
	vertex_d addRegion(Region);
	Graph* getGameMap();
	void setGameMap(Graph);
	void makeRegionConnection(vertex_d, vertex_d);
	void createMapForTwoPlayers(vertex_d*);
	void createMapForThreePlayers(vertex_d*);
	void createMapForFourPlayers(vertex_d*);
	void createMapForFivePlayers(vertex_d*);
	int numberOfRegions;

};



#endif /* MODEL_GAMEMAP_H_ */
