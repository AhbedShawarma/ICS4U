#pragma once
#include "Citizen.h"
#include <string>

class Human : public Citizen
{
public:
	Human(std::string name, std::string species, int happiness = 50, int easeOfAnger = 20, int strength = 40);
	void speak();
	void thank();
	void action();
	virtual ~Human();
};

