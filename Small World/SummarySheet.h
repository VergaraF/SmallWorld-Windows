#pragma once

#include "Player.h"
class SummarySheet
{
public:
	SummarySheet(Player*);
	~SummarySheet();
	Player* getOwnerOfSummarySheet();

private:
	Player* owner;
};

