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
		triggerAction = true;
		std::cout << name << ": You made me angery, no..., it is turning me..., into..., a, a...";
		std::cout << name << " has turned into a wolf! You can try to tame the wolf or let him stay as a wolf who will never pay taxes.\n"
			<< "Do you whish to tame him?";

		//howl();
		//action();
		willPayTaxes = false;
	}
	if (!willPayTaxes) {
		growl();
		howl();
	}
}

void Werewolf::thank() {
	std::cout << "Thank you sir.\n";
	happiness += 20;
}

void Werewolf::action() {

	if (rand() % 10 + 1 == 1) {
		std::cout << "You were successful, " << name << " is now one of your wolves\n";
		int i = 0;
		for (; i < citizens.size(); i++) {
			if ((getSpecies() == citizens[i]->getSpecies())) {
				break;
			}
		}
		citizens.erase(citizens.begin() + i);
		wolves.push_back(((Wolf*)citizens[i]));
		wolves[i]->howl();

	}
	else {
		std::cout << "You were unsuccessful.\n";
	}
	happiness += 100 - easeOfAnger;

}


Werewolf::~Werewolf()
{
}
