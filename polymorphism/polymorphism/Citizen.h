#pragma once
#include <string>

class Citizen
{
protected:
	std::string name;
	std::string species;
	int happiness;
	int easeOfAnger;
	int strength;
	bool isThreatened;

public:
	Citizen(std::string name, std::string species);
	std::string getName();
	std::string getSpecies();
	virtual void payTaxes() = 0;
	virtual void speak() = 0;
	virtual void thank() = 0;
	virtual bool attack() = 0;
	virtual ~Citizen();
};

