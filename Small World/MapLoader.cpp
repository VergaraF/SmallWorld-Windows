/*
 * MapLoader.cpp
 *
 *  Created on: Feb 16, 2018
 *      Author: fvergara
 */

#include "MapLoader.h"


GameMap* MapLoader::readFile(std::string filepath) {
	std::ifstream input(filepath);
	GameMap* m;
	if (input.fail()) {
		std::cout << " File does not exist or it has wrong format" << std::endl;
		std::cout << "Exit program" << std::endl;
		std::exit;
	}

	 m = readInfoFromFile(input);
	return m;
}

GameMap* MapLoader::readInfoFromFile(std::ifstream& fileContents) {
	GameMap* gameMap = new GameMap();
	int regionIndex = 0;
	std::string regionType;
    std::string isEdge;
	std::string hasTribe;
	std::vector<int> neighbourRegions;

	std::string line;
	std::vector<std::string> lineTokens;
	
	std::string token;
	while (std::getline(fileContents, line))
	{ 
		try {


			Region* reg = new Region();
			for (std::istringstream stringstream(line); stringstream >> token;) {
				lineTokens.push_back(token);
			}

			std::stringstream temp(lineTokens[0]);
			temp >> regionIndex;

			if (!(regionIndex >= 0 && regionIndex <= 47)) {
				std::cout << "Invalid region number, thus invalid map" << std::endl;
				std::exit;
			}

			if (lineTokens.size() < 3) {
				std::cout << "Invalid region map. A region must have an index, name and at least one neighbour" << std::endl;
				std::exit;
			}

			regionType = lineTokens[1];
			isEdge = lineTokens[2];

			hasTribe = lineTokens[3];

			int tempInt;
			for (unsigned i = 4; i < lineTokens.size(); i++) {
				std::stringstream temp(lineTokens[i]);
				temp >> tempInt;
				neighbourRegions.push_back(tempInt);
			}



			std::transform(regionType.begin(), regionType.end(), regionType.begin(), ::tolower);
			std::transform(isEdge.begin(), isEdge.end(), isEdge.begin(), ::tolower);
			std::transform(hasTribe.begin(), hasTribe.end(), hasTribe.begin(), ::tolower);


			if (!regionType.compare("water")) {
				reg->setRegionType(RegionType::WATER);
			}
			else if (!regionType.compare("mountain")) {
				reg->setRegionType(RegionType::MOUNTAIN);
			}
			else if (!regionType.compare("none")) {
				//do nothing
			}
			else {
				std::cout << "Invalid region type" << std::endl;
			}

			if (!isEdge.compare("edge")) {
				reg->setRegionType(RegionType::EDGE);
			}
			else if (!isEdge.compare("no")) {
				//do nothing
			}
			else
			{
				std::cout << "Invalid map. A region can either be edge or not. " << std::endl;
				std::exit;
			}

			if (!hasTribe.compare("tribe")) {
				reg->setTribeOnRegion(true);
			}
			else if (!hasTribe.compare("notribe")) {
				//do nothing
			}
			else {
				std::cout << "Invalid map. A region can either have a tribe on it or not. " << std::endl;
				std::exit;
			}

			//reg.neighborIndexes = neighbourRegions;
			//create a new region for this line

			//Region test = reg;
			RegionToAdd regionToAdd;
			regionToAdd.index = regionIndex;
			regionToAdd.region = reg;
			regionToAdd.region->setRegionIndex(regionToAdd.index);

			for (int i = 0; i < neighbourRegions.size(); ++i) {
				regionToAdd.neighbours.push_back(neighbourRegions[i]);
			}
			//regionToAdd.neighbours = neighbourRegions;

			//and add it to the list of regions
			allRegions.push_back(regionToAdd);

			lineTokens.clear();
			neighbourRegions.clear();
		}
		catch (...) {
			throw "Wrong map file submited. Operation failed. Reopen the game to try again.";
		}
	}
	

	std::vector<vertex_d> vertices;
	for (unsigned i = 0; i < this->allRegions.size(); i++) {
		vertices.push_back(gameMap->addRegion(*allRegions[i].region));
	}

	for (unsigned i = 0; i < this->allRegions.size(); i++) {
		for (unsigned j = 0; j < this->allRegions[i].neighbours.size(); ++j) {
			gameMap->makeRegionConnection(vertices[i], this->allRegions[i].neighbours[j]);
		}
	}
	gameMap->numberOfRegions = this->allRegions.size();
	return gameMap;
}
