#include "Human.h"
#include <string>
#include <iostream>

Human::Human(std::string name, std::string species, int happiness, int easeOfAnger, int strength) : Citizen(name, species, happiness, easeOfAnger, strength)
{
	currency = "dollars";
}

void Human::speak() {
	if (happiness > easeOfAnger) {
		std::cout << "Sup dude.\n";
	}
	else {
		std::cout << "You ain't being to nice man, I'm upset! I'll stop paying taxes unless you do something that makes me like you.\n";
	}
}

void Human::thank() {
	std::cout << "You a real brotha!\n";
	happiness += 20;
}

void Human::action() {
	std::cout << "So hear me out, if you  \n";

	happiness += 100 - easeOfAnger;
}

Human::~Human()
{
}
