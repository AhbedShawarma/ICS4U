#include "Vampire.h"
#include <string>
#include <iostream>

Vampire::Vampire(std::string name, std::string species) : Human(name, species, 30, 30, 50)
{
}

void Vampire::speak() {
	std::cout << "grlglglllr (brains)\n";
}

void Vampire::thank() {
	std::cout << "grga larga lerg (I will not eat you)\n";
	happiness += 20;
}

bool Vampire::attack() {
	std::cout << name << " attacked out of anger!\n";

	if ((rand() % strength + 1) > 20) {
		std::cout << name << " has killed the wolf!\n";
		return true;
	}
	else {
		return false;
	}
}

Vampire::~Vampire()
{
	std::cout << name << "has been killed by the wolf!\n";
}
