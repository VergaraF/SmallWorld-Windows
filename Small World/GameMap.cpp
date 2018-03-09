/*
 * GameMap.cpp
 *
 *  Created on: Feb 11, 2018
 *      Author: fvergara
 */

#include <iostream>
#include "GameMap.h"
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/undirected_graph.hpp>

GameMap::GameMap() {
	std::cout << "Creating default game map (graph), no players" << std::endl;
	this->gameMap = Graph();
}

GameMap::GameMap(int regions) {
	std::cout << "Creating game map (graph), no players, " << regions << "regions (nodes)" << std::endl;
	this->gameMap = Graph(regions);
}

GameMap::GameMap(Players numberOfPlayers) {
	Graph g;
	switch (numberOfPlayers) {
	case (TWO): {
		std::vector<Region> gameRegions;
		vertex_d vertexDescriptors[FOR_TWO_PLAYERS];
		for (int i = 0; i < FOR_TWO_PLAYERS; ++i) {
			gameRegions.push_back(Region(i, 0));
			vertexDescriptors[i] = addRegion(gameRegions.at(i));
		}
		createMapForTwoPlayers(vertexDescriptors);
		std::cout << "Map for two players created" << std::endl;
		break;
	}
	case(THREE): {
		std::vector<Region> gameRegions;
		vertex_d vertexDescriptors[FOR_THREE_PLAYERS];
		for (int i = 0; i < FOR_THREE_PLAYERS; ++i) {
			gameRegions.push_back(Region(i, 0));
			vertexDescriptors[i] = addRegion(gameRegions.at(i));
		}
		createMapForThreePlayers(vertexDescriptors);
		std::cout << "Map for three players created" << std::endl;
		break;
	}
	case(FOUR): {
		std::vector<Region> gameRegions;
		vertex_d vertexDescriptors[FOR_FOUR_PLAYERS];
		for (int i = 0; i < FOR_FOUR_PLAYERS; ++i) {
			gameRegions.push_back(Region(i, 0));
			vertexDescriptors[i] = addRegion(gameRegions.at(i));
		}
		createMapForFourPlayers(vertexDescriptors);
		std::cout << "Map for four players created" << std::endl;
		break;
	}
	case(FIVE): {
		std::vector<Region> gameRegions;
		vertex_d vertexDescriptors[FOR_FIVE_PLAYERS];
		for (int i = 0; i < FOR_FIVE_PLAYERS; ++i) {
			gameRegions.push_back(Region(i, 0));
			vertexDescriptors[i] = addRegion(gameRegions.at(i));
		}
		createMapForFourPlayers(vertexDescriptors);
		std::cout << "Map for five players created" << std::endl;
		break;
	}
	default: {
		throw "Invalid number of players";
		break;
	}
	}
}

void GameMap::createMapForTwoPlayers(vertex_d* vertexDescriptors) {
	//we can optimize this hard coded values by using a for loop and liked i to i++,
			//except for three places where that rule does not apply.

			//First row
	makeRegionConnection(vertexDescriptors[0], vertexDescriptors[1]);
	makeRegionConnection(vertexDescriptors[0], vertexDescriptors[5]);

	makeRegionConnection(vertexDescriptors[1], vertexDescriptors[2]);
	makeRegionConnection(vertexDescriptors[1], vertexDescriptors[6]);

	makeRegionConnection(vertexDescriptors[2], vertexDescriptors[3]);
	makeRegionConnection(vertexDescriptors[2], vertexDescriptors[6]);
	makeRegionConnection(vertexDescriptors[2], vertexDescriptors[7]);
	makeRegionConnection(vertexDescriptors[2], vertexDescriptors[8]);

	makeRegionConnection(vertexDescriptors[3], vertexDescriptors[4]);
	makeRegionConnection(vertexDescriptors[3], vertexDescriptors[8]);
	makeRegionConnection(vertexDescriptors[3], vertexDescriptors[9]);

	makeRegionConnection(vertexDescriptors[4], vertexDescriptors[9]);
	makeRegionConnection(vertexDescriptors[4], vertexDescriptors[10]);

	//Second row
	makeRegionConnection(vertexDescriptors[5], vertexDescriptors[6]);
	makeRegionConnection(vertexDescriptors[5], vertexDescriptors[11]);

	makeRegionConnection(vertexDescriptors[6], vertexDescriptors[7]);
	makeRegionConnection(vertexDescriptors[6], vertexDescriptors[11]);
	makeRegionConnection(vertexDescriptors[6], vertexDescriptors[12]);

	makeRegionConnection(vertexDescriptors[7], vertexDescriptors[8]);
	makeRegionConnection(vertexDescriptors[7], vertexDescriptors[12]);
	makeRegionConnection(vertexDescriptors[7], vertexDescriptors[13]);

	makeRegionConnection(vertexDescriptors[8], vertexDescriptors[9]);
	makeRegionConnection(vertexDescriptors[8], vertexDescriptors[13]);
	makeRegionConnection(vertexDescriptors[8], vertexDescriptors[14]);

	makeRegionConnection(vertexDescriptors[9], vertexDescriptors[10]);
	makeRegionConnection(vertexDescriptors[9], vertexDescriptors[14]);

	makeRegionConnection(vertexDescriptors[10], vertexDescriptors[14]);
	makeRegionConnection(vertexDescriptors[10], vertexDescriptors[15]);

	//third row
	makeRegionConnection(vertexDescriptors[11], vertexDescriptors[12]);
	makeRegionConnection(vertexDescriptors[11], vertexDescriptors[16]);
	makeRegionConnection(vertexDescriptors[11], vertexDescriptors[17]);

	makeRegionConnection(vertexDescriptors[12], vertexDescriptors[13]);
	makeRegionConnection(vertexDescriptors[12], vertexDescriptors[17]);
	makeRegionConnection(vertexDescriptors[12], vertexDescriptors[17]);
	makeRegionConnection(vertexDescriptors[12], vertexDescriptors[18]);

	makeRegionConnection(vertexDescriptors[13], vertexDescriptors[14]);
	makeRegionConnection(vertexDescriptors[13], vertexDescriptors[18]);
	makeRegionConnection(vertexDescriptors[13], vertexDescriptors[19]);
	makeRegionConnection(vertexDescriptors[13], vertexDescriptors[20]);

	makeRegionConnection(vertexDescriptors[14], vertexDescriptors[15]);
	makeRegionConnection(vertexDescriptors[14], vertexDescriptors[20]);
	makeRegionConnection(vertexDescriptors[14], vertexDescriptors[21]);

	makeRegionConnection(vertexDescriptors[15], vertexDescriptors[21]);
	makeRegionConnection(vertexDescriptors[15], vertexDescriptors[22]);

	//fourth row
	makeRegionConnection(vertexDescriptors[16], vertexDescriptors[17]);

	makeRegionConnection(vertexDescriptors[17], vertexDescriptors[18]);

	makeRegionConnection(vertexDescriptors[18], vertexDescriptors[19]);

	makeRegionConnection(vertexDescriptors[19], vertexDescriptors[20]);

	makeRegionConnection(vertexDescriptors[20], vertexDescriptors[21]);
	makeRegionConnection(vertexDescriptors[20], vertexDescriptors[22]);

	makeRegionConnection(vertexDescriptors[21], vertexDescriptors[22]);



}

void GameMap::createMapForThreePlayers(vertex_d* vertexDescriptors) {
	//As for MapForTwoPlayers function, this can be optimized using a for loop.
	//I'll apply that approach after I get my "bruteforce" solution

	makeRegionConnection(vertexDescriptors[0], vertexDescriptors[1]);
	makeRegionConnection(vertexDescriptors[0], vertexDescriptors[7]);
	makeRegionConnection(vertexDescriptors[0], vertexDescriptors[12]);

	makeRegionConnection(vertexDescriptors[1], vertexDescriptors[2]);
	makeRegionConnection(vertexDescriptors[1], vertexDescriptors[7]);
	makeRegionConnection(vertexDescriptors[1], vertexDescriptors[8]);

	makeRegionConnection(vertexDescriptors[2], vertexDescriptors[3]);
	makeRegionConnection(vertexDescriptors[2], vertexDescriptors[8]);
	makeRegionConnection(vertexDescriptors[2], vertexDescriptors[9]);

	makeRegionConnection(vertexDescriptors[3], vertexDescriptors[4]);
	makeRegionConnection(vertexDescriptors[3], vertexDescriptors[9]);
	makeRegionConnection(vertexDescriptors[3], vertexDescriptors[10]);

	makeRegionConnection(vertexDescriptors[4], vertexDescriptors[5]);
	makeRegionConnection(vertexDescriptors[4], vertexDescriptors[10]);
	makeRegionConnection(vertexDescriptors[4], vertexDescriptors[11]);

	makeRegionConnection(vertexDescriptors[5], vertexDescriptors[6]);
	makeRegionConnection(vertexDescriptors[5], vertexDescriptors[11]);

	makeRegionConnection(vertexDescriptors[6], vertexDescriptors[11]);
	makeRegionConnection(vertexDescriptors[6], vertexDescriptors[16]);
	makeRegionConnection(vertexDescriptors[6], vertexDescriptors[17]);

	makeRegionConnection(vertexDescriptors[7], vertexDescriptors[8]);
	makeRegionConnection(vertexDescriptors[7], vertexDescriptors[12]);

	makeRegionConnection(vertexDescriptors[8], vertexDescriptors[9]);
	makeRegionConnection(vertexDescriptors[8], vertexDescriptors[12]);
	makeRegionConnection(vertexDescriptors[8], vertexDescriptors[13]);

	makeRegionConnection(vertexDescriptors[9], vertexDescriptors[10]);
	makeRegionConnection(vertexDescriptors[9], vertexDescriptors[13]);
	makeRegionConnection(vertexDescriptors[9], vertexDescriptors[14]);

	makeRegionConnection(vertexDescriptors[10], vertexDescriptors[11]);
	makeRegionConnection(vertexDescriptors[10], vertexDescriptors[14]);
	makeRegionConnection(vertexDescriptors[10], vertexDescriptors[15]);

	makeRegionConnection(vertexDescriptors[11], vertexDescriptors[15]);
	makeRegionConnection(vertexDescriptors[11], vertexDescriptors[16]);

	makeRegionConnection(vertexDescriptors[12], vertexDescriptors[13]);
	makeRegionConnection(vertexDescriptors[12], vertexDescriptors[18]);

	makeRegionConnection(vertexDescriptors[13], vertexDescriptors[14]);
	makeRegionConnection(vertexDescriptors[13], vertexDescriptors[18]);
	makeRegionConnection(vertexDescriptors[13], vertexDescriptors[19]);

	makeRegionConnection(vertexDescriptors[14], vertexDescriptors[15]);
	makeRegionConnection(vertexDescriptors[14], vertexDescriptors[19]);
	makeRegionConnection(vertexDescriptors[14], vertexDescriptors[20]);
	makeRegionConnection(vertexDescriptors[14], vertexDescriptors[21]);

	makeRegionConnection(vertexDescriptors[15], vertexDescriptors[16]);
	makeRegionConnection(vertexDescriptors[15], vertexDescriptors[21]);
	makeRegionConnection(vertexDescriptors[15], vertexDescriptors[22]);

	makeRegionConnection(vertexDescriptors[16], vertexDescriptors[17]);
	makeRegionConnection(vertexDescriptors[16], vertexDescriptors[22]);
	makeRegionConnection(vertexDescriptors[16], vertexDescriptors[23]);

	makeRegionConnection(vertexDescriptors[17], vertexDescriptors[23]);
	makeRegionConnection(vertexDescriptors[17], vertexDescriptors[29]);

	makeRegionConnection(vertexDescriptors[18], vertexDescriptors[19]);
	makeRegionConnection(vertexDescriptors[18], vertexDescriptors[24]);
	makeRegionConnection(vertexDescriptors[18], vertexDescriptors[25]);

	makeRegionConnection(vertexDescriptors[19], vertexDescriptors[20]);
	makeRegionConnection(vertexDescriptors[19], vertexDescriptors[25]);
	makeRegionConnection(vertexDescriptors[19], vertexDescriptors[26]);

	makeRegionConnection(vertexDescriptors[20], vertexDescriptors[21]);
	makeRegionConnection(vertexDescriptors[20], vertexDescriptors[26]);
	makeRegionConnection(vertexDescriptors[20], vertexDescriptors[27]);

	makeRegionConnection(vertexDescriptors[21], vertexDescriptors[22]);
	makeRegionConnection(vertexDescriptors[21], vertexDescriptors[27]);
	makeRegionConnection(vertexDescriptors[21], vertexDescriptors[28]);

	makeRegionConnection(vertexDescriptors[22], vertexDescriptors[23]);
	makeRegionConnection(vertexDescriptors[22], vertexDescriptors[28]);

	makeRegionConnection(vertexDescriptors[23], vertexDescriptors[28]);
	makeRegionConnection(vertexDescriptors[23], vertexDescriptors[29]);

	makeRegionConnection(vertexDescriptors[24], vertexDescriptors[25]);

	makeRegionConnection(vertexDescriptors[25], vertexDescriptors[26]);

	makeRegionConnection(vertexDescriptors[26], vertexDescriptors[27]);

	makeRegionConnection(vertexDescriptors[27], vertexDescriptors[28]);

	makeRegionConnection(vertexDescriptors[28], vertexDescriptors[29]);
}

void GameMap::createMapForFourPlayers(vertex_d* vertexDescriptors) {

	//brute for solution
	//TODO: Optimize using loops (or perhaps create a method that will take node1, connectedTo[index1, 2, 3, etc]
	makeRegionConnection(vertexDescriptors[0], vertexDescriptors[1]);
	makeRegionConnection(vertexDescriptors[0], vertexDescriptors[2]);
	makeRegionConnection(vertexDescriptors[0], vertexDescriptors[5]);
	makeRegionConnection(vertexDescriptors[0], vertexDescriptors[6]);
	makeRegionConnection(vertexDescriptors[0], vertexDescriptors[8]);
	makeRegionConnection(vertexDescriptors[0], vertexDescriptors[11]);
	makeRegionConnection(vertexDescriptors[0], vertexDescriptors[16]);

	makeRegionConnection(vertexDescriptors[1], vertexDescriptors[5]);

	makeRegionConnection(vertexDescriptors[2], vertexDescriptors[3]);
	makeRegionConnection(vertexDescriptors[2], vertexDescriptors[6]);

	makeRegionConnection(vertexDescriptors[3], vertexDescriptors[4]);
	makeRegionConnection(vertexDescriptors[3], vertexDescriptors[6]);
	makeRegionConnection(vertexDescriptors[3], vertexDescriptors[9]);
	makeRegionConnection(vertexDescriptors[3], vertexDescriptors[10]);

	makeRegionConnection(vertexDescriptors[4], vertexDescriptors[7]);
	makeRegionConnection(vertexDescriptors[4], vertexDescriptors[10]);

	makeRegionConnection(vertexDescriptors[5], vertexDescriptors[8]);
	makeRegionConnection(vertexDescriptors[5], vertexDescriptors[11]);

	makeRegionConnection(vertexDescriptors[6], vertexDescriptors[8]);
	makeRegionConnection(vertexDescriptors[6], vertexDescriptors[9]);

	makeRegionConnection(vertexDescriptors[7], vertexDescriptors[10]);
	makeRegionConnection(vertexDescriptors[7], vertexDescriptors[14]);
	makeRegionConnection(vertexDescriptors[7], vertexDescriptors[15]);

	makeRegionConnection(vertexDescriptors[8], vertexDescriptors[9]);
	makeRegionConnection(vertexDescriptors[8], vertexDescriptors[11]);
	makeRegionConnection(vertexDescriptors[8], vertexDescriptors[12]);

	makeRegionConnection(vertexDescriptors[9], vertexDescriptors[10]);
	makeRegionConnection(vertexDescriptors[9], vertexDescriptors[12]);
	makeRegionConnection(vertexDescriptors[9], vertexDescriptors[13]);
	makeRegionConnection(vertexDescriptors[9], vertexDescriptors[19]);

	makeRegionConnection(vertexDescriptors[10], vertexDescriptors[14]);
	makeRegionConnection(vertexDescriptors[10], vertexDescriptors[19]);

	makeRegionConnection(vertexDescriptors[11], vertexDescriptors[12]);
	makeRegionConnection(vertexDescriptors[11], vertexDescriptors[16]);
	makeRegionConnection(vertexDescriptors[11], vertexDescriptors[17]);

	makeRegionConnection(vertexDescriptors[12], vertexDescriptors[13]);
	makeRegionConnection(vertexDescriptors[12], vertexDescriptors[17]);
	makeRegionConnection(vertexDescriptors[12], vertexDescriptors[18]);

	makeRegionConnection(vertexDescriptors[13], vertexDescriptors[18]);
	makeRegionConnection(vertexDescriptors[13], vertexDescriptors[19]);

	makeRegionConnection(vertexDescriptors[14], vertexDescriptors[15]);
	makeRegionConnection(vertexDescriptors[14], vertexDescriptors[19]);
	makeRegionConnection(vertexDescriptors[14], vertexDescriptors[20]);

	makeRegionConnection(vertexDescriptors[15], vertexDescriptors[20]);
	makeRegionConnection(vertexDescriptors[15], vertexDescriptors[21]);

	makeRegionConnection(vertexDescriptors[16], vertexDescriptors[17]);
	makeRegionConnection(vertexDescriptors[16], vertexDescriptors[22]);

	makeRegionConnection(vertexDescriptors[17], vertexDescriptors[18]);
	makeRegionConnection(vertexDescriptors[17], vertexDescriptors[22]);
	makeRegionConnection(vertexDescriptors[17], vertexDescriptors[23]);

	makeRegionConnection(vertexDescriptors[18], vertexDescriptors[19]);
	makeRegionConnection(vertexDescriptors[18], vertexDescriptors[23]);
	makeRegionConnection(vertexDescriptors[18], vertexDescriptors[24]);

	makeRegionConnection(vertexDescriptors[19], vertexDescriptors[20]);
	makeRegionConnection(vertexDescriptors[19], vertexDescriptors[24]);
	makeRegionConnection(vertexDescriptors[19], vertexDescriptors[25]);

	makeRegionConnection(vertexDescriptors[20], vertexDescriptors[21]);
	makeRegionConnection(vertexDescriptors[20], vertexDescriptors[25]);
	makeRegionConnection(vertexDescriptors[20], vertexDescriptors[26]);

	makeRegionConnection(vertexDescriptors[21], vertexDescriptors[26]);
	makeRegionConnection(vertexDescriptors[21], vertexDescriptors[27]);

	makeRegionConnection(vertexDescriptors[22], vertexDescriptors[23]);
	makeRegionConnection(vertexDescriptors[22], vertexDescriptors[28]);

	makeRegionConnection(vertexDescriptors[23], vertexDescriptors[24]);
	makeRegionConnection(vertexDescriptors[23], vertexDescriptors[28]);
	makeRegionConnection(vertexDescriptors[23], vertexDescriptors[29]);
	makeRegionConnection(vertexDescriptors[23], vertexDescriptors[30]);

	makeRegionConnection(vertexDescriptors[24], vertexDescriptors[25]);
	makeRegionConnection(vertexDescriptors[24], vertexDescriptors[30]);

	makeRegionConnection(vertexDescriptors[25], vertexDescriptors[26]);
	makeRegionConnection(vertexDescriptors[25], vertexDescriptors[30]);
	makeRegionConnection(vertexDescriptors[25], vertexDescriptors[31]);
	makeRegionConnection(vertexDescriptors[25], vertexDescriptors[32]);
	makeRegionConnection(vertexDescriptors[25], vertexDescriptors[36]);

	makeRegionConnection(vertexDescriptors[26], vertexDescriptors[27]);
	makeRegionConnection(vertexDescriptors[26], vertexDescriptors[32]);
	makeRegionConnection(vertexDescriptors[26], vertexDescriptors[33]);

	makeRegionConnection(vertexDescriptors[27], vertexDescriptors[33]);

	makeRegionConnection(vertexDescriptors[28], vertexDescriptors[29]);

	makeRegionConnection(vertexDescriptors[29], vertexDescriptors[30]);
	makeRegionConnection(vertexDescriptors[29], vertexDescriptors[34]);

	makeRegionConnection(vertexDescriptors[30], vertexDescriptors[31]);
	makeRegionConnection(vertexDescriptors[30], vertexDescriptors[34]);
	makeRegionConnection(vertexDescriptors[30], vertexDescriptors[35]);

	makeRegionConnection(vertexDescriptors[31], vertexDescriptors[35]);
	makeRegionConnection(vertexDescriptors[31], vertexDescriptors[65]);

	makeRegionConnection(vertexDescriptors[32], vertexDescriptors[33]);
	makeRegionConnection(vertexDescriptors[32], vertexDescriptors[36]);
	makeRegionConnection(vertexDescriptors[32], vertexDescriptors[37]);

	makeRegionConnection(vertexDescriptors[33], vertexDescriptors[37]);
	makeRegionConnection(vertexDescriptors[33], vertexDescriptors[38]);

	makeRegionConnection(vertexDescriptors[34], vertexDescriptors[35]);

	makeRegionConnection(vertexDescriptors[35], vertexDescriptors[36]);

	makeRegionConnection(vertexDescriptors[36], vertexDescriptors[37]);

	makeRegionConnection(vertexDescriptors[37], vertexDescriptors[38]);
}

void GameMap::createMapForFivePlayers(vertex_d* vertexDescriptors) {

	//Bruteforce solution
	//TODO: Optimize as the other createMap functions
	makeRegionConnection(vertexDescriptors[0], vertexDescriptors[1]);
	makeRegionConnection(vertexDescriptors[0], vertexDescriptors[5]);
	makeRegionConnection(vertexDescriptors[0], vertexDescriptors[6]);

	makeRegionConnection(vertexDescriptors[1], vertexDescriptors[2]);
	makeRegionConnection(vertexDescriptors[1], vertexDescriptors[6]);
	makeRegionConnection(vertexDescriptors[1], vertexDescriptors[7]);

	makeRegionConnection(vertexDescriptors[2], vertexDescriptors[3]);
	makeRegionConnection(vertexDescriptors[2], vertexDescriptors[7]);
	makeRegionConnection(vertexDescriptors[2], vertexDescriptors[8]);

	makeRegionConnection(vertexDescriptors[3], vertexDescriptors[4]);
	makeRegionConnection(vertexDescriptors[3], vertexDescriptors[8]);
	makeRegionConnection(vertexDescriptors[3], vertexDescriptors[9]);

	makeRegionConnection(vertexDescriptors[4], vertexDescriptors[9]);
	makeRegionConnection(vertexDescriptors[4], vertexDescriptors[10]);

	makeRegionConnection(vertexDescriptors[5], vertexDescriptors[6]);
	makeRegionConnection(vertexDescriptors[5], vertexDescriptors[11]);
	makeRegionConnection(vertexDescriptors[5], vertexDescriptors[16]);
	makeRegionConnection(vertexDescriptors[5], vertexDescriptors[17]);
	makeRegionConnection(vertexDescriptors[5], vertexDescriptors[22]);
	makeRegionConnection(vertexDescriptors[5], vertexDescriptors[27]);
	makeRegionConnection(vertexDescriptors[5], vertexDescriptors[28]);

	makeRegionConnection(vertexDescriptors[6], vertexDescriptors[7]);
	makeRegionConnection(vertexDescriptors[6], vertexDescriptors[11]);

	makeRegionConnection(vertexDescriptors[7], vertexDescriptors[8]);
	makeRegionConnection(vertexDescriptors[7], vertexDescriptors[11]);
	makeRegionConnection(vertexDescriptors[7], vertexDescriptors[12]);

	makeRegionConnection(vertexDescriptors[8], vertexDescriptors[9]);
	makeRegionConnection(vertexDescriptors[8], vertexDescriptors[12]);
	makeRegionConnection(vertexDescriptors[8], vertexDescriptors[13]);

	makeRegionConnection(vertexDescriptors[9], vertexDescriptors[10]);
	makeRegionConnection(vertexDescriptors[9], vertexDescriptors[13]);
	makeRegionConnection(vertexDescriptors[9], vertexDescriptors[14]);

	makeRegionConnection(vertexDescriptors[10], vertexDescriptors[14]);
	makeRegionConnection(vertexDescriptors[10], vertexDescriptors[15]);

	makeRegionConnection(vertexDescriptors[11], vertexDescriptors[12]);
	makeRegionConnection(vertexDescriptors[11], vertexDescriptors[17]);
	makeRegionConnection(vertexDescriptors[11], vertexDescriptors[18]);

	makeRegionConnection(vertexDescriptors[12], vertexDescriptors[13]);
	makeRegionConnection(vertexDescriptors[12], vertexDescriptors[18]);
	makeRegionConnection(vertexDescriptors[12], vertexDescriptors[19]);
	makeRegionConnection(vertexDescriptors[12], vertexDescriptors[24]);

	makeRegionConnection(vertexDescriptors[13], vertexDescriptors[14]);
	makeRegionConnection(vertexDescriptors[13], vertexDescriptors[20]);
	makeRegionConnection(vertexDescriptors[13], vertexDescriptors[24]);

	makeRegionConnection(vertexDescriptors[14], vertexDescriptors[15]);
	makeRegionConnection(vertexDescriptors[14], vertexDescriptors[20]);
	makeRegionConnection(vertexDescriptors[14], vertexDescriptors[21]);

	makeRegionConnection(vertexDescriptors[15], vertexDescriptors[21]);

	makeRegionConnection(vertexDescriptors[16], vertexDescriptors[17]);

	makeRegionConnection(vertexDescriptors[17], vertexDescriptors[18]);
	makeRegionConnection(vertexDescriptors[17], vertexDescriptors[22]);

	makeRegionConnection(vertexDescriptors[18], vertexDescriptors[19]);
	makeRegionConnection(vertexDescriptors[18], vertexDescriptors[22]);
	makeRegionConnection(vertexDescriptors[18], vertexDescriptors[23]);

	makeRegionConnection(vertexDescriptors[19], vertexDescriptors[23]);
	makeRegionConnection(vertexDescriptors[19], vertexDescriptors[24]);

	makeRegionConnection(vertexDescriptors[20], vertexDescriptors[21]);
	makeRegionConnection(vertexDescriptors[20], vertexDescriptors[24]);
	makeRegionConnection(vertexDescriptors[20], vertexDescriptors[25]);

	makeRegionConnection(vertexDescriptors[21], vertexDescriptors[25]);
	makeRegionConnection(vertexDescriptors[21], vertexDescriptors[26]);

	makeRegionConnection(vertexDescriptors[22], vertexDescriptors[23]);
	makeRegionConnection(vertexDescriptors[22], vertexDescriptors[28]);
	makeRegionConnection(vertexDescriptors[22], vertexDescriptors[29]);

	makeRegionConnection(vertexDescriptors[23], vertexDescriptors[24]);
	makeRegionConnection(vertexDescriptors[23], vertexDescriptors[29]);

	makeRegionConnection(vertexDescriptors[24], vertexDescriptors[25]);
	makeRegionConnection(vertexDescriptors[24], vertexDescriptors[29]);
	makeRegionConnection(vertexDescriptors[24], vertexDescriptors[30]);
	makeRegionConnection(vertexDescriptors[24], vertexDescriptors[31]);
	makeRegionConnection(vertexDescriptors[24], vertexDescriptors[37]);

	makeRegionConnection(vertexDescriptors[25], vertexDescriptors[26]);
	makeRegionConnection(vertexDescriptors[25], vertexDescriptors[31]);
	makeRegionConnection(vertexDescriptors[25], vertexDescriptors[32]);

	makeRegionConnection(vertexDescriptors[26], vertexDescriptors[32]);
	makeRegionConnection(vertexDescriptors[26], vertexDescriptors[33]);

	makeRegionConnection(vertexDescriptors[27], vertexDescriptors[28]);
	makeRegionConnection(vertexDescriptors[27], vertexDescriptors[34]);

	makeRegionConnection(vertexDescriptors[28], vertexDescriptors[29]);
	makeRegionConnection(vertexDescriptors[28], vertexDescriptors[34]);
	makeRegionConnection(vertexDescriptors[28], vertexDescriptors[35]);

	makeRegionConnection(vertexDescriptors[29], vertexDescriptors[35]);
	makeRegionConnection(vertexDescriptors[29], vertexDescriptors[36]);
	makeRegionConnection(vertexDescriptors[29], vertexDescriptors[37]);

	makeRegionConnection(vertexDescriptors[30], vertexDescriptors[31]);
	makeRegionConnection(vertexDescriptors[30], vertexDescriptors[37]);
	makeRegionConnection(vertexDescriptors[30], vertexDescriptors[38]);
	makeRegionConnection(vertexDescriptors[30], vertexDescriptors[39]);
	makeRegionConnection(vertexDescriptors[30], vertexDescriptors[45]);

	makeRegionConnection(vertexDescriptors[31], vertexDescriptors[32]);
	makeRegionConnection(vertexDescriptors[31], vertexDescriptors[39]);

	makeRegionConnection(vertexDescriptors[32], vertexDescriptors[33]);
	makeRegionConnection(vertexDescriptors[32], vertexDescriptors[39]);
	makeRegionConnection(vertexDescriptors[32], vertexDescriptors[40]);

	makeRegionConnection(vertexDescriptors[33], vertexDescriptors[40]);

	makeRegionConnection(vertexDescriptors[34], vertexDescriptors[35]);
	makeRegionConnection(vertexDescriptors[34], vertexDescriptors[41]);

	makeRegionConnection(vertexDescriptors[35], vertexDescriptors[36]);
	makeRegionConnection(vertexDescriptors[35], vertexDescriptors[41]);
	makeRegionConnection(vertexDescriptors[35], vertexDescriptors[42]);

	makeRegionConnection(vertexDescriptors[36], vertexDescriptors[37]);
	makeRegionConnection(vertexDescriptors[36], vertexDescriptors[42]);
	makeRegionConnection(vertexDescriptors[36], vertexDescriptors[43]);

	makeRegionConnection(vertexDescriptors[37], vertexDescriptors[38]);
	makeRegionConnection(vertexDescriptors[37], vertexDescriptors[43]);
	makeRegionConnection(vertexDescriptors[37], vertexDescriptors[44]);

	makeRegionConnection(vertexDescriptors[38], vertexDescriptors[45]);
	makeRegionConnection(vertexDescriptors[38], vertexDescriptors[44]);

	makeRegionConnection(vertexDescriptors[39], vertexDescriptors[40]);
	makeRegionConnection(vertexDescriptors[39], vertexDescriptors[45]);
	makeRegionConnection(vertexDescriptors[39], vertexDescriptors[46]);

	makeRegionConnection(vertexDescriptors[40], vertexDescriptors[46]);
	makeRegionConnection(vertexDescriptors[40], vertexDescriptors[47]);

	makeRegionConnection(vertexDescriptors[41], vertexDescriptors[42]);
	makeRegionConnection(vertexDescriptors[42], vertexDescriptors[43]);
	makeRegionConnection(vertexDescriptors[43], vertexDescriptors[44]);
	makeRegionConnection(vertexDescriptors[44], vertexDescriptors[45]);
	makeRegionConnection(vertexDescriptors[45], vertexDescriptors[46]);
	makeRegionConnection(vertexDescriptors[46], vertexDescriptors[47]);
}

void GameMap::makeRegionConnection(vertex_d region1, vertex_d region2) {
	//this->gameMap->add_edge(region1, region2);
	boost::add_edge(region1, region2, this->gameMap);
	//boost::add_edge(region1, region2, this->gameMap);
}

vertex_d GameMap::addRegion(Region reg) {
	std::cout << "Adding region to the map" << std::endl;
	vertex_d regionVertex = boost::add_vertex(this->gameMap);
	this->gameMap[regionVertex].setRegionIndex(reg.getIndex());
	return regionVertex;
}

Graph GameMap::getGameMap() {
	return this->gameMap;
}

GameMap::~GameMap() {
	//this->gameMap = NULL;
//	delete this->gameMap;
}
