#pragma once
#include "Human.h"
#include <string>

class Zombie : public Human
{
public:
	Zombie(std::string name, std::string species);
	void speak();
	void thank();
	void action();
	~Zombie();
};

