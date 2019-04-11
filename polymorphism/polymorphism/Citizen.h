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

public:
	Citizen(std::string name, std::string species, int happiness, int easeOfAnger, int strength);
	bool isThreatened = false;
	bool willPayTaxes = true;
	static int numOfTaxesCollected;
	//bool isWolf1Alive = true;
	//bool isWolf2Alive = true;
	std::string getName();
	std::string getSpecies();
	void payTaxes();
	void attack();
	virtual void speak() = 0;
	virtual void thank() = 0;
	virtual void action() = 0;

	static std::vector<Citizen*> citizens;
	static std::vector<Wolf*> wolves;

	virtual ~Citizen();
};

