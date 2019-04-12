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
#include <stdlib.h>

using namespace std;

void attack(Citizen* citizen, bool isCitizenAttacking) {
	//pre:	Takes in a citizen object and a bool
	//post:	outputs if the citizen won or the wolf won and deletes and erases the object that lost from its vector
	
	// if citizen is attacking, output it
	if (isCitizenAttacking) {
		std::cout << citizen->getName() << " attacked out of anger!\n";
		std::cout << "Your wolves defend you!\n";
	}
	// else output wolf is attacking
	else {
		std::cout << "You attack " << citizen->getName() << " with your wolf\n";
	}
	// make the wolf howl and growl
	Citizen::wolves[0]->howl();
	Citizen::wolves[0]->growl();

	// if statement that decides if the citizen lives or not based on random number generation, higher chance to live based on the citizen's strength
	if ((rand() % citizen->getStrength() + 1) > 20) {
		// if citizen lives, wolf faints so deletes the wolf and erases it from the vector of wolves
		cout << citizen->getName();
		delete Citizen::wolves[0];
		Citizen::wolves.erase(Citizen::wolves.begin());
	}
	// else, the wolf lives
	else {
		// for loop that iterates through the vector of citizens and deletes the one that fainted along with erasing the citizen from the citizens vector
		for (int i = 0; i < Citizen::citizens.size(); i++) {
			if (Citizen::citizens[i]->getName() == citizen->getName()) {
				delete Citizen::citizens[i];
				Citizen::citizens.erase(Citizen::citizens.begin() + i);
				break;
			}
		}
	}
}


int main()
{
	// for random numbers everytime
	srand(time(NULL));

	// introduces the user to their job
	cout << "Hello tax collector, your job is to collect tax 40 times from citizens over the year.\n"
		<< "to do so, you are given 3 wolves that you can threaten the citizens with. Be careful\n"
		<< "the citizens get angry and can attack or ask you for favours. If you loose all of your\n"
		<< "wolves, or if all of the citizens faint, or if you fail to collect tax 40 times, you will\n"
		<< "be fired. Good luck!\n\n";

	// creates the citizens and adds them to the citizens vector
	cout << "Here are the citizens:\n";
	Citizen::citizens.push_back(new Human("Bobby the Human", "human"));
	Citizen::citizens.push_back(new Zombie("Zarr the Zombie", "zombie"));
	Citizen::citizens.push_back(new Vampire("Dracula the Vampire", "vampire"));
	Citizen::citizens.push_back(new Werewolf("Terminus the Werewolf", "werewolf"));
	Citizen::citizens.push_back(new Nobbs("Viktor the Nobbs", "nobbs"));
	Citizen::citizens.push_back(new Troll("Grohk the Troll", "troll"));
	Citizen::citizens.push_back(new Dwarf("Barick the Dwarf", "dwarf"));

	// creates the wolves and adds them to the wolves vector
	cout << "You have 3 wolves as well:\n";
	Citizen::wolves.push_back(new Wolf("wolf"));
	Citizen::wolves.push_back(new Wolf("wolf"));
	Citizen::wolves.push_back(new Wolf("wolf"));

	// waits for key input to proceed
	cout << "\nPress any key to proceed to start";
	_getch();
	// clears the screen
	system("CLS");

	// variable that sets how many times tax needs to be collected
	int numOfTaxToBeCollected = 40;
	
	// for loop that iterates through the months (12 times), will break out if the citizens vector or wolves vector is empty or if enough taxes have been paid
	for (int month = 1; month < 13 && Citizen::citizens.size() > 0 && Citizen::numOfTaxesCollected < numOfTaxToBeCollected && Citizen::wolves.size() > 0; month++) {
		
		
		// for loop that iterates through each index in the citizens vector, or if the citizens vector is not empty or if wolves vector is not empty or if not enough taxes have been collected
		for (int i = 0; i < Citizen::citizens.size() && Citizen::citizens.size() > 0 && Citizen::numOfTaxesCollected < numOfTaxToBeCollected && Citizen::wolves.size() > 0; i++) {
			
			// sets the current size of the citizens vector as a variable to later check if any citizen was erased from the vector
			int numOfCitizens = Citizen::citizens.size();

			// outputs the current month and times that taxes have been collected
			cout << "Month: " << month << " / 12" << endl;
			cout << "Number of times tax is collected: " << Citizen::numOfTaxesCollected << " / " << numOfTaxToBeCollected << endl;
			// declares variable for user input
			char userAns;
			cout << endl;
			// makes the citizen at i speak
			Citizen::citizens[i]->speak();
			// if statements that checks if the citizen can pay tax
			if (Citizen::citizens[i]->checkIfPaysTax()) {
				// if the citizen can pay tax, prompts user to ask the citizen to pay tax or not
				cout << "Ask to pay tax? (y = yes, n = no): ";
				cin >> userAns;
				// if user enters y or Y, call the payTax function
				if (userAns == 'y' || userAns == 'Y') {
					// store the payTax function's return value
					int citizenResponse = Citizen::citizens[i]->payTaxes();
					// if the return value is 1, then call attack with the citizen at i attacking the user
					if (citizenResponse == 1) {
						attack(Citizen::citizens[i], true);
					}
					// if the return value is 2, prompt user to threaten citizen
					if (citizenResponse == 2) {
						std::cout << "Would you like to threaten the citizen? (y = yes, n = no): ";
						cin >> userAns;
						// if user chose to threaten citizen, call the payTax function with isThreatend true to make the citizen pay
						if (userAns == 'y' || userAns == 'Y') {
							Citizen::citizens[i]->isThreatened = true;
							Citizen::citizens[i]->payTaxes();
							// set is threatened to false again
							Citizen::citizens[i]->isThreatened = true;
						}
					}
				}
				// if user did not choose to make the citizen pay tax, call the thank function of the citizen
				else {
					Citizen::citizens[i]->thank();
				}
			}
			// else if triggerAction is true
			else if (Citizen::citizens[i]->triggerAction) {
				// prompt user to either accept or decline the citizen's request or attack the citizen
				cout << "What do you do? (enter y to accept, n to refuse, a to attack with your wolf): " << endl;
				cin >> userAns;
				// if the user accepts the request, call the citizen's action function and set triggerAction to false
				if (userAns == 'y' || userAns == 'Y') {
					Citizen::citizens[i]->triggerAction = false;
					Citizen::citizens[i]->action();
				}
				// if the user attacks, call the attack function with the citizen at i no being the attacker and set triggerAction to false
				else if (userAns == 'a' || userAns == 'A') {
					Citizen::citizens[i]->triggerAction = false;
					attack(Citizen::citizens[i], false);
				}
				// else set triggerAction to false
				else {
					Citizen::citizens[i]->triggerAction = false;
				}

			}
			// else if the citizen is unable to pay tax, output that they cannot pay tax
			else {
				cout << Citizen::citizens[i]->getName() << " no longer pays tax." << endl;
			}

			// if the current size of the vector is less than the stored size, it means a value was erased from the citzens vector
			// since there can only be 1 value erased each time (nowhere in my functions is more than one citizen fainting), 
			//subtract i by 1 so the next iteration of the for loop does not skip any citizens
			if (Citizen::citizens.size() < numOfCitizens) {
				i--;
			}

			// wait for key press
			cout << "\nPress any key to proceed to the next citizen.\n";
			_getch();
			// clear the screen
			system("CLS");
		}
		// show the month's statistics
		cout << "Here is your last month's statistics:\n";
		cout << "Month: " << month << " / 12" << endl;
		cout << "Number of times tax is collected: " << Citizen::numOfTaxesCollected << " / " << numOfTaxToBeCollected << endl;
		// wait for key press
		cout << "\nPress any key to proceed to the next month";
		_getch();
		// clear the screen
		system("CLS");
	}
	
	// if enought taxes are collected, output the user got a promotion
	if (Citizen::numOfTaxesCollected >= numOfTaxToBeCollected) {
		cout << "You have colleceted enough tax over the year, you got a promotion!" << endl;
	}
	// if all the citizens fainted, output the user is fired
	else if (Citizen::citizens.size() == 0) {
		cout << "All of your citizens have fainted, you are fired." << endl;
	}
	// if all the wolves fainted, output the user is fired
	else if (Citizen::wolves.size() == 0) {
		cout << "All of your wolves have fainted, you have no control over the citizens, you are fired." << endl;
	}
	// else, not enough money was collected, so the user is fired
	else {
		cout << "You have failed to collect enough tax, you are fired" << endl;
	}

	return 0;
}



