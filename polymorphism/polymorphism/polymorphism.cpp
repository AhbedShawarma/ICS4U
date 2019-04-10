#include <iostream>
#include "Citizen.h"
#include "Human.h"
#include "Zombie.h"
#include "Nobbs.h"
#include "Vampire.h"
#include <time.h>
#include <Windows.h>
#include <conio.h>

using namespace std;

int main()
{
	srand(time(NULL));
	Citizen::citizens.push_back(new Human("bob", "human"));
	Citizen::citizens.push_back(new Zombie("z", "zombie"));
	Citizen::citizens.push_back(new Vampire("v", "vampire"));
-


	return 0;
}



