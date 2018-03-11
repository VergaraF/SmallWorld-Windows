#include "StartPlug.h"

StartPlug::StartPlug(){}
StartPlug::~StartPlug(){}

void StartPlug::loadMap()
{
	MapLoader* mapLoader = new MapLoader();
	std::cout << "Please enter the number corresponding to the file map you want to load" << std::endl;
	std::string path = "./Maps";
	std::stringstream temp;
	std::stringstream tempFilename;
	int count = 0;

	std::vector<std::string> fileName;
	for (auto p : fs::directory_iterator(path)) {
		//fileName.push_back(p));
		tempFilename << p;
		fileName.push_back(tempFilename.str());
		tempFilename.str(std::string());
		temp << "[" << count << "] " << p << std::endl;
		count++;
	}
	std::cout << temp.str() << std::endl;

	int userResponse;
	std::cin >> userResponse;

	if (userResponse > fileName.size() || userResponse < 0) {
		std::cout << "Invalid entry, there's no such map file." << std::endl;
		return;
	}

	GameMap gameMap = mapLoader->readFile(fileName[userResponse]);
}

void StartPlug::createPlayers(int numOfPlayers)
{
	if (numOfPlayers >= 2 && numOfPlayers <= 5) {
		for (int player = 0; player < numOfPlayers; ++player) {
			this->players.push_back(new Player());
		}
		std::cout << numOfPlayers << " players created succesfully!" << std::endl;
	}
	else {
		std::cout << "Invalid number of players. You can only choose from 2 to 5 players." << std::endl;
	}
}