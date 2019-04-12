#include "Citizen.h"
#include <string>
#include <iostream>
#include <vector>


Citizen::Citizen(std::string name, std::string species, int happiness, int easeOfAnger, int strength) : name(name), species(species), happiness(happiness), easeOfAnger(easeOfAnger), strength(strength)
{
	// output that a new citizen is created with their species and name
	std::cout << "This citizen is a " << species << ", their name is " << name << ".\n";
	// set variables to default values
	numOfTaxesPaid = 0;
	isThreatened = false;
	willPayTaxes = true;
	triggerAction = false;

}
// vector of Citizen* (static member variable)
std::vector<Citizen*> Citizen::citizens;
// vector of Wolf* (static member variable)
std::vector<Wolf*> Citizen::wolves;
// set numOfTaxesCollected to 0 (static member variable)
int Citizen::numOfTaxesCollected = 0;

std::string Citizen::getName() {
	// pre:	 none
	// post: returns the name of object for public access
	return name;
}

std::string Citizen::getSpecies() {
	// pre:	 none
	// post: returns the species of object for public access
	return species;
}

int Citizen::payTaxes() {
	// pre:  none
	// post: returns a value that corresponds to what happened, 0 means taxes were paid, 1 means the citizen attacked, 2 means the citizen refused
	
	// if rand value is greater than 10 or if threatened, pay taxes, reduce happiness, and add 1 to numOfTaxesPaid and numOfTaxesCollected, return 0
	if ((rand() % happiness + 1) > 10 || isThreatened == true) {
		std::cout << name << " paid their taxes in " << currency << ".\n";
		happiness -= rand() % easeOfAnger + (1 + easeOfAnger * isThreatened);
		numOfTaxesPaid++;
		numOfTaxesCollected++;
		return 0;
	}
	// else
	else {
		// if rand value is less than 70, output refused to pay taxes, return 2
		if ((rand() % (100 - happiness) + 1) < 70) {
			std::cout << name << " refused to pay their taxes.\n";
			return 2;
		}
		// else return 1
		else {
			return 1;
		}
	}
	
}

int Citizen::getStrength() {
	// pre:	 none
	// post: returns the strength of object for public access
	return strength;
}

bool Citizen::checkIfPaysTax() {
	// pre:	 none
	// post: returns bool value for willPayTaxes for public access
	return willPayTaxes;
}

Citizen::~Citizen()
{
	// outputs name and that they have fainted
	std::cout << name << " has fainted!\n";

}
