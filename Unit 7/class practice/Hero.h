#pragma once

#include <string>
#include "Sword.h"

class Hero
{
public:
	Hero(std::string name);
	// destructor
	virtual ~Hero();
	void swing();
	void equip(Sword& toEquip);

protected:


private:
	std::string name;
	int strength;
	Sword* mySword;

};

