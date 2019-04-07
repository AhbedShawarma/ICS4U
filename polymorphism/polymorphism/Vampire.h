#pragma once
#include "Human.h"
#include <string>

class Vampire : public Human
{
public:
	Vampire(std::string name, std::string species);
	void speak();
	void thank();
	void payTaxes();
	bool attack();
	~Vampire();
};

