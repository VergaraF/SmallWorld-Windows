#include "GamePiece.h"



GamePiece::GamePiece(GamePieceType type)
{
	this->type = type;
}


GamePiece::~GamePiece()
{
}

GamePieceType GamePiece::getGamePiece()
{
	return this->type;
}
