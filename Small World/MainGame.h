#pragma once

#include <vector>
#include "StartUp.h"
#include "Observer.h"

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
	int gameTurnRack;
	int firstPlayer;
	StartUp* startUp;
	MapConquerer* mapConquerer;
	void letPlayersChooseRace();
	void playGameLoop(int);
	int getFirstPlayerIndex();
	std::vector<int> racesToAvoid;
	std::vector<int> powersToAvoid;
	void assignRaceTokenPerPlayer();
	Observer gameObserver;
private:
	int tokensGrantedAtEveryTurn;
};

