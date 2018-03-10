#include "UniqueSpecialPowerBadge.h"



UniqueSpecialPowerBadge::UniqueSpecialPowerBadge(SpecialPowerType type)
{
	this->type = type;
}

SpecialPowerType UniqueSpecialPowerBadge::getType() {
	return this->type;
}

UniqueSpecialPowerBadge::~UniqueSpecialPowerBadge()
{
}
