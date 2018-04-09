#pragma once
#include "Player.h"

class DefensivePlayer :
	public Player
{
public:
	DefensivePlayer() : Player() {}
	explicit DefensivePlayer(std::string name, bool isHuman = false) : Player(name, isHuman) {}
	int picks_race(std::vector<FantasyRaceBanner*>) override;
	Region& conquers(Region*) override;
	int goInDecline(std::vector<FantasyRaceBanner*>) override;
};

