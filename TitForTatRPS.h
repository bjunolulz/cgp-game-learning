#pragma once
#include "Strategy.h"


class TitForTatRPS : public Strategy {
public:
	TitForTatRPS();
	int getFirstMove();
	int getNextMove(int last_ai);
};