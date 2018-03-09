/*
 * MapLoader.cpp
 *
 *  Created on: Feb 16, 2018
 *      Author: fvergara
 */

#include "MapLoader.h"


std::vector<RegionToAdd*> allRegions;

GameMap readFile(){
//	std::ifstream input = std::ifstream("MapFile.txt");
	std::ifstream myReadFile;
	 myReadFile.open("text.txt");
	//input.open(;

		if(myReadFile.fail()) {
				std::cout << " File does not exist or it has wrong format" << std::endl;
				std::cout << "Exit program" << std::endl;
				//return NULL;
		}

		GameMap m;
	//	m = readInfoFromFile(myReadFile);
		return m;
}

GameMap readInfoFromFile(std::ifstream fileContents){

		int regionNum(0);
		std::string regionName;
		std::vector<int> neighbourRegions;

		//read line by line and add to a vector of string tokens
		std::string token;
		std::vector<std::string> tokens;

		std::string line;
		std::stringstream linestream(line);

		int tempInt(0);


		while(!fileContents.eof()) {
				while(getline(fileContents,line)) {
					getline(linestream,token);

					while (!linestream.eof()) {
						linestream >> token;
						tokens.push_back(token);
					}
					std::stringstream temp(tokens[0]);
					temp >> regionNum;
					regionName = tokens[1];

					for (unsigned i=2; i<tokens.size(); i++) {
						temp.str(tokens[i]);
						temp >> tempInt;
						neighbourRegions.push_back(tempInt);
					}

					//create a new region for this line
					//Region region();
					RegionToAdd regionToAdd;
					regionToAdd.index = regionNum;
					//regionToAdd.region = region;
					regionToAdd.neighbours = neighbourRegions;


					//and add it to the list of regions
					allRegions.push_back(&regionToAdd);
				}
			}

		//create empty map
		GameMap gameMap(allRegions.size());

		std::vector<Graph::vertex_descriptor> vertices;
		for (unsigned i = 0; i < allRegions.size(); i++){
			//force casting/ - may induce errors
			vertices.push_back(gameMap.addRegion(Region(allRegions.at(i)->index, 0)));
		}
		for (unsigned i = 0; i < allRegions.size(); i++) {
			for (unsigned j = 0; j < allRegions[i]->neighbours.size(); j++) {
				gameMap.makeRegionConnection(vertices.at(i),vertices.at(j));
			}
		}

		return gameMap;
}
