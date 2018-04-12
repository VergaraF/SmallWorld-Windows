#include "Decorator.h"



Decorator::Decorator(Observer* obs)
{
	this->decoratorObserver = obs;
}

void Decorator::notifyPlayerAction(std::string playerAction) {
	this->decoratorObserver->notifyPlayerAction(playerAction);
}

void Decorator::notifyObserverOfPlayer(int playerNum) {
	this->decoratorObserver->notifyObserverOfPlayer(playerNum);
}

void Decorator::notifyRegionsOwned(int numberOfRegionsOwned) {
	this->decoratorObserver->notifyRegionsOwned(numberOfRegionsOwned);
}

void Decorator::notifyNumberOfPlayersInGame(int numOfPlayersInGame) {
	this->decoratorObserver->notifyNumberOfPlayersInGame(numOfPlayersInGame);
}

void Decorator::notifyPlayerConquest(std::string conquest) {
	this->decoratorObserver->notifyPlayerConquest(conquest);
}

void Decorator::notifyPlayerHand(std::string hand) {
	this->decoratorObserver->notifyPlayerHand(hand);
}

void Decorator::notifyPlayerCoins(int coins) {
	this->decoratorObserver->notifyPlayerCoins(coins);
}

void MapOwnershipObserver::notifyRegionsOwned(int regionsOwned) {
	this->decoratorObserver->notifyRegionsOwned(regionsOwned);
	this->showCurrentMapOwnsership();
}

double MapOwnershipObserver::getPercentageForPlayer(int playerNum) {
	switch (playerNum) {
	case 1: {
		return ((double)this->regionsOwnedForPlayerOne / (double)this->numberOfRegionsOnMap) * 100;
		break;
	}
	case 2: {
		return ((double)this->regionsOwnedForPlayerTwo / (double)this->numberOfRegionsOnMap) * 100;
		break;
	}
	case 3: {
		return ((double)this->regionsOwnedForPlayerThree / (double)this->numberOfRegionsOnMap) * 100;
		break;
	}
	case 4: {
		return ((double)this->regionsOwnedForPlayerFour / (double)this->numberOfRegionsOnMap) * 100;
		break;
	}
	case 5: {
		return ((double)this->regionsOwnedForPlayerFive / (double)this->numberOfRegionsOnMap) * 100;
		break;
	}
	default: //throw exception 
		return 0;
		break;
	}
}

void MapOwnershipObserver::showCurrentMapOwnsership() {
	double percentOfOwnershipForPlayerOne = this->getPercentageForPlayer(1);
	double percentOfOwnershipForPlayerTwo = this->getPercentageForPlayer(2);
	double percentOfOwnershipForPlayerThree = this->getPercentageForPlayer(3);
	double percentOfOwnershipForPlayerFour = this->getPercentageForPlayer(4);
	double percentOfOwnershipForPlayerFive = this->getPercentageForPlayer(5);

	double percentageOfFreeRegions = (double)100 - (percentOfOwnershipForPlayerOne + percentOfOwnershipForPlayerTwo + percentOfOwnershipForPlayerThree + percentOfOwnershipForPlayerFour + percentOfOwnershipForPlayerFive);
	std::stringstream temp;
	temp << "***************************************************************************************" << std::endl;
	temp << "Regions occupied by player one : " << std::setprecision(2) << std::fixed << percentOfOwnershipForPlayerOne << " %" << std::endl;
	temp << "Regions occupied by player two : " << std::setprecision(2) << std::fixed << percentOfOwnershipForPlayerTwo << " %" << std::endl;
	if (this->numberOfPlayersInGame < 3) {/* do nothing */}
	else if (this->numberOfPlayersInGame == 3) {
		temp << "Regions occupied by player three : " << std::setprecision(2) << std::fixed << percentOfOwnershipForPlayerThree << " %" << std::endl;
	}
	else if (this->numberOfPlayersInGame == 4) {
		temp << "Regions occupied by player three : " << std::setprecision(2) << std::fixed << percentOfOwnershipForPlayerThree << " %" << std::endl;
		temp << "Regions occupied by player four : " << std::setprecision(2) << std::fixed << percentOfOwnershipForPlayerFour << " %" << std::endl;
	}
	else if (this->numberOfPlayersInGame == 5) {
		temp << "Regions occupied by player three : " << std::setprecision(2) << std::fixed << percentOfOwnershipForPlayerThree << " %" << std::endl;
		temp << "Regions occupied by player four : " << std::setprecision(2) << std::fixed << percentOfOwnershipForPlayerFour << " %" << std::endl;
		temp << "Regions occupied by player five : " << std::setprecision(2) << std::fixed << percentOfOwnershipForPlayerFive << " %" << std::endl;
	}
	else {
		//throw error, invalid number of players 
	}
	temp << "Percentage of regions available for conquering : " << std::setprecision(2) << std::fixed << percentageOfFreeRegions << " %" << std::endl;
	temp << "***************************************************************************************" << std::endl;
	std::cout << temp.str();
}

void PlayerHandObserver::notifyPlayerHand(std::string playerHand){
	this->decoratorObserver->notifyPlayerHand(playerHand);

	std::stringstream temp;
	for(int i = 0; i < this->playerHands.size(); i++) {
		temp << "Player " << i + 1 << " has the hand : " << this->playerHands[i] << std::endl;
	}
	std::cout << temp.str();
}


void PlayerCoinObserver::notifyPlayerCoins(int coins) {
	this->decoratorObserver->notifyPlayerCoins(coins);

	std::stringstream temp;
	for (int i = 0; i < this->playerCoins.size(); i++) {
		temp << "Player " << i % this->numberOfPlayersInGame << " has " << this->playerCoins[i] << " coins." << std::endl;
	}
	std::cout << temp.str();
}