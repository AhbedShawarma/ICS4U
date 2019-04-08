#pragma once
#include "Human.h"
#include <string>

class Vampire : public Human
{
public:
	Vampire(std::string name, std::string species);
	void speak();
	void thank();
	bool attack();
	~Vampire();
};

