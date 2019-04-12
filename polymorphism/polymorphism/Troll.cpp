#include "Troll.h"
#include <string>
#include <iostream>

Troll::Troll(std::string name, std::string species) : Citizen(name, species, 70, 30, 30)
{
	currency = "gems";
}

void Troll::speak() {
	if (happiness > easeOfAnger) {
		std::cout << name << ": I used to work under a bridge y'know.\n";
	}
	else {
		triggerAction = true;
		willPayTaxes = false;
		std::cout << name << ": Ohh you've got me real mad, I will never pay taxes unless you answer my 3 riddles!\n";
	}
}

void Troll::thank() {
	std::cout << name << ": How kind of you.\n";
	happiness += 20;

}

void Troll::action() {
	char ans;
	int i = 1;
	while (i) {

		std::cout << name << ": Riddle 1: What is the next character in the sequence:\n"
			<< "J, A, S, O, N, D ...\n";
		std::cin >> ans;
		if (ans != 'j' && ans != 'J') {
			std::cout << name << ": INCORRECT!\n";
			break;
		}
		std::cout << name << ": CORRECT!\n";
		std::cout << name << ": Riddle 2: What is the next character in the sequence:\n"
			<< "O, T, T, F, F, S, S ...\n";
		std::cin >> ans;
		if (ans != 'e' && ans != 'E') {
			std::cout << name << ": INCORRECT!\n";
			break;
		}
		std::cout << name << ": CORRECT!\n";
		std::cout << name << ": Riddle 3: What is the next character in the sequence:\n"
			<< "V, B, N, M, ...\n";
		std::cin >> ans;
		if (ans != ',' && ans != '<') {
			std::cout << name << ": INCORRECT!\n";
			break;
		}
		std::cout << name << ": CORRECT! You have passed my test!\n";
		willPayTaxes = true;
		i = 0;
	}
	
	if (i == 1) {
		std::cout << name << ": You have failed! I will never pay taxes again.\n";
	}
	happiness += 100 - easeOfAnger;
}

Troll::~Troll()
{
}
