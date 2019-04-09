#include "Citizen.h"
#include <string>
#include <iostream>
#include <vector>


Citizen::Citizen(std::string name, std::string species, int happiness, int easeOfAnger, int strength) : name(name), species(species), happiness(happiness), easeOfAnger(easeOfAnger), strength(strength)
{
	std::cout << "This citizen is a " << species << ", their name is " << name << ".\n";
}

std::vector<Citizen*> Citizen::citizens;
std::vector<Wolf*> Citizen::wolves;

std::string Citizen::getName() {
	return name;
}

std::string Citizen::getSpecies() {
	return species;
}

void Citizen::payTaxes() {

	if ((rand() % happiness + 1) > 10 || isThreatened == true) {
		std::cout << name << " paid their taxes in " << currency << ".\n";
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

void Citizen::attack() {
	std::cout << name << " attacked out of anger!\n";

	if ((rand() % strength + 1) > 20) {
		std::cout << name << " has killed the wolf!\n";
		wolves.erase(wolves.begin());
		//return true;
	}
	else {
		std::cout << name << " has been killed by the wolf!\n";

		//return false;
	}
}

Citizen::~Citizen()
{
}
