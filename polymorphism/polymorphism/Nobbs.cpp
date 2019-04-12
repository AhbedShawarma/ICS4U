#include "Nobbs.h"
#include <string>
#include <iostream>

Nobbs::Nobbs(std::string name, std::string species) : Human(name, species, 70, 10, 20)
{
}

void Nobbs::speak() {
	if (happiness > easeOfAnger) {
		std::cout << name << ": Hello there.\n";
	}
	else {
		std::cout << name << ": You have made me angery! I will stop paying taxes unless you give me something.\n";
		willPayTaxes = false;
		triggerAction = true;
	}
}

void Nobbs::thank() {
	std::cout << name << ": You're up to something if you don't need me to pay taxes this month.\n";
	happiness += 20;
}

void Nobbs::action() {
	std::cout << name << ": You must give back all of the tax I have paid.\n";
	numOfTaxesCollected -= numOfTaxesPayed;
	willPayTaxes = true;
	happiness += 100 - easeOfAnger;
}

Nobbs::~Nobbs()
{
}
