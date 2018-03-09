/*
 * GameMapDriver.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: fvergara
 */

#include "GameMapDriver.h"

GameMapDriver::GameMapDriver(){
	this->gameMap = new GameMap();
}

GameMapDriver::~GameMapDriver(){
	//this->gameMap = NULL;
	//delete this->gameMap;
};

GameMap*  GameMapDriver::createGameMapForNumberOfPlayers(int players){
	std::cout << "Creating map" << std::endl;
		switch (players){
		case (TWO):{
			this->gameMap = NULL;
			delete this->gameMap;
			this->gameMap = new GameMap(TWO);
			return this->gameMap;
			break;
		}
		case (THREE) : {
			this->gameMap = NULL;
			delete this->gameMap;
			this->gameMap = new GameMap(THREE);
			std::cout << "Game map for three players created" << std::endl;
			return this->gameMap;
			break;
		}
		case (FOUR): {
			this->gameMap = NULL;
		    delete this->gameMap;
			this->gameMap = new GameMap(FOUR);
			std::cout << "Game map for four players created" << std::endl;
			return this->gameMap;
			break;
		}
		case (FIVE):{
			this->gameMap = NULL;
			delete this->gameMap;
			this->gameMap = new GameMap(FIVE);
			std::cout << "Game map for five players created" << std::endl;
			return this->gameMap;
			break;
		}
		default: {
			std::cout << "Invalid number of players" << std::endl;
			return this->gameMap;
			break;
		}
		}
	}

GameMap*  GameMapDriver::getGeneratedGameMap(){
	return this->gameMap;
}
