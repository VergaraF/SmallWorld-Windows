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

struct RegionToAdd {
	int index;
	Region region;
	std::vector<int> neighbours;
};

class MapLoader {
public:	
	std::vector<RegionToAdd> allRegions;
	GameMap readInfoFromFile(std::ifstream&s);
	GameMap readFile();
};

#endif /* CONTROLLER_INC_MAPLOADER_H_ */
