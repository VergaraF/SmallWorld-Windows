/*
 * Region.h
 *
 *  Created on: Jan 24, 2018
 *      Author: fvergara
 */
#include "Player.h"
#ifndef MODEL_REGION_H_
#define MODEL_REGION_H_


class Region
{
private:

	unsigned int index;
	Player ownedBy;
	unsigned int tokens;

public:
	Region(unsigned int, unsigned int);
	Region();
	Player getOwnerPlayer();
	unsigned int getTokens();
	void setOwnerPlayer(Player&);
	void setTokens(unsigned int);
};


#endif /* MODEL_REGION_H_ */
