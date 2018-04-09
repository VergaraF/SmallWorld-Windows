#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include "GameMap.h"
#include <iomanip>

class ObserverInterface
{
public:
	virtual void notifyPlayerAction(std::string) = 0;
	virtual void notifyObserverOfPlayer(int) = 0;
	virtual void notifyRegionsOwned(int) = 0;
	virtual void notifyNumberOfPlayersInGame(int) = 0;
	virtual void notifyPlayerConquest(std::string) = 0;
	virtual void notifyPlayerHand(std::string) = 0;
	virtual void notifyPlayerCoins(int) = 0;
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
	static std::vector<std::string> playerHands;
};

class Observer : 
	public ObserverInterface 
{
public:
	void notifyPlayerAction(std::string) override;
	void notifyObserverOfPlayer(int) override;
	void notifyRegionsOwned(int) override;
	void notifyNumberOfPlayersInGame(int) override;
	void notifyPlayerConquest(std::string) override;
	void notifyPlayerHand(std::string) override;
	void notifyPlayerCoins(int) override;
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
	static std::vector<std::string> playerHands;
};

