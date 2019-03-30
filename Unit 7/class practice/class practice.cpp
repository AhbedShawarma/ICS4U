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

	Hero myHero("Cohan");
	myHero.swing();

	return 0;
}
