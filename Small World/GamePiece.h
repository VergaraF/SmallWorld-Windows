#pragma once
#include "Token.h"

enum class GamePieceType {
	TROLL_LAIR,
	FORTRESS,
	MOUNTAIN,
	ENCAMPMENT,
	HOLES_IN_THE_GROUND,
	HEROES,
	DRAGON
};

class GamePiece : public Token
{
public:
	GamePiece(GamePieceType);
	~GamePiece();
	GamePieceType getGamePiece();

private:
	GamePieceType type;
};

