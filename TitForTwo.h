#pragma once
#include "Strategy.h"

class TitForTwo : public Strategy {
public:
	TitForTwo();
	int getNextMove(int last_ai, int before_last_ai);
	int getFirstMove();
};