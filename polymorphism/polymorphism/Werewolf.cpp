#include "Werewolf.h"
#include <string>
#include <iostream>


Werewolf::Werewolf(std::string name, std::string species) : Human(name, species, 50, 10, 50), Wolf(species)
{
	// pre:  takes in name and species as strings
	// post: calls the Human constructor with name and species and values for happiness, easeOfAnger, and strength. Then calls the wolf constructor with species as a parameter
}

void Werewolf::speak() {
	// pre:  none
	// post: outpus message based on happiness, easeOfAnger, and willPayTaxes. Sets willPayTaxes and triggerAction to different values if happiness is lower than easeOfAnger
	//		 calls growl and howl if the werewolf no longer pays taxes

	if (!willPayTaxes) {
		growl();
		howl();
	}
	else {
		if (happiness > easeOfAnger) {
			std::cout << name << ": Uhhh, what do you want?\n";
		}
		else {
			std::cout << name << ": You made me angery, no..., it is turning me..., into..., a, a...";
			std::cout << name << " has turned into a wolf! You can try to tame the wolf or let him stay as a wolf who will never pay taxes.\n"
				<< "Do you whish to tame him?";

			triggerAction = true;
			happiness += 100 - easeOfAnger;
			willPayTaxes = false;
		}

	}
	
}

void Werewolf::thank() {
	// pre:  none
	// post: outputs thank you message and increases happiness
	std::cout << "Thank you sir.\n";
	happiness += 20;
}

void Werewolf::action() {
	// pre:  none
	// post: based on random number generation, either adds the werewolf to the wolves vector (removes it from the citizens vector also) or ouputs that the user could not tame the wolf

	// if rand == 1
	if (rand() % 10 + 1 == 1) {
		std::cout << "You were successful, " << name << " is now one of your wolves\n";
		int i = 0;
		// find the index of the werewolf
		for (; i < citizens.size(); i++) {
			if ((getSpecies() == citizens[i]->getSpecies())) {
				break;
			}
		}

		// cast the werewolf as a wolf and add it to wolves vector
		wolves.push_back(((Wolf*)citizens[i]));
		// remove it from citizens vector
		citizens.erase(citizens.begin() + i);
		// call howl and growl
		wolves[i]->howl();
		wolves[i]->growl();
	}

	else {
		std::cout << "You were unsuccessful.\n";
	}

}


Werewolf::~Werewolf()
{
}
