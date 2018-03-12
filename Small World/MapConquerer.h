#pragma once
#include "GameMap.h"
#include "startPlug.h"

class MapConquerer
{
public:
	MapConquerer(GameMap*);
	~MapConquerer();
	GameMap* gameMap;
	void attemptToConquerRegion(Player*);
	bool conquerRegion(int, Player*);
};

