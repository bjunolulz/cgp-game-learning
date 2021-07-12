#include "PessimisticTitTat.h"

PessimisticTitTat::PessimisticTitTat()
{
	this->name = "Pessimistic Tit For Tat";
}

int PessimisticTitTat::getFirstMove()
{
	return 0;
}

int PessimisticTitTat::getNextMove(int last_ai)
{
	if (last_ai == 1) return 1;
	else return 0;
}
