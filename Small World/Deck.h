#pragma once
#include<vector>
#include "FantasyRaceBanner.h"
#include "MatchingRaceToken.h"
#include "LostTribeToken.h"
#include "UniqueSpecialPowerBadge.h"
#include "GamePiece.h"
#include "Coin.h"
#include "SummarySheet.h"
class Deck
{
public:
	Deck(bool);
	~Deck();
	std::vector<FantasyRaceBanner*> fantasyRaceBanners;
	std::vector<MatchingRaceToken*> raceTokens;
	std::vector<LostTribeToken*> lostTribeTokens;
	std::vector<UniqueSpecialPowerBadge*> uniqueSpecialPowerBadges;
	std::vector<GamePiece*> gamePieces;
	std::vector<Coin*> coinsWithValueTen;
	std::vector<Coin*> coinsWithValueFive;
	std::vector<Coin*> coinsWithValueThree;
	std::vector<Coin*> coinsWithValueOne;
	std::vector<SummarySheet*> summarySheets;
private:
	void initDeck();

};

