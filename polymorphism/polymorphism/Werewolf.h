#pragma once
#include "Human.h"
#include <string>

class Werewolf : public Human, public Wolf
{
public:
	Werewolf(std::string name, std::string species);
	void speak();
	void thank();
	void action();
	~Werewolf();
};

