#pragma once
#include "Citizen.h"
#include <string>

class Human : public Citizen
{
public:
	Human(std::string name, std::string species, int happiness = 50, int easeOfAnger = 10, int strength = 50);
	void speak();
	void thank();
	bool attack();
	void action();
	virtual ~Human();
};

