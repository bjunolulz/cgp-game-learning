#include "Random.h"

Random::Random()
{
	this->name = "Random";
}

int Random::getNextMove()
{
	return rand() % 2;
}

int Random::getFirstMove()
{
	return rand() % 2;
}
