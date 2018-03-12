/*
 * Region.h
 *
 *  Created on: Jan 24, 2018
 *      Author: fvergara
 */

#ifndef MODEL_REGION_H_
#define MODEL_REGION_H_
//#include "Player.h"

#include <vector>
#include "Token.h"

enum class RegionType {
	WATER,
	MOUNTAIN,
	EDGE
};

class Region
{
private:
	unsigned int index;
	unsigned int tokens;
	bool hasLostTribe;
	bool mountainType;
	bool waterType;
	bool edgeType;
	bool conquered;

public:
	Region(unsigned int, unsigned int);
	Region();
	std::vector<Token*> raceTokens;
	std::vector<Token*> propertyTokens;
	unsigned int getTokens();
	unsigned int getIndex();
	void setTokens(unsigned int);
	void setRegionIndex(unsigned int);
	void setRegionType(RegionType);
	void setEdgeRegion(bool);
	void setTribeOnRegion(bool);
	bool containsLostTribe();
	bool isMountain();
	bool isWater();
	bool isEdge();
	bool isConquered();
	bool hasBeenConquered(bool);
	std::string ownedBy;
	std::vector<int> neighborIndexes;
};


#endif /* MODEL_REGION_H_ */
