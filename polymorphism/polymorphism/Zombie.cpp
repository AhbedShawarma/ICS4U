#include "Zombie.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

Zombie::Zombie(std::string name, std::string species) : Human(name, species, 40, 20, 30)
{
}

void Zombie::speak() {
	if (happiness > 0) {
		std::cout << "grrlg...brains...\n";
	}
	else {
		std::cout << "YOU HAVE ANGERED ME! FULFIL MY REQUEST OR ELSE I WILL NEVER PAY TAXES!\n";
	}
}

void Zombie::thank() {
	std::cout << "glrga...I will not eat you...\n";
	happiness += 20;
}

bool Zombie::attack() {
	std::cout << name << " attacked out of anger!\n";

	if ((rand() % strength + 1) > 20) {
		std::cout << name << " has killed the wolf!\n";
		return true;
	}
	else {
		return false;
	}
}

void Zombie::action() {
	std::cout << "YOU MUST BRING ME A BRAIN OF A CITIZEN!\n Enter the species of the citizen you would like to kill to get their brain:\n";
	std::cin >> citizenToKill;
	while (true) {
		//for (int i = 0; i < citizens.size(); i++) {
			//if ((citizenToKill == citizens[i]->getSpecies()) && citizenToKill != getSpecies()) {
			//if (std::stoi(citizenToKill) )
		break;
			//}
		//}
		std::cout << "ENTER A VALID CITIZEN SPECIES!\n";
	}
}

Zombie::~Zombie()
{
	std::cout << name << "has been killed by the wolf!\n";
}
