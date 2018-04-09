#pragma once
#include "Player.h"

class RandomPlayer :
	public Player
{
public:
	RandomPlayer() : Player() {}
	explicit RandomPlayer(std::string name) : Player(name) {}
	int picks_race(std::vector<FantasyRaceBanner*>) override;
	Region& conquers(Region*) override;
	int goInDecline(std::vector<FantasyRaceBanner*>) override;
};

