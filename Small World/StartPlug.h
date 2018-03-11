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
	void loadMap();
	void createPlayers(int);
	std::vector<Player*> getPlayers();
private:
	std::vector<Player*> players;
};

