#include "ModeratePlayer.h"

int ModeratePlayer::picks_race(std::vector<FantasyRaceBanner*> banners)
{
	this->obs->notifyPlayerAction(" [" + this->name + "] is picking a race randomly");
	std::cout << "A Moderate oponent is picking a race from the following: " << std::endl;
	std::stringstream temp;
	for (int i = 0; i < banners.size(); ++i) {
		temp << "[" << i << "] " << banners[i]->getRace()->toString() << " : " << banners[i]->getPower()->toString() << std::endl;
	}
	std::cout << temp.str() << std::endl;
	std::srand(std::time(0));
	int userInput = rand() % banners.size();
	this->fantasyRaceBanner = banners[userInput - 1];
	std::string handStringRepresentation = banners[userInput]->getRace()->toString() + " " + banners[userInput]->getPower()->toString();
	this->obs->notifyPlayerHand(handStringRepresentation);
	return userInput; //race picked
}

Region& ModeratePlayer::conquers(Region* regionConquered)
{
	this->obs->notifyPlayerAction("[" + this->name + "] conquered a region");
	regionConquered->hasBeenConquered(true);
	regionConquered->ownedBy = this->name;
	regionConquered->setTokens(0);
	regionConquered->raceTokens.clear();
	std::cout << "A Moderate oponent conquered a region!  " << std::endl;
	this->obs->notifyPlayerAction("[" + this->name + "] will place all his token in the same region to avoid lose it");

	for (int i = 0; i < this->raceTokens.size() - 2; ++i) {
		this->raceTokens.pop_back();
		regionConquered->raceTokens.push_back(new MatchingRaceToken(this->fantasyRaceBanner->getRace()->getRaceType()));
	}
	regionConquered->setTokens(this->raceTokens.size() - 2);
	std::cout << this->raceTokens.size() - 2 << " Tokens placed." << std::endl;


	this->obs->notifyPlayerConquest("Conquered Region " + regionConquered->getIndex());
	return *regionConquered;
}

int ModeratePlayer::goInDecline(std::vector<FantasyRaceBanner*> banners)
{
	this->obs->notifyRegionsOwned(this->conqueredRegions.size());
	this->obs->notifyPlayerAction("Moderate [" + this->name + "] is going in decline and choosing his new race");
	this->fantasyRaceBanner->setStatus(Status::DECLINE);
	this->secondFantasyRaceBanner = this->fantasyRaceBanner;
	std::cout << "Moderate player pics a race from the following: " << std::endl;
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
