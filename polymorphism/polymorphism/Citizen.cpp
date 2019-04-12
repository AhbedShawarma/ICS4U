#include "Citizen.h"
#include <string>
#include <iostream>
#include <vector>


Citizen::Citizen(std::string name, std::string species, int happiness, int easeOfAnger, int strength) : name(name), species(species), happiness(happiness), easeOfAnger(easeOfAnger), strength(strength)
{
	std::cout << "This citizen is a " << species << ", their name is " << name << ".\n";
	numOfTaxesPayed = 0;
	isThreatened = false;
	willPayTaxes = true;
	triggerAction = false;

}

std::vector<Citizen*> Citizen::citizens;
std::vector<Wolf*> Citizen::wolves;
int Citizen::numOfTaxesCollected = 0;

std::string Citizen::getName() {
	return name;
}

std::string Citizen::getSpecies() {
	return species;
}

int Citizen::payTaxes() {

	if ((rand() % happiness + 1) > 10 || isThreatened == true) {
		std::cout << name << " paid their taxes in " << currency << ".\n";
		happiness -= rand() % easeOfAnger + (1 + easeOfAnger * isThreatened);
		numOfTaxesPayed++;
		numOfTaxesCollected++;
		return 0;
	}

	else {
		if ((rand() % (100 - happiness) + 1) < 70) {
			std::cout << name << " refused to pay their taxes.\n";
			return 2;
		}
		else {
			return 1;
		}
	}
	
}

int Citizen::getStrength() {
	return strength;
}

bool Citizen::checkIfPaysTax() {
	return willPayTaxes;
}

//bool Citizen::triggerAction() {
//	if (happiness <= easeOfAnger) {
//		return true;
//	}
//	return false;
//}

Citizen::~Citizen()
{
	std::cout << name << " has fainted!\n";

}
