#include "Wolf.h"
#include <iostream>
#include <string>

Wolf::Wolf(std::string species) : species(species)
{
	if (species == "wolf") {
		std::cout << "This is a wolf given to you for help.\n";
	}
}

void Wolf::growl() {
	std::cout << "Wolf: GRRRRRRRR!\n";
}

void Wolf::howl() {
	std::cout << "Wolf: AAAWWWWOOOOOOOO!\n";
}

Wolf::~Wolf()
{
	std::cout << " has killed the wolf!\n";
}
