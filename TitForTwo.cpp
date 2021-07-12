#include "TitForTwo.h"

TitForTwo::TitForTwo()
{
	this->name = "Tit For Two Tats";
}

int TitForTwo::getNextMove(int last_ai, int before_last_ai)
{
	if (last_ai == 0) {
		if (before_last_ai == 0) return 0;
		else return 1;
	}
	else return 1;
}

int TitForTwo::getFirstMove()
{
	return 1;
}
