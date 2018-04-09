#pragma once
#include "Player.h"
class AggressivePlayer :
	public Player
{
public:
	AggressivePlayer() : Player() {}
	explicit AggressivePlayer(std::string name, bool isHuman = false) : Player(name, isHuman) {}
	int picks_race(std::vector<FantasyRaceBanner*>) override;
	Region& conquers(Region*) override;
	int goInDecline(std::vector<FantasyRaceBanner*>) override;
};

