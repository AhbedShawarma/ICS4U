#pragma once

#include <string>

class Sword
{
public:
	Sword(std::string, int lower, int upper);
	virtual ~Sword();
	std::string name;
	int getDamage(); 

private:
	int lower;
	int upper;


};
