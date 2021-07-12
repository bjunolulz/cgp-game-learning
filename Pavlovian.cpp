#include "Pavlovian.h"

Pavlovian::Pavlovian()
{
	this->name = "Pavlovian";
}

int Pavlovian::getFirstMove()
{
	return rand() % 2;
}

int Pavlovian::getNextMove(int last_my, int my_points)
{
	if (my_points > 2) return last_my;
	else {
		if (last_my == 1) return 0;
		else return 1;
	}
}
