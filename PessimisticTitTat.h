#pragma once
#include "Strategy.h"

class PessimisticTitTat : public Strategy {
public:
	PessimisticTitTat();
	int getFirstMove();
	int getNextMove(int last_ai);
};