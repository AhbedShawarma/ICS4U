#include "Human.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include <conio.h>

Human::Human(std::string name, std::string species, int happiness, int easeOfAnger, int strength) : Citizen(name, species, happiness, easeOfAnger, strength)
{
	currency = "dollars";
}

void Human::speak() {
	if (happiness > easeOfAnger) {
		std::cout << name << ": Sup dude.\n";
	}
	else {
		willPayTaxes = false;
		std::cout << name << ": You ain't being to nice man, I'm upset! I'll stop paying taxes unless you beat me in a duel.\n";
	}
}

void Human::thank() {
	std::cout << name << ": You a real brotha!\n";
	happiness += 20;
}

void Human::action() {
	std::cout << name << ": Get ready! I'll only pay taxes if you beat me.\n";
	std::cout << "PRESS W to attack, A to dodge left, D to dodge right.\n";
	bool humanWin = false;
	int chanceOfKilling = 1;
	for (int chanceOfWinning = 5; chanceOfWinning > 0; chanceOfWinning--, chanceOfKilling++) {
		int move = rand() % 3 + 1;
		if (move == 1) {
			std::cout << "The opponent attacked head on!\n";
			_getch();
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
			else if ((GetKeyState('A') & 0x8000) || (GetKeyState('D') & 0x8000)) {
				std::cout << "You dodged the attack!\n";
				continue;
			}
			else {
				std::cout << "You stood still and lost!\n";
				break;
			}
		}
		else if (move == 2) {
			std::cout << "The opponent attacked from the right!\n";
			_getch();
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
			else if (GetKeyState('A') & 0x8000) {
				std::cout << "You dodged the attack!\n";
				continue;
			}
			else if (GetKeyState('D') & 0x8000) {
				std::cout << "You dodged the wrong way and lost!\n";
				break;
			}
			else {
				std::cout << "You stood still and lost!\n";
				break;
			}
		}
		else if (move == 3) {
			std::cout << "The opponent attacked from the left!\n";
			_getch();
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
			else if (GetKeyState('D') & 0x8000) {
				std::cout << "You dodged the attack!\n";
				continue;
			}
			else if (GetKeyState('A') & 0x8000) {
				std::cout << "You dodged the wrong way and lost!\n";
				break;
			}
			else {
				std::cout << "You stood still and lost!\n";
				break;
			}
		}
	}
	if (!humanWin) {
		happiness += 100 - easeOfAnger;
		willPayTaxes = true;
		if (rand() % chanceOfKilling) {
			std::cout << "You killed " << name << " in the aftermath!\n";
			for (int i = 0; i < citizens.size(); i++) {
				if (citizens[i]->getName() == getName()) {
					delete citizens[0];
					citizens.erase(citizens.begin() + i);
				}
			}
		}
	}
}

Human::~Human()
{
	std::cout << name << "has been killed!\n";
}
