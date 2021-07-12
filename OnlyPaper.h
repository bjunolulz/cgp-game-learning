#pragma once
#include "Strategy.h"

class OnlyPaper : public Strategy {
public:
	OnlyPaper();
	int getNextMove();
};