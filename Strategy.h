#pragma once
#include <string>
#include <iostream>
#include <ctime>

class Strategy {
protected:
	std::string name;

public:
	~Strategy();
	Strategy();
	Strategy(std::string name);
	virtual int getNextMove();
	virtual int getFirstMove();
	virtual int getNextMove(bool betrayed);
	virtual int getNextMove(int last_ai_or_my);
	virtual int getNextMove(int last_my, int my_points);
	std::string getName();
};
