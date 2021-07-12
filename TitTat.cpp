#include "TitTat.h"

TitTat::TitTat()
{
	this->name = "Tit For Tat";
}

int TitTat::getFirstMove()
{
	return 1;
}

int TitTat::getNextMove(int last_ai)
{
	if (last_ai == 1) return 1;
	else return 0;
}
