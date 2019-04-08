#pragma once
#include "Human.h"
#include <string>

class Zombie : public Human
{
private:
	std::string citizenToKill;
public:
	Zombie(std::string name, std::string species);
	void speak();
	void thank();
	bool attack();
	void action();
	~Zombie();
};

