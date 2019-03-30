#include "pch.h"
#include "Hero.h"

#include <iostream>
#include <string>


Hero::Hero(std::string name) : name(name), mySword(NULL)
{
	// rand int, remainder when you divide by 9 (0 to 8) then add 10 so you have values 10 to 18
	strength = rand() % 9 + 10;
	std::cout << name << " arrives with strength " << strength << std::endl;
}

void Hero::equip(Sword& toEquip) {
	mySword = &toEquip;
	std::cout << name << " holds " << mySword->name << " aloft!" << std::endl;
}

void Hero::swing() {
	if (mySword == NULL) {
		std::cout << name << " swings their arm through the air ..." << std::endl;
	}
	else {
		int totalDamage = strength / 2 + mySword->getDamage();
		std::cout << name << " swings " << mySword->name << " and does " << totalDamage << " damage." << std::endl;
	}
}

Hero::~Hero()
{
}
