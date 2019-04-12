#include "Troll.h"
#include <string>
#include <iostream>

Troll::Troll(std::string name, std::string species) : Citizen(name, species, 70, 30, 30)
{
	// pre:  takes in name and species as strings
	// post: calls the Citizen constructor with name and species and values for happiness, easeOfAnger, and strength

	// sets currency to gems
	currency = "gems";
}

void Troll::speak() {
	// pre:  none
	// post: outpus message based on happiness and ease of anger and sets willPayTaxes and triggerAction to different values if happiness is lower than easeOfAnger
	if (happiness > easeOfAnger) {
		std::cout << name << ": I used to work under a bridge y'know.\n";
	}
	else {
		triggerAction = true;
		willPayTaxes = false;
		happiness += 100 - easeOfAnger;
		std::cout << name << ": Ohh you've got me real mad, I will never pay taxes unless you answer my 3 riddles!\n";
	}
}

void Troll::thank() {
	// pre:  none
	// post: outputs thank you message and increases happiness
	std::cout << name << ": How kind of you.\n";
	happiness += 20;

}

void Troll::action() {
	// pre:  none
	// post: outputs riddles for the user, if the user gets all 3 correct, troll will be able to pay taxes
	
	// variable for user input
	char ans;
	bool i = true;
	// while loop that runs while i is true
	while (i) {

		std::cout << name << ": Riddle 1: What is the next character in the sequence:\n"
			<< "J, A, S, O, N, D ...\n";
		std::cin >> ans;
		// if user does not enter j or J, they are wrong, break out
		if (ans != 'j' && ans != 'J') {
			std::cout << name << ": INCORRECT!\n";
			break;
		}
		std::cout << name << ": CORRECT!\n";
		std::cout << name << ": Riddle 2: What is the next character in the sequence:\n"
			<< "O, T, T, F, F, S, S ...\n";
		std::cin >> ans;
		// if user does not enter e or E, they are wrong, break out
		if (ans != 'e' && ans != 'E') {
			std::cout << name << ": INCORRECT!\n";
			break;
		}
		std::cout << name << ": CORRECT!\n";
		std::cout << name << ": Riddle 3: What is the next character in the sequence:\n"
			<< "V, B, N, M, ...\n";
		std::cin >> ans;
		// if user does not enter , or <, they are wrong, break out
		if (ans != ',' && ans != '<') {
			std::cout << name << ": INCORRECT!\n";
			break;
		}
		// user has passed all riddle, set pay taxes to true, set i to false
		std::cout << name << ": CORRECT! You have passed my test!\n";
		willPayTaxes = true;
		i = false;
	}
	
	// if i is true, ouput user has lost
	if (i == true) {
		std::cout << name << ": You have failed! I will never pay taxes again.\n";
	}
}

Troll::~Troll()
{
}
