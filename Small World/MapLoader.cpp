/*
 * MapLoader.cpp
 *
 *  Created on: Feb 16, 2018
 *      Author: fvergara
 */

#include "MapLoader.h"

GameMap MapLoader::readFile() {
	std::ifstream input("./MapFile.txt");
	//input.open(;

	if (input.fail()) {
		std::cout << " File does not exist or it has wrong format" << std::endl;
		std::cout << "Exit program" << std::endl;
		return NULL;

	}

	GameMap m = readInfoFromFile(input);
	//	m = readInfoFromFile(myReadFile);
	return m;
}

GameMap MapLoader::readInfoFromFile(std::ifstream& fileContents) {

	int regionNum(0);

	std::string regionName;
	std::vector<int> neighbourRegions;

	//read line by line and add to a vector of string tokens
	std::string token;
	std::vector<std::string> tokens;

	std::string line;
	std::stringstream linestream(line);

	int tempInt(0);

	while (!fileContents.eof()) {
		while (getline(fileContents, line)) {
			getline(linestream, token);

			while (!linestream.eof()) {
				linestream >> token;
				tokens.push_back(token);
			}
			std::stringstream temp(tokens[0]);
			temp >> regionNum;
			regionName = tokens[1];

			for (unsigned i = 2; i < tokens.size(); i++) {
				temp.str(tokens[i]);
				temp >> tempInt;
				neighbourRegions.push_back(tempInt);
			}

			//create a new region for this line
			RegionToAdd regionToAdd;
			regionToAdd.index = regionNum;
			regionToAdd.region = Region();
			regionToAdd.region.setRegionIndex(regionToAdd.index);
			regionToAdd.neighbours = neighbourRegions;

			//and add it to the list of regions
			allRegions.push_back(regionToAdd);
		}
	}

	//create empty map
	GameMap gameMap;

	std::vector<vertex_d> vertices;
	for (unsigned i = 0; i < this->allRegions.size(); i++) {
		vertices.push_back(gameMap.addRegion(allRegions[i].region));
	}

	for (unsigned i = 0; i < this->allRegions.size(); i++) {

		for (const auto& regionNeighbourIndex : this->allRegions[i].neighbours)
		{
			gameMap.makeRegionConnection(vertices.at[i], vertices.at(regionNeighbourIndex));
		}
		
	}

	return gameMap;
}
