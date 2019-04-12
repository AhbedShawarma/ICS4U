#include <iostream>
#include "Citizen.h"
#include "Human.h"
#include "Zombie.h"
#include "Nobbs.h"
#include "Vampire.h"
#include "Werewolf.h"
#include "Dwarf.h"
#include "Troll.h"
#include "Wolf.h"
 
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>	// for clearing the screen

using namespace std;


void attack(Citizen* attacker) {

	std::cout << attacker->getName()<< " attacked out of anger!\n";

	if ((rand() % attacker->getStrength() + 1) > 20) {
		cout << attacker->getName();
		delete Citizen::wolves[0];
		Citizen::wolves.erase(Citizen::wolves.begin());
	}
	else {
		//std::cout << name << " has been killed by the wolf!\n";
		for (int i = 0; i < Citizen::citizens.size(); i++) {
			if (Citizen::citizens[i]->getName() == attacker->getName()) {
				delete Citizen::citizens[i];
				Citizen::citizens.erase(Citizen::citizens.begin() + i);
				break;
			}
		}
	}
}


int main()
{
	srand(time(NULL));

	cout << "Hello tax collector, your job is to collect tax 40 times from citizens over the year.\n"
		<< "to do so, you are given 3 wolves that you can threaten the citizens with. Be careful\n"
		<< "the citizens get angery and can attack or ask you for favours. If you loose all of your\n"
		<< "wolves, or if all of the citizens faint, or if you fail to collect tax 40 times, you will\n"
		<< "be fired. Good luck!\n\n";

	cout << "Here are the citizens:\n";
	Citizen::citizens.push_back(new Human("Bobby the Human", "human"));
	Citizen::citizens.push_back(new Zombie("Zarr the Zombie", "zombie"));
	Citizen::citizens.push_back(new Vampire("Dracula the Vampire", "vampire"));
	Citizen::citizens.push_back(new Werewolf("Terminus the Werewolf", "werewolf"));
	Citizen::citizens.push_back(new Nobbs("Viktor the Nobbs", "nobbs"));
	Citizen::citizens.push_back(new Troll("Grohk the Troll", "troll"));
	Citizen::citizens.push_back(new Dwarf("Barick the Dwarf", "dwarf"));

	cout << "You have 3 wolves as well:\n";
	Citizen::wolves.push_back(new Wolf("wolf"));
	Citizen::wolves.push_back(new Wolf("wolf"));
	Citizen::wolves.push_back(new Wolf("wolf"));

	cout << "\nPress any key to proceed to start";
	_getch();
	system("CLS");

	int numOfTaxToBeCollected = 40;
	
	for (int month = 1; month < 13 && Citizen::citizens.size() > 0 && Citizen::numOfTaxesCollected <= numOfTaxToBeCollected && Citizen::wolves.size() > 0; month++) {
		int numOfCitizens = Citizen::citizens.size();
			
		for (int i = 0; i < Citizen::citizens.size(); i++) {
			cout << "Month: " << month << " / 12" << endl;
			cout << "Number of times tax is collected: " << Citizen::numOfTaxesCollected << " / " << numOfTaxToBeCollected << endl;
			char userAns;
			cout << endl;
			Citizen::citizens[i]->speak();
			if (Citizen::citizens[i]->checkIfPaysTax()) {
				cout << "Ask to pay tax? (y = yes, n = no) ";
				cin >> userAns;
				if (userAns == 'y' || userAns == 'Y') {
					int citizenResponse = Citizen::citizens[i]->payTaxes();
					if (citizenResponse == 1) {
						attack(Citizen::citizens[i]);
					}
					if (citizenResponse == 2) {
						std::cout << "Would you like to threaten the citizen? (y = yes, n = no)";
						cin >> userAns;
						if (userAns == 'y' || userAns == 'Y') {
							Citizen::citizens[i]->isThreatened = true;
							Citizen::citizens[i]->payTaxes();
							Citizen::citizens[i]->isThreatened = true;
						}
					}
				}
				else {
					Citizen::citizens[i]->thank();
				}
			}
			else if (Citizen::citizens[i]->triggerAction/* && !(Citizen::citizens[i]->checkIfPaysTax())*/){
				cout << "What do you do? (press y to accept, n to refuse, a to attack with your wolf) " << endl;
				cin >> userAns;
				if (userAns == 'y' || userAns == 'Y') {
					Citizen::citizens[i]->triggerAction = false;
					Citizen::citizens[i]->action();
				}
				else if (userAns == 'a' || userAns == 'A') {
					Citizen::citizens[i]->triggerAction = false;
					attack(Citizen::citizens[i]);
				}
				else {
					Citizen::citizens[i]->triggerAction = false;
				}
			}
			else {
				cout << Citizen::citizens[i]->getName() << " no longer pays tax." << endl;
			}

			if (Citizen::citizens.size() < numOfCitizens) {
				i--;
			}


			cout << "\nPress any key to proceed to the next citizen.\n";
			_getch();

			system("CLS");
		}
		cout << "Here is your last month's statistics:\n";
		cout << "Month: " << month - 1 << " / 12" << endl;
		cout << "Number of times tax is collected: " << Citizen::numOfTaxesCollected << " / " << numOfTaxToBeCollected << endl;

		cout << "\nPress any key to proceed to the next month";
		_getch();

		system("CLS");
	}

	if (Citizen::numOfTaxesCollected >= numOfTaxToBeCollected) {
		cout << "You have colleceted enough tax over the year, you got a promotion!" << endl;
	}

	else {
		cout << "You have failed to collect enough tax, you are fired" << endl;
	}

	if (Citizen::citizens.size() == 0) {
		cout << "All of your citizens have fainted, you are fired." << endl;
	}

	if (Citizen::wolves.size() == 0) {
		cout << "All of your wolves have fainted, you are fired." << endl;
	}


	return 0;
}



