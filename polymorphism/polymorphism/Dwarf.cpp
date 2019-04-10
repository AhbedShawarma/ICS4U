#include "Dwarf.h"
#include <string>
#include <iostream>


Dwarf::Dwarf(std::string name, std::string species) : Citizen(name, species, 70, 30, 30)
{
}

void Dwarf::speak() {

}

void Dwarf::thank() {
	happiness += 20;

}

void Dwarf::action() {
	happiness += 100 - easeOfAnger;

}

Dwarf::~Dwarf()
{
	std::cout << name << "has been killed!\n";
}
