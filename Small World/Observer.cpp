#include "Observer.h"

int Observer::playerNumber;
int Observer::numberOfPlayersInGame;
int Observer::numberOfRegionsOnMap;
int Observer::regionsOwnedForPlayerOne;
int Observer::regionsOwnedForPlayerTwo;
int Observer::regionsOwnedForPlayerThree;
int Observer::regionsOwnedForPlayerFour;
int Observer::regionsOwnedForPlayerFive;
std::vector<std::string> Observer::playerConquests;
std::vector<int> Observer::playerCoins;
std::vector<std::string> Observer::playerHands;

void Observer::notifyNumberOfPlayersInGame(int numOfPlayers) {
	this->numberOfPlayersInGame = numOfPlayers;
	if (numOfPlayers == 2) {
		numberOfRegionsOnMap = (int)Regions::FOR_TWO_PLAYERS;
	}
	else if (numOfPlayers == 3) {
		numberOfRegionsOnMap = (int)Regions::FOR_THREE_PLAYERS;
	}
	else if (numOfPlayers == 4) {
		numberOfRegionsOnMap = (int)Regions::FOR_FOUR_PLAYERS;
	}
	else if (numOfPlayers == 5) {
		numberOfRegionsOnMap = (int)Regions::FOR_FIVE_PLAYERS;
	}
	else {
		//throw exception
		numberOfRegionsOnMap = 0;
	}
}
void Observer::notifyPlayerConquest(std::string conquests){
	this->playerConquests.push_back(conquests);
}

void Observer::notifyPlayerAction(std::string currentPlayerAction) {
	std::stringstream temp;
	temp << "Player # " << playerNumber << currentPlayerAction << std::endl;
	std::cout << temp.str() << std::endl;
}

void Observer::notifyObserverOfPlayer(int playerNum) {
	this->playerNumber = playerNum;
}

void Observer::notifyRegionsOwned(int regionsOwnedByPlayer) {
	switch(playerNumber) {
	case 1: {
		this->regionsOwnedForPlayerOne = regionsOwnedByPlayer;
		break;
	}
	case 2: {
		this->regionsOwnedForPlayerTwo = regionsOwnedByPlayer;
		break;
	}
	case 3: {
		this->regionsOwnedForPlayerThree = regionsOwnedByPlayer;
		break;
	}
	case 4:{
		this->regionsOwnedForPlayerFour = regionsOwnedByPlayer;
		break;
	}
	case 5: {
		this->regionsOwnedForPlayerFive = regionsOwnedByPlayer;
	}
	//throw exception
	}	
}

void Observer::notifyPlayerCoins(int coins) {
	this->playerCoins.push_back(coins);
}

void Observer::notifyPlayerHand(std::string handString) {
	this->playerHands.push_back(handString);
}


