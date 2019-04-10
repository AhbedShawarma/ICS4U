#pragma once
#include "Citizen.h"
#include <string>

class Dwarf : public Citizen
{
public:
	Dwarf(std::string name, std::string species);
	void speak();
	void thank();
	void action();
	~Dwarf();
};

