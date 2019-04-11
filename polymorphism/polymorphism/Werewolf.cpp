#include "Werewolf.h"
#include <string>
#include <iostream>


Werewolf::Werewolf(std::string name, std::string species) : Human(name, species, 50, 10, 50), Wolf(species)
{
}

void Werewolf::speak() {
	if (happiness > easeOfAnger) {
		std::cout << name << ": Uhhh, what do you want?\n";
	}
	else {
		std::cout << name << ": You made me angery, no..., it is turning me..., into..., a, a...";
		howl();
		action();
		willPayTaxes = false;
	}
}

void Werewolf::thank() {
	std::cout << "Thank you sir.\n";
	happiness += 20;
}

void Werewolf::action() {
	std::cout << name << " has turned into a wolf! You can try to tame the wolf or let him stay as a wolf who will never pay taxes.\nPress t to tame\n";
	// erase werewolf from citizens and add a new one to the wolf vector, still as a werewolf tho
	// or a way to do it normally?
	char userAns;
	std::cin >> userAns;
	if (userAns == 't') {
		if (rand() % 10 + 1 == 1) {
			std::cout << "You were successful, " << name << " is now one of your wolves\n";

		}
	}

}


Werewolf::~Werewolf()
{
	std::cout << name << " has died.\n";
}
