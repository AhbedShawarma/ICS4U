#include "Nobbs.h"
#include <string>
#include <iostream>

Nobbs::Nobbs(std::string name, std::string species) : Human(name, species, 70, 10, 20)
{
}

void Nobbs::speak() {
	std::cout << "grlglglllr (brains)\n";
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
