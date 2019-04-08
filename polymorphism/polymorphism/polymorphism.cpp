#include <iostream>
#include "Citizen.h"
#include "Human.h"
#include "Zombie.h"
#include "Nobbs.h"
#include "Vampire.h"
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));
	Citizen::citizens.push_back(new Human("bob", "human"));
	
	return 0;
}



