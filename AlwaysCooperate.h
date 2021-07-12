#pragma once
#include "Strategy.h"

class AlwaysCooperate : public Strategy {
public:
	AlwaysCooperate();
	~AlwaysCooperate();
	int getNextMove();
	int getFirstMove();
};