#pragma once
#include "Citizen.h"
#include <string>

class Troll : public Citizen
{
public:
	Troll(std::string name, std::string species);
	void speak();
	void thank();
	void action();
	~Troll();
};

