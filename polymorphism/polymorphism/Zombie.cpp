#include "Zombie.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

Zombie::Zombie(std::string name, std::string species) : Human(name, species, 40, 20, 30)
{
	// pre:  takes in name and species as strings
	// post: calls the Human constructor with name and species and values for happiness, easeOfAnger, and strength

}

void Zombie::speak() {
	// pre:  none
	// post: outpus message based on happiness and ease of anger and sets willPayTaxes and triggerAction to different values if happiness is lower than easeOfAnger
	if (happiness > easeOfAnger) {
		std::cout << name << ": grrlg...brains...\n";
	}
	else {
		triggerAction = true;
		willPayTaxes = false;
		happiness += 100 - easeOfAnger;
		std::cout << name << ": YOU HAVE ANGERED ME! FULFIL MY REQUEST OR ELSE I WILL NEVER PAY TAXES!\n";

	}
}

void Zombie::thank() {
	// pre:  none
	// post: outputs thank you message and increases happiness
	std::cout << name << ": glrga...I will not eat you...\n";
	happiness += 20;
}

void Zombie::action() {
	// pre:  none
	// post: prompts user to bring a brain of a citizen, deletes that citizen and erases them from the vector of citizens, the zombie will now pay taxes
	
	// if size = 1, then simply output that since there is no one else, no one gets their brain extracted
	if (citizens.size() == 1) {
		std::cout << name << ": Since all other citizens have already fainted, you do not have to bring me anyone.\n";
	}
	// else choose a citizen to get a brain from
	else {
		std::cout << name << ": YOU MUST BRING ME A BRAIN OF A CITIZEN!\n" <<
			"Choose which citizen's brain you would like to take\n"
			<< "(h - human, t - troll, d - dwarf, w - werewolf, n - Nobbs, v - vampire): ";
	
		// set variable for the user input on whose brain to extract
		char citizenToFaint;
		std::cin >> citizenToFaint;
		int i;
		// while true loop that exits when the user enters a valid citizen species that is also in the vector of citizens
		while (true) {
			i = 0;
			// iterates through vectorof citizens until, breaks when if finds a valid species input
			for (i; i < citizens.size(); i++) {
				if ((citizenToFaint == (citizens[i]->getSpecies())[0]) && (citizenToFaint != getSpecies()[0])) {
					break;
				}
			}
			// if the loop breaks early, it found a valid citizen, so delete that citizen and erase them from the citizens vector and break out of the loo
			if (i != citizens.size()) {
				delete citizens[i];
				citizens.erase(citizens.begin() + i);
				break;
			}
			// prompt user to enter valid citizen species
			std::cout << "ENTER A VALID CITIZEN SPECIES! (it could be that the citizen is dead)\n"
				<< "(h - human, t - troll, d - dwarf, w - werewolf, n - Nobbs, v - vampire): ";
			std::cin >> citizenToFaint;
		}

	}

	willPayTaxes = true;

}

Zombie::~Zombie()
{
}
