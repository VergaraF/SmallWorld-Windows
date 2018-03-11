#pragma once

#include <vector>
#include "StartUp.h"

enum class GameTurnRack {
	EIGHT = 8,
	NINETH = 9,
	TENTH = 10
};
class MainGame
{
public:
	MainGame();
	~MainGame();
	std::vector<Player*> players;
	int currentGameTurnPosition;
	int firstPlayer;
	StartUp* startUp;
	void letPlayersChooseRace();
	int getFirstPlayerIndex();
};

