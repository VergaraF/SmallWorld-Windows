//============================================================================
// Name        : Small.cpp
// Author      : Fabian Vergara
// Version     : 1.0.0
// Copyright   : This code belongs to Fabian Vergara and is meant to be present to Dr. Nora Houari by the author itself.
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Controller/inc/GameMapDriver.h"

int main() {
	GameMapDriver* gameMapDriver = new GameMapDriver();
	int players = 0;
	//gameMapDriver->createGameMapForNumberOfPlayers(2);
	std::cout << "How many players are going to play the game? Insert a numeric value from 2 to 5  : ";
	std::cin >> players;

	switch (players)  {
	case 2 : {
		gameMapDriver->createGameMapForNumberOfPlayers(2);
		break;
	}
	case 3: {
		gameMapDriver->createGameMapForNumberOfPlayers(3);
		break;
	}
	case 4: {
		gameMapDriver->createGameMapForNumberOfPlayers(4);
		break;
	}
	case 5: {
		gameMapDriver->createGameMapForNumberOfPlayers(5);
		break;
	}
	default: std::cout << "Invalid number of players" << std::endl;;
	break;
	}
	return 0;
}
