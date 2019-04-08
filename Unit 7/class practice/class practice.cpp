#include "pch.h"
#include <iostream>
#include <string>
#include "Hero.h"
#include "Sword.h"
#include <time.h>

using namespace std;


int main()
{
	srand(time(NULL));

	Hero bob("Bob");
	Sword ex("Excalibur", 0, 5);
	Sword exV2("Excalibur V2", 100, 200);

	bob.swing();
	bob.equip(ex);
	bob.swing();
	bob.swing();
	bob.equip(exV2);
	bob.swing();

	return 0;
}
