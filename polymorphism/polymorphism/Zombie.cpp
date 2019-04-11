#include "Zombie.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

Zombie::Zombie(std::string name, std::string species) : Human(name, species, 40, 20, 30)
{
}

void Zombie::speak() {
	if (happiness > easeOfAnger) {
		std::cout << name << ": grrlg...brains...\n";
	}
	else {
		willPayTaxes = false;
		std::cout << name << ": YOU HAVE ANGERED ME! FULFIL MY REQUEST OR ELSE I WILL NEVER PAY TAXES!\n";
	}
}

void Zombie::thank() {
	std::cout << name << ": glrga...I will not eat you...\n";
	happiness += 20;
}

void Zombie::action() {
	std::cout << name << ": YOU MUST BRING ME A BRAIN OF A CITIZEN!\nEnter the species of the citizen you would like to kill to get their brain:\n";
	char citizenToKill;
	std::cin >> citizenToKill;
	int i;
	while (true) {
		i = 0;
		for (i; i < citizens.size(); i++) {
			if ((citizenToKill == (citizens[i]->getSpecies())[0]) && (citizenToKill != getSpecies()[0])) {
				break;
			}
		}
		if (i != citizens.size()) {
			citizens[i]->attack();
			//citizens.erase(citizens.begin() + i);
			break;
		}
		std::cout << "ENTER A VALID CITIZEN SPECIES!\n"
			<< "(h - human, t - troll, d - dwarf, w - werewolf, n - Nobbs, v - vampire)\n";
		std::cin >> citizenToKill;
	}
	willPayTaxes = true;
	happiness += 100 - easeOfAnger;
}

Zombie::~Zombie()
{
	std::cout << name << "has been killed!\n";
}
