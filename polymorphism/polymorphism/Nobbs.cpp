#include "Nobbs.h"
#include <string>
#include <iostream>

Nobbs::Nobbs(std::string name, std::string species) : Human(name, species, 70, 10, 20)
{
	// pre:  takes in name and species as strings
	// post: calls the Human constructor with name and species and values for happiness, easeOfAnger, and strength
}

void Nobbs::speak() {
	// pre:  none
	// post: outpus message based on happiness and ease of anger and sets willPayTaxes and triggerAction to different values if happiness is lower than easeOfAnger
	if (happiness > easeOfAnger) {
		std::cout << name << ": Hello there.\n";
	}
	else {
		std::cout << name << ": You have made me angery! I will stop paying taxes unless you give me something.\n";
		willPayTaxes = false;
		triggerAction = true;
		happiness += 100 - easeOfAnger;
	}
}

void Nobbs::thank() {
	// pre:  none
	// post: outputs thank you message and increases happiness
	std::cout << name << ": You're up to something if you don't need me to pay taxes this month.\n";
	happiness += 20;
}

void Nobbs::action() {
	// pre:  none
	// post: subtracts all the times Nobbs has paid from numOfTaxesCollected

	std::cout << name << ": You must give back all of the tax I have paid.\n";
	numOfTaxesCollected -= numOfTaxesPaid;
	willPayTaxes = true;
}

Nobbs::~Nobbs()
{
}
