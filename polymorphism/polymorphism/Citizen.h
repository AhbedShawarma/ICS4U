#pragma once
#include <string>
#include <vector>
#include "Wolf.h"

class Citizen
{
protected:
	std::string name;
	std::string species;
	std::string currency;
	int numOfTaxesPayed;
	int happiness;
	int easeOfAnger;
	int strength;
	bool willPayTaxes;


public:
	Citizen(std::string name, std::string species, int happiness, int easeOfAnger, int strength);
	bool checkIfPaysTax();
	bool triggerAction;
	bool isThreatened;
	static int numOfTaxesCollected;
	std::string getName();
	std::string getSpecies();
	int getStrength();
	int payTaxes();
	virtual void speak() = 0;
	virtual void thank() = 0;
	virtual void action() = 0;

	static std::vector<Citizen*> citizens;
	static std::vector<Wolf*> wolves;

	virtual ~Citizen();
};

