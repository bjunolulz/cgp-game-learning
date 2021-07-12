#include "Alternating.h"

Alternating::Alternating()
{
	this->name = "Alternating";

}

int Alternating::getFirstMove()
{
	return rand() % 2;
}

int Alternating::getNextMove(int last_my)
{
	if (last_my == 0) return 1;
	else return 0;
}
