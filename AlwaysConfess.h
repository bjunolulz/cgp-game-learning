#pragma once
#include "Strategy.h"

class AlwaysConfess : public Strategy {
public:
	AlwaysConfess();
	~AlwaysConfess();
	int getNextMove();
	int getFirstMove();
};