#pragma once
#include "GameMap.h"
#include "startPlug.h"
//#include "MainGame.h"

class MapConquerer
{
public:
	MapConquerer(GameMap*);
	~MapConquerer();
	GameMap* gameMap;
	void attemptToConquerRegion(Player*, int, std::vector<Player*>);
	bool conquerRegion(int, Player*, int, std::vector<Player*>);
	bool redeployTroops(Player*);
};

