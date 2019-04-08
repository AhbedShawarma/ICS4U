#include "Human.h"
#include <string>
#include <iostream>

Human::Human(std::string name, std::string species, int happiness, int easeOfAnger, int strength) : Citizen(name, species, happiness, easeOfAnger, strength)
{
	isThreatened = false;

}

void Human::speak() {
	std::cout << "Sup dude.\n";
}

void Human::thank() {
	std::cout << "grga larga lerg (I will not eat you)\n";
	happiness += 20;
}

bool Human::attack() {
	std::cout << name << " attacked out of anger!\n";

	if ((rand() % strength + 1) > 20) {
		std::cout << name << " has killed the wolf!\n";
		return true;
	}
	else {
		return false;
	}
}

void Human::action() {

}

Human::~Human()
{
}
