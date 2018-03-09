/*
 * MapLoader.h
 *
 *  Created on: Feb 16, 2018
 *      Author: fvergara
 */

#ifndef CONTROLLER_INC_MAPLOADER_H_
#define CONTROLLER_INC_MAPLOADER_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Region.h"
#include "GameMap.h"

GameMap readInfoFromFile(std::ifstream);

GameMap readFile();

struct RegionToAdd{
	int index;
	Region region;
	std::vector<int> neighbours;
};

#endif /* CONTROLLER_INC_MAPLOADER_H_ */
