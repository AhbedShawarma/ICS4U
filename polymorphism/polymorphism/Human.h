#pragma once
#include "Citizen.h"
#include <string>

class Human : public Citizen
{
public:
	Human(std::string name, std::string species);
	virtual void speak() = 0;
	virtual void thank() = 0;
	virtual void payTaxes() = 0;
	virtual bool attack() = 0;
	virtual ~Human();
};

