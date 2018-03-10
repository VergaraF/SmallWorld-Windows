#include "Coin.h"



Coin::Coin(int val)
{
	this->value = val;
}

int Coin::getValue() {
	return this->value;
}

Coin::~Coin()
{
}
