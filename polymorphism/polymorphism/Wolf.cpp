#include "Wolf.h"
#include <iostream>
#include <string>

Wolf::Wolf(std::string species) : species(species)
{
	// pre: takes in string species as input
	// post: stores parameter as species memeber variable and outputs a wolf is created based on its species
	if (species == "wolf") {
		std::cout << "This is a wolf given to you for help.\n";
	}
}

void Wolf::growl() {
	// pre:  none
	// post: wolf growls
	std::cout << "Wolf: GRRRRRRRR!\n";
}

void Wolf::howl() {
	// pre:  none
	// post: wolf howls
	std::cout << "Wolf: AAAWWWWOOOOOOOO!\n";
}

Wolf::~Wolf()
{
	// outputs which type of wolf fainted
	if (species == "werewolf") {
		std::cout << " has made the werewolf faint!\n";
	}
	else {
		std::cout << " has made the wolf faint!\n";
	}
}
