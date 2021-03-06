#include "MapConquerer.h"



MapConquerer::MapConquerer(GameMap* map, std::vector<Player*> players)
{
	this->gameMap = map;
	this->playersInGame = players;
}


MapConquerer::~MapConquerer()
{
}

void MapConquerer::attemptToConquerRegion(Player& playerConquering, int playerIndex, bool automated)
{
	bool indexToAvoid[80] = { false };
	int userInput;

	if (!automated) {
		std::cout << "Please enter the region index that you'd like to conquer. " << std::endl
			<< "Your map has " << this->gameMap->numberOfRegions << " to choose from" << std::endl;
		std::cin >> userInput;
		conquerRegion(userInput, playerConquering, playerIndex);
	}
	else {
		std::cout << "Oponent will enter the region index that he'd like to conquer. " << std::endl
			<< "The map has " << this->gameMap->numberOfRegions << " to choose from" << std::endl;
		std::srand(std::time(0));
		int userInput = rand() % this->gameMap->numberOfRegions;
		while (indexToAvoid[userInput - 1]){
			userInput = rand() % this->gameMap->numberOfRegions;
		}
		if (!conquerRegion(userInput - 1, playerConquering, playerIndex)) {
			indexToAvoid[userInput] = true;
		}
	}
}

bool MapConquerer::conquerRegion(int regionIndex, Player& playerConquering, int playerIndex) {
	//bool regionIsConquered;
	Graph g = *(this->gameMap->getGameMap());
	Region* reg = &g[regionIndex];
	
	bool regionIsConquered = reg->isConquered();

	if (!regionIsConquered) {
	
		if (reg->isEdge()) {
			g[regionIndex] = playerConquering.conquers(reg);
			playerConquering.conqueredRegions.emplace_back(g[regionIndex]);
			playerConquering.getObserver()->notifyRegionsOwned(playerConquering.conqueredRegions.size());
			this->playersInGame.at(playerIndex) = &playerConquering;
			this->gameMap->setGameMap(g);
			return true;
		}
		else {
			Region* tempReg;
			bool foundAdjRegion = false;
			std::vector<Region> currentRegions = playerConquering.getConqueredRegions();
			for (int i = 0; i < playerConquering.getConqueredRegions().size(); ++i){
				
				tempReg = &currentRegions[i];	
				vertex_d regToConquerDescriptor = regionIndex;
				vertex_d regConqueredByPlater = tempReg->getIndex();
				// boost::vertex(regOneDescriptor, g);
					//tempReg.getIndex();
				bool isAdj = boost::edge(regToConquerDescriptor, regConqueredByPlater, g).second;

				if (isAdj) {
					g[regionIndex] = playerConquering.conquers(reg);
					playerConquering.conqueredRegions.emplace_back(g[regionIndex]);
					this->playersInGame.at(playerIndex) = &playerConquering;
					playerConquering.getObserver()->notifyRegionsOwned(playerConquering.conqueredRegions.size());
					this->gameMap->setGameMap(g);
					//this->playersInGame.at(playerIndex)
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
			
			if ( !playerConquering.getName().compare(reg->ownedBy)){
				std::cout << "Imposible to conquer region. You already own this region" << std::endl;
				return false;
			}
			
			std::cout << "[Player " << playerConquering.getName() << "] This region is already conquered and has " << numberOfRaceTokens << " tokens on it. You will roll a dice!" << std::endl;
			int numberRolled = playerConquering.getRollingDiceFacility()->roll();
			std::cout << "The dice shows a number " << numberRolled << std::endl;
			std::cout << "You have " << playerConquering.getRaceTokens().size() << " tokens and rolled a number " << numberRolled << std::endl;
			int numberOfTokensInRegion = reg->raceTokens.size();
			if (numberOfTokensInRegion < (playerConquering.getRaceTokens().size() + numberRolled)) {
				if (reg->containsLostTribe()) {
					reg->setTribeOnRegion(false);
				}
				else {
					std::cout << "This region was owned by : " << reg->ownedBy << std::endl;
					for (int i = 0; i < this->playersInGame.size(); ++i) {
						//players->at(i)->getName().co
						if (!this->playersInGame.at(i)->getName().compare(reg->ownedBy)) {
							
							for (int j = 0; j < this->playersInGame.at(i)->conqueredRegions.size(); ++j) {
								if(this->playersInGame.at(i)->conqueredRegions.at(j).getIndex() == reg->getIndex()) {
									this->playersInGame.at(i)->conqueredRegions.erase(this->playersInGame.at(i)->conqueredRegions.begin() + j);
									break;
								}
							}
						}
					}
				}
			//	std::cout << MainGame().players.size() << std::endl;
				g[regionIndex] = playerConquering.conquers(reg);
				playerConquering.conqueredRegions.emplace_back(g[regionIndex]);
				this->playersInGame.at(playerIndex) = &playerConquering;
				playerConquering.getObserver()->notifyRegionsOwned(playerConquering.conqueredRegions.size());
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
			for (int i = 0; i < playerConquering.getConqueredRegions().size(); ++i) {
				tempReg = playerConquering.getConqueredRegions()[i];

				vertex_d regToConquerDescriptor = regionIndex;
				vertex_d regConqueredByPlater = tempReg.getIndex();
				// boost::vertex(regOneDescriptor, g);
				//tempReg.getIndex();
				bool isAdj = boost::edge(regToConquerDescriptor, regConqueredByPlater, g).second;

				if (isAdj) {
					int numberOfRaceTokens = reg->raceTokens.size();
					std::cout << "[Player " << playerConquering.getName() << "] This region is already conquered and has " << numberOfRaceTokens << " tokens on it. You will roll a dice!" << std::endl;
					int numberRolled = playerConquering.getRollingDiceFacility()->roll();
					std::cout << "The dice shows a number " << numberRolled << std::endl;
					std::cout << "You have " << playerConquering.getRaceTokens().size() << " tokens and rolled a number " << numberRolled << std::endl;
					int numberOfTokensInRegion = reg->raceTokens.size();
					if (numberOfTokensInRegion < (playerConquering.getRaceTokens().size() + numberRolled)) {
						g[regionIndex] = playerConquering.conquers(reg);
						playerConquering.conqueredRegions.emplace_back(g[regionIndex]);
						this->playersInGame.at(playerIndex) = &playerConquering;
						playerConquering.getObserver()->notifyRegionsOwned(playerConquering.conqueredRegions.size());
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

bool MapConquerer::redeployTroops(Player* playerConquering, int playerIndex, std::vector<Player*>& players)
{
	bool keepRedeploying = true;
	while (keepRedeploying) {
		std::cout << "You have " << playerConquering->getRaceTokens().size() << " tokens" << std::endl;

		std::cout << "You have the current regions conquered with the following amount of tokens on each : " << std::endl;
		for (int regionIndex = 0; regionIndex < playerConquering->conqueredRegions.size(); ++regionIndex) {
			std::cout << "[ Region : " << regionIndex << " ] Tokens : " << playerConquering->conqueredRegions[regionIndex].raceTokens.size() << std::endl;
		}

		std::cout << "If you wish to place any owned tokens in any region please press 1, otherwise press any number : " << std::endl;

		int userInput;
		std::cin >> userInput;
		bool keepDeploying = true;
		if (userInput == 1) {
			while (keepDeploying) {
				std::cout << "Enter the number of region you'd like to place your tokens : " << std::endl;
				std::cin >> userInput;
				int numberOfTokens;
				std::cout << "How many tokens do you want to deploy at that region? : " << std::endl;
				std::cin >> numberOfTokens;
				if (numberOfTokens <= playerConquering->conqueredRegions.size()) {
					for (int i = 0; i < numberOfTokens; i++) {
						playerConquering->conqueredRegions[userInput].raceTokens.push_back(new MatchingRaceToken(playerConquering->getFantasyRaceBanner()->getRace()->getRaceType()));
						playerConquering->getRaceTokens().pop_back();
					}
					std::stringstream temp;
					temp << " placed " << numberOfTokens << " on Region Index # " << playerConquering->conqueredRegions[userInput].getIndex();
					temp << std::endl << "That region now has " << playerConquering->conqueredRegions[userInput].getTokens() << " tokens.";
					playerConquering->getObserver()->notifyPlayerAction(temp.str());
				}
				else {
					std::cout << "You don't have enough tokens to perform this action, try again. " << std::endl;
				}

				std::cout << "Do you want to keep deploying tokens to your conquered regions ? Press 0 for no, otherwise enter any number " << std::endl;
				std::cin >> userInput;
				if (userInput == 0) {
					keepDeploying = false;
				}
			}
		}

		playerConquering->getObserver()->notifyPlayerAction("is redeploying some tokens ");
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
			playerConquering->conqueredRegions[regionDonor].raceTokens.pop_back();
			playerConquering->conqueredRegions[regionRecipient].raceTokens.push_back(new MatchingRaceToken(playerConquering->getFantasyRaceBanner()->getRace()->getRaceType()));
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
