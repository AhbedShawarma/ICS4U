#include "Vampire.h"
#include <string>
#include <iostream>

Vampire::Vampire(std::string name, std::string species) : Human(name, species, 50, 30, 60)
{
}

void Vampire::speak() {
	if (happiness > easeOfAnger) {
		std::cout << "Greetings mortal.\n";

	}
	else {
		willPayTaxes = false;
		std::cout << "I have had it with you, if you want me to pay taxes, you must do me a favour.\n";
	}
}

void Vampire::thank() {
	std::cout << "How kind of you.\n";
	happiness += 20;
}

void Vampire::action() {
	std::cout << "Ha! Now that you have agreed you cannot say no. You must give me a sample of your wolf's blood,\n"
		<< "don't worry, theres only a 20% chance that your wolf lives.\n";
	if ((rand() % 10 + 1) > 2) {
		std::cout << "Pity, the wolf died in the process.\n";
		wolves.erase(wolves.begin());
	}
	else {
		std::cout << "This wolf must be blessed, it survived.\n";
	}

	willPayTaxes = true;
	happiness += 100 - easeOfAnger;
}

Vampire::~Vampire()
{
	std::cout << name << "has been killed!\n";
}
