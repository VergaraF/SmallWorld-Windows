#pragma once
#include "Player.h"
class ModeratePlayer :
	public Player
{
public:
	ModeratePlayer() : Player() {}
	explicit ModeratePlayer(std::string name, bool isHuman = false) : Player(name, isHuman) {}
	int picks_race(std::vector<FantasyRaceBanner*>) override;
	Region& conquers(Region*) override;
	int goInDecline(std::vector<FantasyRaceBanner*>) override;
};

