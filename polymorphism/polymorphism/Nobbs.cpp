#include "Nobbs.h"
#include <string>
#include <iostream>

Nobbs::Nobbs(std::string name, std::string species) : Human(name, species, 70, 10, 20)
{
}

void Nobbs::speak() {
	std::cout << "\n";
}

void Nobbs::thank() {
	std::cout << "\n";
	happiness += 20;
}
void Nobbs::action() {
	std::cout << "You have to give me taxes of 2 citizens\n";
}

Nobbs::~Nobbs()
{
	std::cout << name << "has been killed!\n";
}
