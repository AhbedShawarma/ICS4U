#pragma once
#include <string>
#include <vector>

class Citizen
{
protected:
	std::string name;
	std::string species;
	int happiness;
	int easeOfAnger;
	int strength;
	bool willPayTaxes = true;

public:
	Citizen(std::string name, std::string species, int happiness, int easeOfAnger, int strength);
	bool isThreatened = false;
	std::string getName();
	std::string getSpecies();
	virtual void payTaxes();
	virtual void speak() = 0;
	virtual void thank() = 0;
	virtual bool attack() = 0;
	virtual void action() = 0;


	static std::vector<Citizen*> citizens;


	virtual ~Citizen();
};

