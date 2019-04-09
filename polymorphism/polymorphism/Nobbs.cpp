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

Nobbs::~Nobbs()
{
	std::cout << name << "has been killed!\n";
}
