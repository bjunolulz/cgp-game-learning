#include "RandomRPS.h"

RandomRPS::RandomRPS()
{
	this->name = "Random";
}

int RandomRPS::getNextMove()
{
	return rand() % 3;
}
