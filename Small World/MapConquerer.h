#pragma once
#include "GameMap.h"
#include "startPlug.h"
//#include "MainGame.h"

class MapConquerer
{
public:
	MapConquerer(GameMap*, std::vector<Player*>);
	~MapConquerer();
	GameMap* gameMap;
	std::vector<Player*> playersInGame;
	void attemptToConquerRegion(Player&, int);
	bool conquerRegion(int, Player&, int);
	bool redeployTroops(Player*, int, std::vector<Player*>&);
};

