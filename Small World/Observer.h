#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include "GameMap.h"

class ObserverInterface
{
public:
	virtual void notifyAction(std::string) = 0;
	virtual void notifyPlayer(int) = 0;
	virtual void notifyRegionsOwned(int) = 0;
	virtual void notifyNumberOfPlayers(int) = 0;
	virtual void notifyConquest(std::string) = 0;
	virtual void notifyCoins(int) = 0;

	static int playerNumber;
	static int numberOfPlayersInGame;
	static int numberOfRegionsOnMap;

	static int regionsOwnedForPlayerOne;
	static int regionsOwnedForPlayerTwo;
	static int regionsOwnedForPlayerThree;
	static int regionsOwnedForPlayerFour;
	static int regionsOwnedForPlayerFive;
	
	static std::vector<std::string> playerConquests;
	static std::vector<int> playerCoins;
};

class Observer : public ObserverInterface 
{
public:
	void notifyAction(std::string) override;
	void notifyPlayer(int) override;
	void notifyRegionsOwned(int) override;
	void notifyNumberOfPlayers(int) override;
	void notifyConquest(std::string) override;
	void notifyCoins(int) override;

	static int playerNumber;
	static int numberOfPlayersInGame;
	static int numberOfRegionsOnMap;

	static int regionsOwnedForPlayerOne;
	static int regionsOwnedForPlayerTwo;
	static int regionsOwnedForPlayerThree;
	static int regionsOwnedForPlayerFour;
	static int regionsOwnedForPlayerFive;

	static std::vector<std::string> playerConquests;
	static std::vector<int> playerCoins;

};

