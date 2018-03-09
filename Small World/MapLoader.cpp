/*
 * MapLoader.cpp
 *
 *  Created on: Feb 16, 2018
 *      Author: fvergara
 */

#include "MapLoader.h"

GameMap MapLoader::readFile(std::string filepath) {
	std::ifstream input(filepath);

	if (input.fail()) {
		std::cout << " File does not exist or it has wrong format" << std::endl;
		std::cout << "Exit program" << std::endl;
		return NULL;
	}

	GameMap m = readInfoFromFile(input);
	return m;
}

GameMap MapLoader::readInfoFromFile(std::ifstream& fileContents) {
	
	int regionIndex = 0;
	std::string regionName;
	std::vector<int> neighbourRegions;

	std::string line;
	std::vector<std::string> lineTokens;
	
	std::string token;
	while (std::getline(fileContents, line))
	{
		for (std::istringstream stringstream(line); stringstream >> token;) {
			lineTokens.push_back(token);
		}

		std::stringstream temp(lineTokens[0]);
		temp >> regionIndex;

		if (!(regionIndex >= 0 && regionIndex <= 47)) {
			std::cout << "Invalid region number, thus invalid map" << std::endl;
			return NULL;
		}

		if (lineTokens.size() < 3) {
			std::cout << "Invalid region map. A region must have an index, name and at least one neighbour" << std::endl;
			return NULL;
		}

		regionName = lineTokens[1];

		int tempInt;
		for (unsigned i = 2; i < lineTokens.size(); i++) {
			std::stringstream temp(lineTokens[i]);
			temp >> tempInt;
			neighbourRegions.push_back(tempInt);
		}

		//create a new region for this line
		RegionToAdd regionToAdd;
		regionToAdd.index = regionIndex;
		regionToAdd.region = Region();
		regionToAdd.region.setRegionIndex(regionToAdd.index);
		regionToAdd.neighbours = neighbourRegions;

		//and add it to the list of regions
		allRegions.push_back(regionToAdd);

		lineTokens.clear();
		neighbourRegions.clear();
	}

	//create empty map
	GameMap gameMap;

	std::vector<vertex_d> vertices;
	for (unsigned i = 0; i < this->allRegions.size(); i++) {
		vertices.push_back(gameMap.addRegion(allRegions[i].region));
	}

	for (unsigned i = 0; i < this->allRegions.size(); i++) {
		for (unsigned j = 0; j < this->allRegions[i].neighbours.size(); ++j) {
			gameMap.makeRegionConnection(vertices[i], vertices[j]);
		}
	}
	return gameMap;
}
