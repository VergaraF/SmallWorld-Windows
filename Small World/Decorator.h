#pragma once

#include "Observer.h"
#include <iomanip>


class Decorator : public Observer
{
public:
	explicit Decorator(Observer*);
	Observer* decoratorObserver;
	void notifyPlayerAction(std::string) override;
	void notifyObserverOfPlayer(int) override;
	void notifyRegionsOwned(int) override;
	void notifyNumberOfPlayersInGame(int) override;
	void notifyPlayerConquest(std::string) override;
	void notifyPlayerHand(std::string) override;
	void notifyPlayerCoins(int) override;
};

class MapOwnershipObserver : public Decorator 
{
public:
	explicit MapOwnershipObserver(Observer* obs) : Decorator(obs) {}
	void notifyRegionsOwned(int) override;
	void showCurrentMapOwnsership();
private:
	double getPercentageForPlayer(int);
};


class PlayerHandObserver : public Decorator
{
public:
	explicit PlayerHandObserver(Observer* obs) : Decorator(obs) {}
	void notifyPlayerHand(std::string) override;
};

class PlayerCoinObserver : public Decorator
{
public:
	explicit PlayerCoinObserver(Observer* obs) : Decorator(obs) {}
	void notifyPlayerCoins(int) override;
};