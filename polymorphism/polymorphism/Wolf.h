#pragma once
#include <string>

class Wolf
{
protected:
	std::string species;
public:
	Wolf(std::string species);
	void growl();
	void howl();
	virtual ~Wolf();
};

