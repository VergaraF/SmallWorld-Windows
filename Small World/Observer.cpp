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

void Observer::notifyNumberOfPlayers(int numOfPlayers) {
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
void Observer::notifyConquest(std::string conquests){
	playerConquests.push_back(conquests);
}

void Observer::notifyAction(std::string currentPlayerAction) {
	std::stringstream temp;
	temp << "Player # " << playerNumber << currentPlayerAction << std::endl;
	std::cout << temp.str() << std::endl;
}

void Observer::notifyPlayer(int player) {
	playerNumber = player;
}

void Observer::notifyRegionsOwned(int regionsOwnedByPlayer) {
	switch(playerNumber) {
	case 1: {
		regionsOwnedForPlayerOne = regionsOwnedByPlayer;
		break;
	}
	case 2: {
		regionsOwnedForPlayerTwo = regionsOwnedByPlayer;
		break;
	}
	case 3: {
		regionsOwnedForPlayerThree = regionsOwnedByPlayer;
		break;
	}
	case 4:{
		regionsOwnedForPlayerFour = regionsOwnedByPlayer;
		break;
	}
	case 5: {
		regionsOwnedForPlayerFive = regionsOwnedByPlayer;
	}
	//throw exception
	}	
}

void Observer::notifyCoins(int coins) {
	playerCoins.push_back(coins);
}

void Observer::notifyHand(std::string handString) {
	playerHands.push_back(handString);
}


