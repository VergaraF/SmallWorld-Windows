#include "Deck.h"



Deck::Deck(bool init)
{
	if (init) {
		initDeck();
	}
}


Deck::~Deck()
{
}

void Deck::initDeck() {


	//Creating 14 fantasy race banners... with "NONE" race for now
	for (int banners = 0; banners < 14; ++banners) {
		this->fantasyRaceBanners.push_back(new FantasyRaceBanner(RaceType::NONE, SpecialPowerType::BLANK));
	}

	//Creating 168 Matching Race tokens & 18 Lost Tribe Tokens
	//15 amazons
	for (int amazons = 0; amazons < 15; ++amazons) {
		this->raceTokens.push_back(new MatchingRaceToken(RaceType::AMAZON));
	}
	//8 dwarves
	for (int dwarves = 0; dwarves < 8; ++dwarves) {
		this->raceTokens.push_back(new MatchingRaceToken(RaceType::DWARVES));
	}
	//11 elves
	for (int elves = 0; elves < 11; ++elves) {
		this->raceTokens.push_back(new MatchingRaceToken(RaceType::ELVES));
	}
	//10 ghouls
	for (int ghouls = 0; ghouls < 10; ++ghouls) {
		this->raceTokens.push_back(new MatchingRaceToken(RaceType::GHOULS));
	}
	//13 ratmen
	for (int ratmen = 0; ratmen < 13; ++ratmen) {
		this->raceTokens.push_back(new MatchingRaceToken(RaceType::RATMEN));
	}
	//20 skeletons
	for (int skeletons = 0; skeletons < 20; ++skeletons) {
		this->raceTokens.push_back(new MatchingRaceToken(RaceType::SKELETONS));
	}
	//18 Sorcerers
	for (int sorcerers = 0; sorcerers < 18; ++sorcerers) {
		this->raceTokens.push_back(new MatchingRaceToken(RaceType::SORCERERS));
	}
	//11 tritons
	for (int tritons = 0; tritons < 11; ++tritons) {
		this->raceTokens.push_back(new MatchingRaceToken(RaceType::TRITONS));
	}
	//11 giants
	for (int giants = 0; giants < 11; ++giants) {
		this->raceTokens.push_back(new MatchingRaceToken(RaceType::GIANTS));
	}
	//11 halflings
	for (int halflings = 0; halflings < 11; ++halflings) {
		this->raceTokens.push_back(new MatchingRaceToken(RaceType::HALFLINGS));
	}
	//10 humans
	for (int humans = 0; humans < 10; ++humans) {
		this->raceTokens.push_back(new MatchingRaceToken(RaceType::HUMANS));
	}
	//10 orcs
	for (int orcs = 0; orcs < 10; ++orcs) {
		this->raceTokens.push_back(new MatchingRaceToken(RaceType::ORCS));
	}
	//10 trolls
	for (int trolls = 0; trolls < 10; ++trolls) {
		this->raceTokens.push_back(new MatchingRaceToken(RaceType::TROLLS));
	}
	//10 wizards
	for (int wizards = 0; wizards < 10; ++wizards) {
		this->raceTokens.push_back(new MatchingRaceToken(RaceType::WIZARDS));
	}
	//18 lostTribes
	for (int lostTribes = 0; lostTribes < 18; ++lostTribes) {
		this->lostTribeTokens.push_back(new LostTribeToken());
	}

	//creating 20 unique special power badges plus 1 blank badge for a special power of your own design
	//all special power badges are blank for now
	for (int badges = 0; badges < 21; ++badges) {
		this->uniqueSpecialPowerBadges.push_back(new UniqueSpecialPowerBadge(SpecialPowerType::BLANK));
	}

	//creating special game pieces
	//10 troll lairs
	for (int trollLairs = 0; trollLairs < 10; ++trollLairs) {
		this->gamePieces.push_back(new GamePiece(GamePieceType::TROLL_LAIR));
	}
	//6 fortresses
	for (int fortres = 0; fortres < 6; ++fortres) {
		this->gamePieces.push_back(new GamePiece(GamePieceType::FORTRESS));
	}
	//9 mountains
	for (int mountain = 0; mountain < 9; ++mountain) {
		this->gamePieces.push_back(new GamePiece(GamePieceType::MOUNTAIN));
	}
	//5 encampments
	for (int encampment = 0; encampment < 5; ++encampment) {
		this->gamePieces.push_back(new GamePiece(GamePieceType::ENCAMPMENT));
	}
	//2 holes-in-the-ground
	for (int holesInTheGround = 0; holesInTheGround < 2; ++holesInTheGround) {
		this->gamePieces.push_back(new GamePiece(GamePieceType::HOLES_IN_THE_GROUND));
	}
	//2 heroes
	for (int heroe = 0; heroe < 2; ++heroe) {
		this->gamePieces.push_back(new GamePiece(GamePieceType::HEROES));
	}
	//1 dragon
	this->gamePieces.push_back(new GamePiece(GamePieceType::DRAGON));

	//Creating victory coins
	//30 "10"'s
	for (int tens = 0; tens < 30; ++tens) {
		this->coinsWithValueTen.push_back(new Coin(10));
	}
	//24 "5"'s
	for (int fives = 0; fives < 24; ++fives) {
		this->coinsWithValueFive.push_back(new Coin(5));
	}
	//20 "3"'s
	for (int threes = 0; threes < 20; ++threes) {
		this->coinsWithValueThree.push_back(new Coin(3));
	}
	//35 "1"'s
	for (int ones = 0; ones < 35; ++ones) {
		this->coinsWithValueOne.push_back(new Coin(1));
	}
}