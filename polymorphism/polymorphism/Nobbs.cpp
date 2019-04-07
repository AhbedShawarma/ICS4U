#include "Nobbs.h"
#include <string>
#include <iostream>

Nobbs::Nobbs(std::string name, std::string species) : Human(name, species)
{
	happiness = 50;
	easeOfAnger = 20;
	strength = 30;
	isThreatened = false;
}

void Nobbs::speak() {
	std::cout << "grlglglllr (brains)\n";
}

void Nobbs::payTaxes() { // if i put it under citizen, does it update variables? does Citizen::payTaxes work?

	if (happiness < 1) {
		attack();
	}
	else {
		if ((rand() % happiness + 1) > 10 || isThreatened == true) {
			std::cout << name << " paid their taxes.\n";
			happiness -= rand() % easeOfAnger + (1 + easeOfAnger * isThreatened);
		}
		else {
			if ((rand() % (100 - happiness) + 1) < 50) {
				attack();
			}
			else {
				std::cout << name << " refused to pay their taxes.\n";
			}
		}
	}

}

void Nobbs::thank() {
	std::cout << "grga larga lerg (I will not eat you)\n";
	happiness += 20;
}

bool Nobbs::attack() {
	std::cout << name << " attacked out of anger!\n";

	if ((rand() % strength + 1) > 20) {
		std::cout << name << " has killed the wolf!\n";
		return true;
	}
	else {
		return false;
	}
}

Nobbs::~Nobbs()
{
	std::cout << name << "has been killed by the wolf!\n";
}
