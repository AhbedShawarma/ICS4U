#include "Vampire.h"
#include <string>
#include <iostream>

Vampire::Vampire(std::string name, std::string species) : Human(name, species, 50, 30, 60)
{
	// pre:  takes in name and species as strings
	// post: calls the Human constructor with name and species and values for happiness, easeOfAnger, and strength
}

void Vampire::speak() {
	// pre:  none
	// post: outpus message based on happiness and ease of anger and sets willPayTaxes and triggerAction to different values if happiness is lower than easeOfAnger
	if (happiness > easeOfAnger) {
		std::cout << name << ": Greetings mortal.\n";

	}
	else {
		willPayTaxes = false;
		triggerAction = true;
		happiness += 100 - easeOfAnger;
		std::cout << name << ": I have had it with you, if you want me to pay taxes, you must do me a favour.\n";
	}
}

void Vampire::thank() {
	// pre:  none
	// post: outputs thank you message and increases happiness
	std::cout << name << ": How kind of you.\n";
	happiness += 20;
}

void Vampire::action() {
	// pre:  none
	// post: outputs that vampire will extract blood from a wolf, the wolf either lives or faints based on a random chance, vampire will now pay taxes

	std::cout << name << ": Ha! Now that you have agreed you cannot say no. You must give me a sample of your wolf's blood,\n"
		<< "don't worry, theres only a 20% chance that your wolf lives.\n";
	if ((rand() % 5 + 1) > 1) {
		std::cout << name << ": Pity, the wolf fainted in the process.\n";
		std::cout << name;
		// delete the wolf and erase it from the vector
		delete wolves[0];
		wolves.erase(wolves.begin());
	}
	else {
		std::cout << name << ": This wolf must be blessed, it survived.\n";
	}
	willPayTaxes = true;
}

Vampire::~Vampire()
{
}
