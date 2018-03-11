#pragma once
#include <string>

enum class SpecialPowerType {
	ALCHEMIST,
	BERSERK,
	BIVOUACKING,
	COMMANDO,
	DIPLOMAT,
	DRAGON_MASTER,
	FLYING,
	FOREST,
	FORTIFIED,
	HEROIC,
	HILL,
	MERCHANT,
	MOUNTED,
	PILLAGING,
	SEAFARING,
	SPIRIT,
	STOUT,
	SWAMP,
	UNDERWORLD,
	WEALTHY,
	BLANK
};
class UniqueSpecialPowerBadge
{
public:
	UniqueSpecialPowerBadge(SpecialPowerType);
	~UniqueSpecialPowerBadge();
	SpecialPowerType getType();
	std::string toString();
private:
	SpecialPowerType type;
	std::string powerName;
};

