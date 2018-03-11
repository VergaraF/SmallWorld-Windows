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
				this->players[player]->conquers();
				
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
					this->players[player]->conquers();
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
	int firstPlayer = newGame->getFirstPlayerIndex();
	newGame->playGameLoop(firstPlayer);
}


