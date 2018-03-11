#include "UniqueSpecialPowerBadge.h"



UniqueSpecialPowerBadge::UniqueSpecialPowerBadge(SpecialPowerType type)
{
	this->type = type;

	switch (type) {
	case SpecialPowerType::ALCHEMIST: {
		this->powerName = "Alchemist";
		break;
	}
	case SpecialPowerType::BERSERK: {
		this->powerName = "Berserk";
		break;
	}
	case SpecialPowerType::BIVOUACKING: {
		this->powerName = "Bivouacking";
		break;
	}
	case SpecialPowerType::COMMANDO: {
		this->powerName = "Commando";
		break;
	}
	case SpecialPowerType::DIPLOMAT: {
		this->powerName = "Diplomat";
		break;
	}
	case SpecialPowerType::DRAGON_MASTER: {
		this->powerName = "Dragon Master";
		break;
	}
	case SpecialPowerType::FLYING: {
		this->powerName = "Flying";
		break;
	}
	case SpecialPowerType::FOREST: {
		this->powerName = "Forest";
		break;
	}
	case SpecialPowerType::FORTIFIED: {
		this->powerName = "Fortified";
		break;
	}
	case SpecialPowerType::HEROIC: {
		this->powerName = "Heroic";
		break;
	}
	case SpecialPowerType::HILL: {
		this->powerName = "Hill";
		break;
	}
	case SpecialPowerType::MERCHANT: {
		this->powerName = "Merchant";
		break;
	}
	case SpecialPowerType::MOUNTED: {
		this->powerName = "Mounted";
		break;
	}
	case SpecialPowerType::PILLAGING: {
		this->powerName = "Pillaging";
		break;
	}
	case SpecialPowerType::SEAFARING: {
		this->powerName = "Seafaring";
		break;
	}
	case SpecialPowerType::SPIRIT: {
		this->powerName = "Spirit";
		break;
	}
	case SpecialPowerType::STOUT: {
		this->powerName = "Stout";
		break;
	}
	case SpecialPowerType::SWAMP: {
		this->powerName = "Swamp";
		break;
	}
	case SpecialPowerType::UNDERWORLD: {
		this->powerName = "Underworld";
		break;
	}
	case SpecialPowerType::WEALTHY: {
		this->powerName = "Wealthy";
		break;
	}
	}
}

SpecialPowerType UniqueSpecialPowerBadge::getType() {
	return this->type;
}

std::string UniqueSpecialPowerBadge::toString()
{
	return this->powerName;
}

UniqueSpecialPowerBadge::~UniqueSpecialPowerBadge()
{
}
