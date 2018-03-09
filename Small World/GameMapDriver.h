/*
 * GameMapDriver.h
 *
 *  Created on: Feb 14, 2018
 *      Author: fvergara
 */

#ifndef CONTROLLER_GAMEMAPDRIVER_H_
#define CONTROLLER_GAMEMAPDRIVER_H_

#include <boost/graph/graph_traits.hpp>
#include <boost/graph/undirected_graph.hpp>
#include "GameMap.h"
#include <iostream>


class GameMapDriver{
private:
	GameMap* gameMap;
public:
	GameMapDriver();
	~GameMapDriver();
	GameMap* createGameMapForNumberOfPlayers(int);
	GameMap* getGeneratedGameMap();
};



#endif /* CONTROLLER_GAMEMAPDRIVER_H_ */
