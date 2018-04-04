#include "MapConquerer.h"



MapConquerer::MapConquerer(GameMap* map)
{
	this->gameMap = map;
}


MapConquerer::~MapConquerer()
{
}

void MapConquerer::attemptToConquerRegion(Player* playerConquering, int playerIndex, std::vector<Player*> players)
{
	std::cout << "Please enter the region index that you'd like to conquer. " << std::endl
		<< "Your map has " << this->gameMap->numberOfRegions << " to choose from" << std::endl;
	int userInput;
	std::cin >> userInput;
	conquerRegion(userInput, playerConquering, playerIndex, players);
}

bool MapConquerer::conquerRegion(int regionIndex, Player* playerConquering, int playerIndex, std::vector<Player*> players) {
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
				bool isAdj = boost::edge(regToConquerDescriptor, regConqueredByPlater, g).second;

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
				if (reg->containsLostTribe()) {
					reg->setTribeOnRegion(false);
				}
				else {
					std::cout << "This region was owned by : " << reg->ownedBy << std::endl;
					for (int i = 0; i < players.size(); ++i) {
						if (!players[i]->getName().compare(reg->ownedBy)) {
							for (int j = 0; j < players[i]->conqueredRegions.size(); ++j) {
								if( players[i]->conqueredRegions[j]->getIndex() == reg->getIndex()) {
									players[i]->conqueredRegions.erase(players[i]->conqueredRegions.begin() + j);
									break;
								}
							}
						}
					}
				}
			//	std::cout << MainGame().players.size() << std::endl;
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
				bool isAdj = boost::edge(regToConquerDescriptor, regConqueredByPlater, g).second;

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

bool MapConquerer::redeployTroops(Player* player)
{
	bool keepRedeploying = true;
	while (keepRedeploying) {
		std::cout << "You have the current regions conquered with the following amount of tokens on each : " << std::endl;
		for (int regionIndex = 0; regionIndex < player->conqueredRegions.size(); ++regionIndex) {
			std::cout << "[ Region : " << regionIndex << " ] Tokens : " << player->conqueredRegions[regionIndex]->raceTokens.size() << std::endl;
		}
		std::cout << "Enter the number of region you'd like to switch tokens from : " << std::endl;
		int regionDonor;
		std::cin >> regionDonor;
		std::cout << "Enter the number of tokens you'd like to move : " << std::endl;
		int numberOfTokens;
		std::cin >> numberOfTokens;
		std::cout << "You want to move " << numberOfTokens << " tokens from region # " << regionDonor << std::endl;
		std::cout << "Enter the number of the region you'd like to move your tokens TO : " << std::endl;
		int regionRecipient;
		std::cin >> regionRecipient;
		for (int i = 0; i < numberOfTokens; ++i) {
			player->conqueredRegions[regionDonor]->raceTokens.pop_back();
			player->conqueredRegions[regionRecipient]->raceTokens.push_back(new MatchingRaceToken(player->getFantasyRaceBanner()->getRace()->getRaceType()));
		}
		std::cout << "You moved " << numberOfTokens << " from region # " << regionDonor << " to region  # " << regionRecipient << std::endl;
		std::cout << "Do you want to keep redeploying troops ? Press any number of yes, 0 to stop : " << std::endl;
		int keepRedeployingDecision;
		std::cin >> keepRedeployingDecision;
		if (keepRedeployingDecision == 0) {
			keepRedeploying = false;
		}
	}
	return true;

}
