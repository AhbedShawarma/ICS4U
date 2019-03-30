#include "pch.h"
#include "Sword.h"

#include <string>;
#include <iostream>

Sword::Sword(std::string name, int lower, int upper) : name(name), lower(lower), upper(upper)
{
	std::cout << name << " has been forged!" << std::endl;
}

int Sword::getDamage() {
	return rand() % (upper - lower + 1) + lower;
}

Sword::~Sword()
{
}
