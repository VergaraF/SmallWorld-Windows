#pragma once

#include "MapLoader.h"
#include "Player.h"
#include "Deck.h"
#include <filesystem>
#include <iostream>
#include <vector>

namespace fs = std::experimental::filesystem;

class StartPlug
{
public:
	StartPlug();
	~StartPlug();
	GameMap* loadMap();
	void createPlayers(int);
	std::vector<Player*> players;
	//std::vector<Player*> getPlayers();
private:
	
};

