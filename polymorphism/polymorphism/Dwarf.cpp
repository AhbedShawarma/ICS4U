#include "Dwarf.h"
#include <string>
#include <iostream>


Dwarf::Dwarf(std::string name, std::string species) : Citizen(name, species, 70, 30, 30)
{
	// pre:  takes in name and species as strings
	// post: calls the Citizen constructor with name and species and values for happiness, easeOfAnger, and strength
	
	// sets currency to gold
	currency = "gold";
}

void Dwarf::speak() {
	// pre:  none
	// post: outpus message based on happiness and ease of anger and sets willPayTaxes and triggerAction to different values if happiness is lower than easeOfAnger
	if (happiness > easeOfAnger) {
		std::cout << name << ": Cheerio mate!\n";
	}
	else {
		happiness += 100 - easeOfAnger;
		std::cout << name << ": Ohhh ye got me mad! If ye want me to pay taxes e'er again, ye must give me something in return.";
		willPayTaxes = false;
		triggerAction = true;

	}
}

void Dwarf::thank() {
	// pre:  none
	// post: outputs thank you message and increases happiness
	std::cout << name << ": Thanks mate, you're a good fellow.\n";
	happiness += 20;
}

void Dwarf::action() {
	// pre:  none
	// post: gives dwarf 3 tax portions (takes 3 away from numOfTaxesCollected) and makes dwarf able to pay taxes again

	std::cout << name << ": You have to give me money worth 3 portions of tax that you have collected from citizens, even if that means you have to pay out of your pocket.\n";
	numOfTaxesCollected -= 3;
	willPayTaxes = true;

}

Dwarf::~Dwarf()
{
}
