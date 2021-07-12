#pragma once
#include "Strategy.h"

class TitTat : public Strategy {
public:
	TitTat();
	int getFirstMove();
	int getNextMove(int last_ai);
};