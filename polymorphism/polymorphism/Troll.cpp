#include "Troll.h"
#include <string>
#include <iostream>

Troll::Troll(std::string name, std::string species) : Citizen(name, species, 70, 30, 30)
{
}

void Troll::speak() {
	if (happiness > easeOfAnger) {
		std::cout << "I used to work under a bridge y'know.\n";
	}
	else {
		willPayTaxes = false;
		std::cout << "Ohh you've got me real mad, I will never pay taxes unless you answer my 3 riddles!\n";
	}
}

void Troll::thank() {
	std::cout << "How kind of you.\n";
	happiness += 20;

}

void Troll::action() {
	char ans;
	int i = 1;
	while (i) {

		std::cout << "Riddle 1: What is the next letter in the sequence:\n"
			<< "J, A, S, O, N, D ...\n";
		std::cin >> ans;
		if (ans != 'j' && ans != 'J') {
			std::cout << "INCORRECT!\n";
			break;
		}
		std::cout << "CORRECT!\n";
		std::cout << "Riddle 2: What is the next letter in the sequence:\n"
			<< "O, T, T, F, F, S, S ...\n";
		if (ans != 'e' && ans != 'E') {
			std::cout << "INCORRECT!\n";
			break;
		}
		std::cout << "CORRECT!\n";
		std::cout << "Riddle 3: What is the next letter in the sequence:\n"
			<< "V, B, N, M, ...\n";
		if (ans != ',' && ans != '<') {
			std::cout << "INCORRECT!\n";
			break;
		}
		std::cout << "CORRECT! You have passed my test!\n";
		willPayTaxes = false;
		happiness += 100 - easeOfAnger;
		i = 0;
	}
	
	if (i == 1) {
		std::cout << "You have failed! I will never pay taxes again.\n";
	}
}

Troll::~Troll()
{
	std::cout << name << "has been killed!\n";
}
