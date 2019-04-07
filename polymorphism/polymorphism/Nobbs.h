#pragma once
#include "Human.h"
#include <string>

class Nobbs : public Human
{
public:
	Nobbs(std::string name, std::string species);
	void speak();
	void thank();
	void payTaxes();
	bool attack();
	~Nobbs();
};

