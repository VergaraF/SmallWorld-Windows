#include "SummarySheet.h"



SummarySheet::SummarySheet(Player* player)
{
	this->owner = player;
}

Player* SummarySheet::getOwnerOfSummarySheet() {
	return this->owner;
}

SummarySheet::~SummarySheet()
{
}
