#include "MapConquerer.h"



MapConquerer::MapConquerer(GameMap* map)
{
	this->gameMap = map;
}


MapConquerer::~MapConquerer()
{
}

void MapConquerer::attemptToConquerRegion(Player* playerConquering)
{
	std::cout << "Please enter the region index that you'd like to conquer. " << std::endl
		<< "Your map has " << this->gameMap->numberOfRegions << " to choose from" << std::endl;
	int userInput;
	std::cin >> userInput;
	conquerRegion(userInput, playerConquering);
}

bool MapConquerer::conquerRegion(int regionIndex, Player* playerConquering) {
	//bool regionIsConquered;
	Graph g = *(this->gameMap->getGameMap());
	Region* reg = &g[regionIndex];
	
	bool regionIsConquered = reg->isConquered();

	if (!regionIsConquered) {
	
		if (reg->isEdge()) {
			playerConquering->conquers(reg);
		}
		else {
			//TODO: check if region is adj to any region owned by player
		}
	}
	else {
		int numberOfRaceTokens = reg->raceTokens.size();
		std::cout << "[Player " << playerConquering->getName() << "] This region is already conquered and has "<< numberOfRaceTokens << " tokens on it. You will roll a dice!" << std::endl;
		int numberRolled = playerConquering->getRollingDiceFacility()->roll();
		std::cout << "The dice shows a number " << numberRolled << std::endl;
		std::cout << "You have " << playerConquering->getRaceTokens().size() << " tokens and rolled a number " << numberRolled << std::endl;
		int numberOfTokensInRegion = reg->raceTokens.size();
		if (numberOfTokensInRegion < (playerConquering->getRaceTokens().size() + numberRolled)) {
			playerConquering->conquers(reg);
		}
		else {
			std::cout << "Impossible to conquer region. " << std::endl;
		}
	}
	return true;
}
