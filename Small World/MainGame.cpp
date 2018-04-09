#include "MainGame.h"

MainGame::MainGame()
{
	currentGameTurnPosition = 0;
	firstPlayer = 0;
	this->startUp = new StartUp();
	this->players = this->startUp->getPlayers();
	int numberOfRegions = this->startUp->getGameMap()->numberOfRegions;
	this->tokensGrantedAtEveryTurn = 6;

	switch (numberOfRegions) {
	case((int)Regions::FOR_TWO_PLAYERS): {
		this->gameTurnRack = (int)GameTurnRack::EIGHT;
		break;
	}
	case ((int)Regions::FOR_THREE_PLAYERS): {
		this->gameTurnRack = (int)GameTurnRack::NINETH;
		break;
	}
	case ((int)Regions::FOR_FOUR_PLAYERS): {
		this->gameTurnRack = (int)GameTurnRack::TENTH;
		break;
	}
	case ((int)Regions::FOR_FIVE_PLAYERS): {
		this->gameTurnRack = (int)GameTurnRack::TENTH;
		break;
	}
	}
	this->mapConquerer = this->startUp->mapConquerer;

}


MainGame::~MainGame()
{
}

void MainGame::letPlayersChooseRace()
{
	std::vector<FantasyRaceBanner*> temp;
	//this->startUp->getRaceBannersFromDeck(racesToAvoid, powersToAvoid);
	this->startUp->getRaceBannersFromDeck();
	std::vector<FantasyRaceBanner*> racesAvailable = this->startUp->raceBanners;

	for (int player = 0; player < this->players.size(); ++player) {
		int indexOfRaceBannerChose = this->players[player]->picks_race(racesAvailable);
		racesToAvoid.push_back((int)this->players[player]->getFantasyRaceBanner()->getRace()->getRaceType());
		powersToAvoid.push_back((int)this->players[player]->getFantasyRaceBanner()->getPower()->getType());
		for (int raceIndex = 0; raceIndex < racesAvailable.size(); ++raceIndex) {

			if (indexOfRaceBannerChose != raceIndex) {
				temp.push_back(racesAvailable[raceIndex]);
			}
		}
		racesAvailable = temp;
		temp.clear();
		//this->startUp->getRaceBannersFromDeck(racesToAvoid, powersToAvoid);
	}
}

int MainGame::getFirstPlayerIndex() {
	return this->startUp->getStartingPlayer();
}

void MainGame::assignRaceTokenPerPlayer()
{
	int numberOfCoinsToGive = 0;
	for (int player = 0; player < this->players.size(); ++player) {
		switch (players[player]->getFantasyRaceBanner()->getRace()->getRaceType()) {

		case RaceType::ELVES: {
			numberOfCoinsToGive = 6;
			for (int i = 0; i < numberOfCoinsToGive; ++i) {
				players[player]->giveRaceTokens(RaceType::ELVES);
				//this->startUp->getDeck().
				//TODO REMOVE TOKENS FROM DECK. Implement different race tokens stack as for now they are all combined
			}

			break;
		}
		case RaceType::ORCS: {
			numberOfCoinsToGive = 5;
			for (int i = 0; i < numberOfCoinsToGive; ++i) {
				players[player]->giveRaceTokens(RaceType::ORCS);
				//this->startUp->getDeck().
				//TODO REMOVE TOKENS FROM DECK. Implement different race tokens stack as for now they are all combined
			}

			break;
		}
		case RaceType::RATMEN: {
			numberOfCoinsToGive = 8;
			for (int i = 0; i < numberOfCoinsToGive; ++i) {
				players[player]->giveRaceTokens(RaceType::RATMEN);
				//this->startUp->getDeck().
				//TODO REMOVE TOKENS FROM DECK. Implement different race tokens stack as for now they are all combined
			}

			break;
		}
		case RaceType::TROLLS: {
			numberOfCoinsToGive = 5;
			for (int i = 0; i < numberOfCoinsToGive; ++i) {
				players[player]->giveRaceTokens(RaceType::TROLLS);
				//this->startUp->getDeck().
				//TODO REMOVE TOKENS FROM DECK. Implement different race tokens stack as for now they are all combined
			}

			break;
		}
		case RaceType::HALFLINGS: {
			numberOfCoinsToGive = 6;
			for (int i = 0; i < numberOfCoinsToGive; ++i) {
				players[player]->giveRaceTokens(RaceType::HALFLINGS);
				//this->startUp->getDeck().
				//TODO REMOVE TOKENS FROM DECK. Implement different race tokens stack as for now they are all combined
			}

			break;
		}
		case RaceType::WIZARDS: {
			numberOfCoinsToGive = 5;
			for (int i = 0; i < numberOfCoinsToGive; ++i) {
				//players[player]->getRaceTokens().push_back(new MatchingRaceToken(RaceType::WIZARDS));
				players[player]->giveRaceTokens(RaceType::WIZARDS);
				//this->startUp->getDeck().
				//TODO REMOVE TOKENS FROM DECK. Implement different race tokens stack as for now they are all combined
			}

			break;
		}
		case RaceType::AMAZON: {
			numberOfCoinsToGive = 6;
			for (int i = 0; i < numberOfCoinsToGive; ++i) {
				players[player]->giveRaceTokens(RaceType::AMAZON);
				//this->startUp->getDeck().
				//TODO REMOVE TOKENS FROM DECK. Implement different race tokens stack as for now they are all combined
			}

			break;
		}
		case RaceType::SORCERERS: {
			numberOfCoinsToGive = 5;
			for (int i = 0; i < numberOfCoinsToGive; ++i) {
				players[player]->giveRaceTokens(RaceType::SORCERERS);
				//this->startUp->getDeck().
				//TODO REMOVE TOKENS FROM DECK. Implement different race tokens stack as for now they are all combined
			}

			break;
		}
		case RaceType::DWARVES: {
			numberOfCoinsToGive = 3;
			for (int i = 0; i < numberOfCoinsToGive; ++i) {
				players[player]->giveRaceTokens(RaceType::DWARVES);
				//this->startUp->getDeck().
				//TODO REMOVE TOKENS FROM DECK. Implement different race tokens stack as for now they are all combined
			}

			break;
		}
		case RaceType::GHOULS: {
			numberOfCoinsToGive = 5;
			for (int i = 0; i < numberOfCoinsToGive; ++i) {
				players[player]->giveRaceTokens(RaceType::GHOULS);
				//this->startUp->getDeck().
				//TODO REMOVE TOKENS FROM DECK. Implement different race tokens stack as for now they are all combined
			}

			break;
		}
		case RaceType::TRITONS: {
			numberOfCoinsToGive = 6;
			for (int i = 0; i < numberOfCoinsToGive; ++i) {
				players[player]->giveRaceTokens(RaceType::TRITONS);
				//this->startUp->getDeck().
				//TODO REMOVE TOKENS FROM DECK. Implement different race tokens stack as for now they are all combined
			}

			break;
		}
		case RaceType::GIANTS: {
			numberOfCoinsToGive = 6;
			for (int i = 0; i < numberOfCoinsToGive; ++i) {
				players[player]->giveRaceTokens(RaceType::GIANTS);
				//this->startUp->getDeck().
				//TODO REMOVE TOKENS FROM DECK. Implement different race tokens stack as for now they are all combined
			}

			break;
		}
		case RaceType::HUMANS: {
			numberOfCoinsToGive = 5;
			for (int i = 0; i < numberOfCoinsToGive; ++i) {
				players[player]->giveRaceTokens(RaceType::HUMANS);
				//this->startUp->getDeck().
				//TODO REMOVE TOKENS FROM DECK. Implement different race tokens stack as for now they are all combined
			}

			break;
		}
		case RaceType::SKELETONS: {
			numberOfCoinsToGive = 6;
			for (int i = 0; i < numberOfCoinsToGive; ++i) {
				players[player]->giveRaceTokens(RaceType::SKELETONS);
				//this->startUp->getDeck().
				//TODO REMOVE TOKENS FROM DECK. Implement different race tokens stack as for now they are all combined
			}
			break;
		}

		}
	}
}

void MainGame::playGameLoop(int startPlayerIndex) {
	std::vector<FantasyRaceBanner*> racesAvailable = this->startUp->raceBanners;
	bool keepConquering = true;
	bool isFirstTurn = true;
	int count = 0;
	int player = startPlayerIndex;
	int playerCount = 1;
	bool playerNotified[5] = { false, false, false, false, false};
	gameObserver.notifyNumberOfPlayersInGame(this->players.size());
	while (this->currentGameTurnPosition < this->gameTurnRack) {
		mapConquerer->playersInGame = this->players;

		while (player < this->players.size()) {
			keepConquering = true;
			if (!playerNotified[playerCount - 1]) {
				if (playerCount <= this->players.size()) {
					this->players[player]->getObserver()->notifyObserverOfPlayer(playerCount);
					playerNotified[playerCount - 1] = true;
					playerCount++;
				}
			}
			if (player == startPlayerIndex && !isFirstTurn) {
				this->currentGameTurnPosition++;
			}
			std::cout << "Player [ on chair # " << player << " : " << this->players[player]->getName() << "] turn # " << currentGameTurnPosition << std::endl;
			count++;
			this->players[player]->selectObserver();

			if (isFirstTurn) {			
				while (keepConquering) {
					mapConquerer->attemptToConquerRegion(*(this->players[player]), player);
					this->players = mapConquerer->playersInGame;
					if (this->players[player]->getRaceTokens().size() > 0) {
 						std::cout << "Player [ on chair # " << player << " : " << this->players[player]->getName() << "] Do you want to keep conquering? Type 1 for yes or 0 for no " << std::endl;
						int userInput;
						std::cin >> userInput;
						if (userInput == 0) {
							keepConquering = false;
						}
					}
					else {
						std::cout << "Player [ on chair # " << player << " : " << this->players[player]->getName() << "] You don't have more tokens to keep conquering at the moment " << std::endl;
						keepConquering = false;
					}
				}
			}
			else {
				//give every player 6 new tokens on every turn
				
				this->players[player]->getObserver()->notifyPlayerAction(" has been awarded with # of tokens : " + this->tokensGrantedAtEveryTurn);
				for (int i = 0; i < 6; i++) {
					this->players[player]->giveRaceTokens(this->players[player]->getFantasyRaceBanner()->getRace()->getRaceType());
				}
				int dontDoAnything;
				std::cout << "Player [ on chair # " << player << " : " << this->players[player]->getName() << "] If you DO NOT want to conquer or go in decline, type 0. Otherwise, press any number. " << std::endl;
				std::cin >> dontDoAnything;
				if (dontDoAnything != 0) {
					std::cout << "Player [ on chair # " << player << " : " << this->players[player]->getName() << "] Do you want to go IN DECLINE, or keep conquering? Type 1 for decline or 0 for conquering " << std::endl;
					int userInput;
					std::cin >> userInput;
					if (userInput == 1) {
						int indexOfRaceBannerChose = this->players[player]->goInDecline(racesAvailable);
						racesAvailable = this->startUp->getRaceBannersFromDeck();
					}
					else if (userInput == 0) {
						while (keepConquering) {
							mapConquerer->attemptToConquerRegion(*this->players[player], player);
							this->players = mapConquerer->playersInGame;
							if (this->players[player]->getRaceTokens().size() > 0) {
								std::cout << "Player [ on chair # " << player << " : " << this->players[player]->getName() << "] Do you want to keep conquering? Type 1 for yes or 0 for no " << std::endl;
								int userInput;
								std::cin >> userInput;
								if (userInput == 0) {
									keepConquering = false;
								}
							}
							else {
								std::cout << "Player [ on chair # " << player << " : " << this->players[player]->getName() << "] You don't have more tokens to keep conquering at the moment " << std::endl;
								keepConquering = false;
							}
						}
					}
					else {
						std::cout << "Invalid entry." << std::endl;
					}
				}
			}		
			std::cout << "You can't conquer more regions at the moment or you chose not to. Do you want to redeploy (or deploy troops to your existing regions) your troops ? press 1 for yes, 0 for no" << std::endl;
			int userInput;
			std::cin >> userInput;
			if (userInput == 1) {
				mapConquerer->redeployTroops(this->players[player], player, this->players);
			}
			int currentScore = this->players[player]->scores();
			std::cout << "Player [ on chair # " << player << " : " << this->players[player]->getName() << "] has scored " <<  std::endl;

			if (count > 1) {
				isFirstTurn = false;
			}
			
			if (player % this->players.size() - 1 == 0) {
				player = 0;
			}
			else {
				player++;
			}
		}
	}
	std::cout << "The game has finished! Winner is : " << "[Place_Holder]" << std::endl;
}


int main() {
	MainGame* newGame = new MainGame();

	newGame->letPlayersChooseRace();
	newGame->assignRaceTokenPerPlayer();
	int firstPlayer = newGame->getFirstPlayerIndex();
	newGame->playGameLoop(firstPlayer);
}


