#include "Dwarf.h"
#include <string>
#include <iostream>


Dwarf::Dwarf(std::string name, std::string species) : Citizen(name, species, 70, 30, 30)
{
	currency = "gold";
}

void Dwarf::speak() {
	if (happiness > easeOfAnger) {
		std::cout << name << ": Cheerio mate!\n";
	}
	else {
		std::cout << name << ": Ohhh ye got me mad! If ye want me to pay taxes e'er again, ye must give me something in return.";
		willPayTaxes = false;
		triggerAction = true;

	}
}

void Dwarf::thank() {
	std::cout << name << ": Thanks mate, you're a good fellow.\n";
	happiness += 20;
}

void Dwarf::action() {
	std::cout << name << ": You have to give me money worth 3 portions of tax that you have collected from citizens, even if that means you have to pay out of your pocket.\n";
	numOfTaxesCollected -= 3;
	willPayTaxes = true;
	happiness += 100 - easeOfAnger;

}

Dwarf::~Dwarf()
{
}
