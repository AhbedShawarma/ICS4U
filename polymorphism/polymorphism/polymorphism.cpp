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

using namespace std;

int main()
{
	srand(time(NULL));
	Citizen::citizens.push_back(new Human("bob", "human"));
	Citizen::citizens.push_back(new Zombie("z", "zombie"));
	Citizen::citizens.push_back(new Vampire("v", "vampire"));
	Citizen::citizens.push_back(new Werewolf("w", "werewolf"));

	Citizen::citizens[3]->speak();

	return 0;
}



