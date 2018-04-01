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
			g[regionIndex] = playerConquering->conquers(reg);
			this->gameMap->setGameMap(g);
		
		}
		else {
			Region* tempReg;
			bool foundAdjRegion = false;
			std::vector<Region*> currentRegions = playerConquering->getConqueredRegions();
			for (int i = 0; i < playerConquering->getConqueredRegions().size(); ++i){
				
				tempReg = currentRegions[i];
				
				vertex_d regToConquerDescriptor = regionIndex;
				vertex_d regConqueredByPlater = tempReg->getIndex();
				// boost::vertex(regOneDescriptor, g);
					//tempReg.getIndex();
				bool isAdj = boost::edge(boost::vertex(regToConquerDescriptor, g), boost::vertex(regConqueredByPlater, g), g).second;
			
				if (isAdj) {
					g[regionIndex] = playerConquering->conquers(reg);
					this->gameMap->setGameMap(g);
					foundAdjRegion = isAdj;
					return true;
				}
			}

			if (!foundAdjRegion) {
				std::cout << "The region you are trying to conquer is NOT an edge nor connected to any of you regions." << std::endl;
				return false;
			}
		}
	}
	else {
		if (reg->isEdge()) {
			int numberOfRaceTokens = reg->raceTokens.size();
			
			if ( !playerConquering->getName().compare(reg->ownedBy)){
				std::cout << "Imposible to conquer region. You already own this region" << std::endl;
				return false;
			}
			std::cout << "[Player " << playerConquering->getName() << "] This region is already conquered and has " << numberOfRaceTokens << " tokens on it. You will roll a dice!" << std::endl;
			int numberRolled = playerConquering->getRollingDiceFacility()->roll();
			std::cout << "The dice shows a number " << numberRolled << std::endl;
			std::cout << "You have " << playerConquering->getRaceTokens().size() << " tokens and rolled a number " << numberRolled << std::endl;
			int numberOfTokensInRegion = reg->raceTokens.size();
			if (numberOfTokensInRegion < (playerConquering->getRaceTokens().size() + numberRolled)) {
				g[regionIndex] = playerConquering->conquers(reg);
				this->gameMap->setGameMap(g);
				return true;
			}
			else {
				std::cout << "Impossible to conquer region. " << std::endl;
				return false;
			}
		}
		else {
			Region tempReg;
			bool foundAdjRegion = false;
			for (int i = 0; i < playerConquering->getConqueredRegions().size(); ++i) {
				tempReg = *(playerConquering->getConqueredRegions()[i]);

				vertex_d regToConquerDescriptor = regionIndex;
				vertex_d regConqueredByPlater = tempReg.getIndex();
				// boost::vertex(regOneDescriptor, g);
				//tempReg.getIndex();
				bool isAdj = boost::edge(boost::vertex(regToConquerDescriptor, g), boost::vertex(regConqueredByPlater, g), g).second;

				if (isAdj) {
					int numberOfRaceTokens = reg->raceTokens.size();
					std::cout << "[Player " << playerConquering->getName() << "] This region is already conquered and has " << numberOfRaceTokens << " tokens on it. You will roll a dice!" << std::endl;
					int numberRolled = playerConquering->getRollingDiceFacility()->roll();
					std::cout << "The dice shows a number " << numberRolled << std::endl;
					std::cout << "You have " << playerConquering->getRaceTokens().size() << " tokens and rolled a number " << numberRolled << std::endl;
					int numberOfTokensInRegion = reg->raceTokens.size();
					if (numberOfTokensInRegion < (playerConquering->getRaceTokens().size() + numberRolled)) {
						g[regionIndex] = playerConquering->conquers(reg);
						this->gameMap->setGameMap(g);
						
					}
					else {
						std::cout << "Impossible to conquer region. " << std::endl;
						return false;
					}
					foundAdjRegion = isAdj;
					return true;
				}
			}

			if (!foundAdjRegion) {
				std::cout << "The region you are trying to conquer is NOT an edge nor connected to any of you regions." << std::endl;
				return false;
			}
		}
		
	}
	this->gameMap->setGameMap(g);
	return true;
}

bool MapConquerer::redeployTroops(Player *)
{
	//TODO Redeploy troops implementation
	return true;

}
