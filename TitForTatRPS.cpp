#include "TitForTatRPS.h"

TitForTatRPS::TitForTatRPS()
{
	this->name = "Tit for Tat";
}

int TitForTatRPS::getFirstMove()
{
	return rand() % 3;
}

int TitForTatRPS::getNextMove(int last_ai)
{
	return last_ai;
}

