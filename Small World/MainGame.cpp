#include "MainGame.h"

MainGame::MainGame()
{
	currentGameTurnPosition = 0;
	firstPlayer = 0;
	this->startUp = new StartUp();
	this->players = this->startUp->getPlayers();
}


MainGame::~MainGame()
{
}

void MainGame::letPlayersChooseRace()
{
	std::vector<FantasyRaceBanner*> racesAvailable = this->startUp->raceBanners;
	std::vector<FantasyRaceBanner*> temp;
	for (int player = 0; player < this->players.size(); ++player) {
		int indexOfRaceBannerChose = this->players[player]->picks_race(racesAvailable);
		for (int raceIndex = 0; raceIndex < racesAvailable.size(); ++raceIndex) {
			
			if (indexOfRaceBannerChose != raceIndex) {
				temp.push_back(racesAvailable[raceIndex]);
			}
		}
		racesAvailable = temp;
		temp.clear();
	}
} 

int MainGame::getFirstPlayerIndex() {
	return this->startUp->getStartingPlayer();
}



int main() {
	MainGame* newGame = new MainGame();

	newGame->letPlayersChooseRace();
	int firstPlayer = newGame->getFirstPlayerIndex();

}


