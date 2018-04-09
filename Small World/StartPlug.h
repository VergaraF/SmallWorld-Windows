#pragma once

#include "MapLoader.h"
#include "Player.h"
#include "AggressivePlayer.h"
#include "ModeratePlayer.h"
#include "RandomPlayer.h"
#include "DefensivePlayer.h"
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

