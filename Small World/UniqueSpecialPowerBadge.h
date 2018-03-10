#pragma once

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
private:
	SpecialPowerType type;
};

