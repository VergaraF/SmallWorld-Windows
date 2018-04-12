#include "RandomPlayer.h"

int RandomPlayer::picks_race(std::vector<FantasyRaceBanner*> banners)
{
	this->obs->notifyPlayerAction(" [" + this->name + "] is picking a race randomly");
	std::cout << "Oponent is picking a race from the following: " << std::endl;
	std::stringstream temp;
	for (int i = 0; i < banners.size(); ++i) {
		temp << "[" << i << "] " << banners[i]->getRace()->toString() << " : " << banners[i]->getPower()->toString() << std::endl;
	}
	std::cout << temp.str() << std::endl;
	std::srand(std::time(0));
	int userInput = rand() % banners.size();
	this->fantasyRaceBanner = banners[userInput];
	std::string handStringRepresentation = banners[userInput]->getRace()->toString() + " " + banners[userInput]->getPower()->toString();
	this->obs->notifyPlayerHand(handStringRepresentation);
	return userInput; //race picked
}

Region& RandomPlayer::conquers(Region* regionConquered)
{
	this->obs->notifyPlayerAction("[" + this->name + "] conquered a region");
	regionConquered->hasBeenConquered(true);
	regionConquered->ownedBy = this->name;
	regionConquered->setTokens(0);
	regionConquered->raceTokens.clear();
	std::cout << "An random oponent conquered a region!  " << std::endl;
	int userInput = rand() % this->raceTokens.size();
	this->obs->notifyPlayerAction("[" + this->name + "] will place a random # of tokens");
	if (userInput <= this->raceTokens.size() && userInput != 0) {
		for (int i = 0; i < userInput; ++i) {
			this->raceTokens.pop_back();
			regionConquered->raceTokens.push_back(new MatchingRaceToken(this->fantasyRaceBanner->getRace()->getRaceType()));
		}
		regionConquered->setTokens(userInput);
		std::cout << userInput << " Tokens placed." << std::endl;
	}
	else {
		std::cout << "Random oponent doesn't have enough tokens to perform this action. " << "He has " << this->raceTokens.size() << " available." << std::endl;
		if (this->raceTokens.size() == 1) {
			regionConquered->raceTokens.push_back(new MatchingRaceToken(this->fantasyRaceBanner->getRace()->getRaceType()));
			this->raceTokens.pop_back();
		}
		else {
			for (int i = 0; i < this->raceTokens.size(); ++i) {
				this->raceTokens.pop_back();
				regionConquered->raceTokens.push_back(new MatchingRaceToken(this->fantasyRaceBanner->getRace()->getRaceType()));

			}
			regionConquered->setTokens(userInput);
			std::cout << "Random oponent placed his remaining tokens in this region." << std::endl;
		}
	}
	this->obs->notifyPlayerConquest("Conquered Region " + regionConquered->getIndex());
	return *regionConquered;
}

int RandomPlayer::goInDecline(std::vector<FantasyRaceBanner*> banners)
{
	this->obs->notifyRegionsOwned(this->conqueredRegions.size());
	this->obs->notifyPlayerAction(" random [" + this->name + "] is going in decline and choosing his new race");
	this->fantasyRaceBanner->setStatus(Status::DECLINE);
	this->secondFantasyRaceBanner = this->fantasyRaceBanner;
	std::cout << "Random player pics a race from the following: " << std::endl;
	std::stringstream temp;
	for (int i = 0; i < banners.size(); ++i) {
		temp << "[" << i << "] " << banners[i]->getRace()->toString() << " : " << banners[i]->getPower()->toString() << std::endl;
	}
	std::cout << temp.str() << std::endl;
	std::srand(std::time(0));
	int userInput = rand() % banners.size();
	this->fantasyRaceBanner = banners[userInput];
	banners.erase(banners.begin() + userInput);
	std::string handStringRepresentation = banners[userInput]->getRace()->toString() + " " + banners[userInput]->getPower()->toString();
	this->getObserver()->notifyPlayerHand(handStringRepresentation);
	return userInput;
}
