//============================================================================
// Name        : Small.cpp
// Author      : Fabian Vergara
// Version     : 1.0.0
// Copyright   : This code belongs to Fabian Vergara and is meant to be present to Dr. Nora Houari by the author itself.
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "GameMapDriver.h"
#include "MapLoader.h"
#include "Deck.h"
#include "Dice.h"

void runGameMapDriver();
void runGameMapLoader();
void runDice();
void createDeck();

int main() {
	bool testGameMapDriver = false;
	bool testGameMapLoader = false;
	bool testDiceFacility = false;
	bool createDeckFlag = true;
	
	if (testGameMapDriver){
		runGameMapDriver();
	}

	if (testGameMapLoader) {
		runGameMapLoader();
	}

	if (testDiceFacility) {
		runDice();
	}

	if (createDeckFlag) {
		createDeck();
	}
	return 0;
}

void createDeck() {
	Deck* deck = new Deck();
	
	//Creating players summary sheet, implying there are 5 players and the extra one to serve as a game turn reference for the group
	for (int players = 0; players < 6; ++players) {
		deck->summarySheets.push_back(new SummarySheet());
	}

	//Creating 14 fantasy race banners... with "NONE" race for now
	for (int banners = 0; banners < 14; ++banners) {
		deck->fantasyRaceBanners.push_back(new FantasyRaceBanner(RaceType::NONE, SpecialPowerType::BLANK));
	}

	//Creating 168 Matching Race tokens & 18 Lost Tribe Tokens
	//15 amazons
	for (int amazons = 0; amazons < 15; ++amazons) {
		deck->raceTokens.push_back(new MatchingRaceToken(RaceType::AMAZON));
	}
	//8 dwarves
	for (int dwarves = 0; dwarves < 8; ++dwarves) {
		deck->raceTokens.push_back(new MatchingRaceToken(RaceType::DWARVES));
	}
	//11 elves
	for (int elves = 0; elves < 11; ++elves) {
		deck->raceTokens.push_back(new MatchingRaceToken(RaceType::ELVES));
	}
	//10 ghouls
	for (int ghouls = 0; ghouls < 10; ++ghouls) {
		deck->raceTokens.push_back(new MatchingRaceToken(RaceType::GHOULS));
	}
	//13 ratmen
	for (int ratmen = 0; ratmen < 13; ++ratmen) {
		deck->raceTokens.push_back(new MatchingRaceToken(RaceType::RATMEN));
	}
	//20 skeletons
	for (int skeletons = 0; skeletons < 20; ++skeletons) {
		deck->raceTokens.push_back(new MatchingRaceToken(RaceType::SKELETONS));
	}
	//18 Sorcerers
	for (int sorcerers = 0; sorcerers < 18; ++sorcerers) {
		deck->raceTokens.push_back(new MatchingRaceToken(RaceType::SORCERERS));
	}
	//11 tritons
	for (int tritons = 0; tritons < 11; ++tritons) {
		deck->raceTokens.push_back(new MatchingRaceToken(RaceType::TRITONS));
	}
	//11 giants
	for (int giants = 0; giants < 11; ++giants) {
		deck->raceTokens.push_back(new MatchingRaceToken(RaceType::GIANTS));
	}
	//11 halflings
	for (int halflings = 0; halflings < 11; ++halflings) {
		deck->raceTokens.push_back(new MatchingRaceToken(RaceType::HALFLINGS));
	}
	//10 humans
	for (int humans = 0; humans < 10; ++humans) {
		deck->raceTokens.push_back(new MatchingRaceToken(RaceType::HUMANS));
	}
	//10 orcs
	for (int orcs = 0; orcs < 10; ++orcs) {
		deck->raceTokens.push_back(new MatchingRaceToken(RaceType::ORCS));
	}
	//10 trolls
	for (int trolls = 0; trolls < 10; ++trolls) {
		deck->raceTokens.push_back(new MatchingRaceToken(RaceType::TROLLS));
	}
	//10 wizards
	for (int wizards = 0; wizards < 10; ++wizards) {
		deck->raceTokens.push_back(new MatchingRaceToken(RaceType::WIZARDS));
	}
	//18 lostTribes
	for (int lostTribes = 0; lostTribes < 18; ++lostTribes) {
		deck->lostTribeTokens.push_back(new LostTribeToken());
	}

	//creating 20 unique special power badges plus 1 blank badge for a special power of your own design
	//all special power badges are blank for now
	for (int badges = 0; badges < 21; ++badges) {
		deck->uniqueSpecialPowerBadges.push_back(new UniqueSpecialPowerBadge(SpecialPowerType::BLANK));
	}

	//creating special game pieces
	//10 troll lairs
	for (int trollLairs = 0; trollLairs < 10; ++trollLairs) {
		deck->gamePieces.push_back(new GamePiece(GamePieceType::TROLL_LAIR));
	}
	//6 fortresses
	for (int fortres = 0; fortres < 6; ++fortres) {
		deck->gamePieces.push_back(new GamePiece(GamePieceType::FORTRESS));
	}
	//9 mountains
	for (int mountain = 0; mountain < 9; ++mountain) {
		deck->gamePieces.push_back(new GamePiece(GamePieceType::MOUNTAIN));
	}
	//5 encampments
	for (int encampment = 0; encampment < 5; ++encampment) {
		deck->gamePieces.push_back(new GamePiece(GamePieceType::ENCAMPMENT));
	}
	//2 holes-in-the-ground
	for (int holesInTheGround = 0; holesInTheGround < 2; ++holesInTheGround) {
		deck->gamePieces.push_back(new GamePiece(GamePieceType::HOLES_IN_THE_GROUND));
	}
	//2 heroes
	for (int heroe = 0; heroe < 2; ++heroe) {
		deck->gamePieces.push_back(new GamePiece(GamePieceType::HEROES));
	}
	//1 dragon
	deck->gamePieces.push_back(new GamePiece(GamePieceType::DRAGON));

	//Creating victory coins
	//30 "10"'s
	for (int tens = 0; tens < 30; ++tens) {
		deck->coinsWithValueTen.push_back(new Coin(10));
	}
	//24 "5"'s
	for (int fives = 0; fives < 24; ++fives) {
		deck->coinsWithValueFive.push_back(new Coin(5));
	}
	//20 "3"'s
	for (int threes = 0; threes < 20; ++threes) {
		deck->coinsWithValueThree.push_back(new Coin(3));
	}
	//35 "1"'s
	for (int ones = 0; ones < 35; ++ones) {
		deck->coinsWithValueOne.push_back(new Coin(1));
	}

}

void runDice() {
	Dice* dice = new Dice();
	dice->roll();

	for (unsigned int i = 0; i < 100; ++i) {
		dice->roll();	
	}
	std::cout << dice->getStatistics() << std::endl;
}

void runGameMapLoader() {
	MapLoader* gameMapLoader = new MapLoader();
	GameMap gameMap = gameMapLoader->readFile("./MapFileForTwoPlayers.txt");

}
void runGameMapDriver() {
	GameMapDriver* gameMapDriver = new GameMapDriver();
	int players = 0;
	//gameMapDriver->createGameMapForNumberOfPlayers(2);
	std::cout << "How many players are going to play the game? Insert a numeric value from 2 to 5  : ";
	std::cin >> players;

	switch (players) {
	case 2: {
		gameMapDriver->createGameMapForNumberOfPlayers(2);
		break;
	}
	case 3: {
		gameMapDriver->createGameMapForNumberOfPlayers(3);
		break;
	}
	case 4: {
		gameMapDriver->createGameMapForNumberOfPlayers(4);
		break;
	}
	case 5: {
		gameMapDriver->createGameMapForNumberOfPlayers(5);
		break;
	}
	default: std::cout << "Invalid number of players" << std::endl;;
		break;
	}
	int i;
	std::cin >> i;
}
