#include "Citizen.h"
#include <string>
#include <iostream>


Citizen::Citizen(std::string name, std::string species) : name(name), species(species)
{
	std::cout << "This citizen is a " << species << ", their name is " << name << ".\n";
}

std::string Citizen::getName() {
	return name;
}

std::string Citizen::getSpecies() {
	return species;
}

Citizen::~Citizen()
{
}
