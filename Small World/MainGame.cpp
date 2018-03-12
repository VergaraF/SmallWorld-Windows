#include "MainGame.h"

MainGame::MainGame()
{
	currentGameTurnPosition = 0;
	firstPlayer = 0;
	this->startUp = new StartUp();
	this->players = this->startUp->getPlayers();
	int numberOfRegions = this->startUp->getGameMap()->numberOfRegions;
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
	this->mapConquerer = new MapConquerer(this->startUp->getGameMap());

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
				players[player]->getRaceTokens().push_back(new MatchingRaceToken(RaceType::ELVES));
				//this->startUp->getDeck().
				//TODO REMOVE TOKENS FROM DECK. Implement different race tokens stack as for now they are all combined
			}

			break;
		}
		case RaceType::ORCS: {
			numberOfCoinsToGive = 5;
			for (int i = 0; i < numberOfCoinsToGive; ++i) {
				players[player]->getRaceTokens().push_back(new MatchingRaceToken(RaceType::ORCS));
				//this->startUp->getDeck().
				//TODO REMOVE TOKENS FROM DECK. Implement different race tokens stack as for now they are all combined
			}

			break;
		}
		case RaceType::RATMEN: {
			numberOfCoinsToGive = 8;
			for (int i = 0; i < numberOfCoinsToGive; ++i) {
				players[player]->getRaceTokens().push_back(new MatchingRaceToken(RaceType::RATMEN));
				//this->startUp->getDeck().
				//TODO REMOVE TOKENS FROM DECK. Implement different race tokens stack as for now they are all combined
			}

			break;
		}
		case RaceType::TROLLS: {
			numberOfCoinsToGive = 5;
			for (int i = 0; i < numberOfCoinsToGive; ++i) {
				players[player]->getRaceTokens().push_back(new MatchingRaceToken(RaceType::TROLLS));
				//this->startUp->getDeck().
				//TODO REMOVE TOKENS FROM DECK. Implement different race tokens stack as for now they are all combined
			}

			break;
		}
		case RaceType::HALFLINGS: {
			numberOfCoinsToGive = 6;
			for (int i = 0; i < numberOfCoinsToGive; ++i) {
				players[player]->getRaceTokens().push_back(new MatchingRaceToken(RaceType::HALFLINGS));
				//this->startUp->getDeck().
				//TODO REMOVE TOKENS FROM DECK. Implement different race tokens stack as for now they are all combined
			}

			break;
		}
		case RaceType::WIZARDS: {
			numberOfCoinsToGive = 5;
			for (int i = 0; i < numberOfCoinsToGive; ++i) {
				players[player]->getRaceTokens().push_back(new MatchingRaceToken(RaceType::WIZARDS));
				//this->startUp->getDeck().
				//TODO REMOVE TOKENS FROM DECK. Implement different race tokens stack as for now they are all combined
			}

			break;
		}
		case RaceType::AMAZON: {
			numberOfCoinsToGive = 6;
			for (int i = 0; i < numberOfCoinsToGive; ++i) {
				players[player]->getRaceTokens().push_back(new MatchingRaceToken(RaceType::AMAZON));
				//this->startUp->getDeck().
				//TODO REMOVE TOKENS FROM DECK. Implement different race tokens stack as for now they are all combined
			}

			break;
		}
		case RaceType::SORCERERS: {
			numberOfCoinsToGive = 5;
			for (int i = 0; i < numberOfCoinsToGive; ++i) {
				players[player]->getRaceTokens().push_back(new MatchingRaceToken(RaceType::SORCERERS));
				//this->startUp->getDeck().
				//TODO REMOVE TOKENS FROM DECK. Implement different race tokens stack as for now they are all combined
			}

			break;
		}
		case RaceType::DWARVES: {
			numberOfCoinsToGive = 3;
			for (int i = 0; i < numberOfCoinsToGive; ++i) {
				players[player]->getRaceTokens().push_back(new MatchingRaceToken(RaceType::DWARVES));
				//this->startUp->getDeck().
				//TODO REMOVE TOKENS FROM DECK. Implement different race tokens stack as for now they are all combined
			}

			break;
		}
		case RaceType::GHOULS: {
			numberOfCoinsToGive = 5;
			for (int i = 0; i < numberOfCoinsToGive; ++i) {
				players[player]->getRaceTokens().push_back(new MatchingRaceToken(RaceType::GHOULS));
				//this->startUp->getDeck().
				//TODO REMOVE TOKENS FROM DECK. Implement different race tokens stack as for now they are all combined
			}

			break;
		}
		case RaceType::TRITONS: {
			numberOfCoinsToGive = 6;
			for (int i = 0; i < numberOfCoinsToGive; ++i) {
				players[player]->getRaceTokens().push_back(new MatchingRaceToken(RaceType::TRITONS));
				//this->startUp->getDeck().
				//TODO REMOVE TOKENS FROM DECK. Implement different race tokens stack as for now they are all combined
			}

			break;
		}
		case RaceType::GIANTS: {
			numberOfCoinsToGive = 6;
			for (int i = 0; i < numberOfCoinsToGive; ++i) {
				players[player]->getRaceTokens().push_back(new MatchingRaceToken(RaceType::GIANTS));
				//this->startUp->getDeck().
				//TODO REMOVE TOKENS FROM DECK. Implement different race tokens stack as for now they are all combined
			}

			break;
		}
		case RaceType::HUMANS: {
			numberOfCoinsToGive = 5;
			for (int i = 0; i < numberOfCoinsToGive; ++i) {
				players[player]->getRaceTokens().push_back(new MatchingRaceToken(RaceType::HUMANS));
				//this->startUp->getDeck().
				//TODO REMOVE TOKENS FROM DECK. Implement different race tokens stack as for now they are all combined
			}

			break;
		}
		case RaceType::SKELETONS: {
			numberOfCoinsToGive = 6;
			for (int i = 0; i < numberOfCoinsToGive; ++i) {
				players[player]->getRaceTokens().push_back(new MatchingRaceToken(RaceType::SKELETONS));
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

	bool isFirstTurn = true;
	int count = 0;
	while (this->currentGameTurnPosition <= this->gameTurnRack) {
		for (int player = startPlayerIndex; player < this->players.size(); ++player) {
			std::cout << "Player [ " << player << "] turn # " << currentGameTurnPosition << std::endl;

			if (player == startPlayerIndex) {
				this->currentGameTurnPosition++;
				count++;
			}

			if (isFirstTurn) {
				mapConquerer->attemptToConquerRegion(this->players[player]);
				//this->players[player]->conquers();

			}
			else {
				std::cout << "Player [ " << player << "] Do you want to go IN DECLINE, or keep conquering? Type 1 for decline or 0 for conquering " << std::endl;
				int userInput;
				std::cin >> userInput;
				if (userInput == 1) {
					int indexOfRaceBannerChose = this->players[player]->goInDecline(racesAvailable);
					//[TODO] FIX: known bug, it may still give races that were given already
					//racesAvailable = this->startUp->getRaceBannersFromDeck(this->startUp->takenRaces, this->startUp->takenSpecialPowers);
					racesAvailable = this->startUp->getRaceBannersFromDeck();
				}
				else if (userInput == 0) {
					mapConquerer->attemptToConquerRegion(this->players[player]);
				}
				else {
					std::cout << "Invalid entry." << std::endl;
				}
			}

			this->players[player]->scores();

			if (count > 1) {
				isFirstTurn = false;
			}
			if (player % this->players.size() - 1 == 0) {
				player = 0;
			}

		}
	}
	std::cout << "The game has finished! Winner is : " << "[Place_Holder]";
}


int main() {
	MainGame* newGame = new MainGame();

	newGame->letPlayersChooseRace();
	newGame->assignRaceTokenPerPlayer();
	int firstPlayer = newGame->getFirstPlayerIndex();
	newGame->playGameLoop(firstPlayer);
}


