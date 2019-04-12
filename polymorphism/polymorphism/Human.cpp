#include "Human.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include <conio.h>

Human::Human(std::string name, std::string species, int happiness, int easeOfAnger, int strength) : Citizen(name, species, happiness, easeOfAnger, strength)
{
	// pre: takes in name and species as strings
	// post: calls the Citizen constructor with name and species and values for happiness, easeOfAnger, and strength
	
	// sets currecny to dollars
	currency = "dollars";
}

void Human::speak() {
	// pre:  none
	// post: outpus message based on happiness and ease of anger and sets willPayTaxes and triggerAction to different values if happiness is lower than easeOfAnger

	if (happiness > easeOfAnger) {
		std::cout << name << ": Sup dude.\n";
	}
	else {
		willPayTaxes = false;
		triggerAction = true;
		happiness += 100 - easeOfAnger;
		std::cout << name << ": You ain't being to nice man, I'm upset! I'll stop paying taxes unless you beat me in a duel.\n";
	}
}

void Human::thank() {
	// pre:  none
	// post: outputs thank you message and increases happiness

	std::cout << name << ": You a real brotha!\n";
	happiness += 20;
}

void Human::action() {
	// pre:  none
	// post: outputs a scenario where the user duels the human, sets willPayTaxes to true if the user wins

	std::cout << name << ": Get ready! I'll only pay taxes if you beat me in 5 turns.\n";
	std::cout << "PRESS W to attack, A to dodge left, D to dodge right.\n";
	// sets bool variable for who wins
	bool humanWin = true;
	// sets chance of winning variable
	int chanceOfWinning;
	// for loop that runs 5 times
	for (chanceOfWinning = 5; chanceOfWinning > 0; chanceOfWinning--) {
		// generates random move for human to make
		int move = rand() % 3 + 1;
		// if statements that do and output different things based on the move
		if (move == 1) {
			std::cout << "The opponent attacked head on!\n";
			// waits for key press
			_getch();

			// if W, random chance that decides if the human wins or user does
			if (GetKeyState('W') & 0x8000) {
				if (rand() % chanceOfWinning) {
					std::cout << "You are disarmed and lost the duel!\n";
					humanWin = true;
					break;
				}
				else {
					std::cout << "You disarmed " << name << " and won!\n";
					humanWin = false;
					break;
				}
			}
			// if A or D, user dodged
			else if ((GetKeyState('A') & 0x8000) || (GetKeyState('D') & 0x8000)) {
				std::cout << "You dodged the attack!\n";
				continue;
			}
			// else loss
			else {
				std::cout << "You stood still and lost!\n";
				break;
			}
		}
		else if (move == 2) {
			std::cout << "The opponent attacked from the right!\n";
			_getch();
			// if W, random chance that decides if the human wins or user does
			if (GetKeyState('W') & 0x8000) {
				if (rand() % chanceOfWinning) {
					std::cout << "You are disarmed and lost the duel!\n";
					humanWin = true;
					break;
				}
				else {
					std::cout << "You disarmed " << name << " and won!\n";
					humanWin = false;
					break;
				}
			}
			// if A user, dodged
			else if (GetKeyState('A') & 0x8000) {
				std::cout << "You dodged the attack!\n";
				continue;
			}
			// if D, user lost
			else if (GetKeyState('D') & 0x8000) {
				std::cout << "You dodged the wrong way and lost!\n";
				break;
			}
			// else user lost
			else {
				std::cout << "You stood still and lost!\n";
				break;
			}
		}
		else if (move == 3) {
			std::cout << "The opponent attacked from the left!\n";
			_getch();
			// if W, random chance that decides if the human wins or user does
			if (GetKeyState('W') & 0x8000) {
				if (rand() % chanceOfWinning) {
					std::cout << "You are disarmed and lost the duel!\n";
					humanWin = true;
					break;
				}
				else {
					std::cout << "You disarmed " << name << " and won!\n";
					humanWin = false;
					break;
				}
			}
			// if D, user dodged
			else if (GetKeyState('D') & 0x8000) {
				std::cout << "You dodged the attack!\n";
				continue;
			}
			// if A, user lost
			else if (GetKeyState('A') & 0x8000) {
				std::cout << "You dodged the wrong way and lost!\n";
				break;
			}
			// else user lost
			else {
				std::cout << "You stood still and lost!\n";
				break;
			}
		}
	}

	// if the for loop finished, user lost
	if (chanceOfWinning == 0) {
		std::cout << name << ": 5 turns are up, I win!\n";
	}
	// if the human lost, they will pay taxes
	if (!humanWin) {
		willPayTaxes = true;
	}
}

Human::~Human()
{
}
