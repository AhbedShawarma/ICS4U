/*
Name:			Abhay Sharma
Date:			February 15 2019
Description:	This program reads in input from a file whose first line is the number of officers and the following 2 lines are the names of the officers where the ith officer in the top row is partnered
				with the ith offier in the bottom row. The program checks all the pairs of officers and will output good if the officers pairings are consistent (a matches with b and b matches with a) or will output
				bad if they are inconsistent (a matches with b, b matches with c)
*/

#include "pch.h"
#include <iostream>	// for console input and output
#include <fstream>	// for reading in from a file
#include <string>	// for string manipulation
#include <algorithm>// for find() and distance() functions

using namespace std;

int main()
{
	// declares number of names variable
	int numOfNames;

	// allows input access from .txt file through a file object
	ifstream file("test.txt");

	// reads in number of names from the first line of the file
	file >> numOfNames;

	// creates two dynamically sized arrays of length numOfNames that will store officer names
	string* firstRow = new string[numOfNames];
	string* secondRow = new string[numOfNames];

	// a for loop that adds each name in the first row to an array
	for (int i = 0; i < numOfNames; i++) {
		file >> firstRow[i];
	}
	// a for loop that adds each name in the second row to an another array
	for (int i = 0; i < numOfNames; i++) {
		file >> secondRow[i];
	}

	// outputs bad if there is an odd number of officers and exits the program since there will never be consistent partners
	if (numOfNames % 2 != 0) {
		cout << "bad" << endl << "Since there is an odd number of officers, all of them can not have matching partners.";
		return 0;
	}

	// a for loop that loops for every name there is to check if the officer pairs are consistent or not
	for (int i = 0; i < numOfNames; i++) {
		// if an officer is paired with themself, outputs bad, why it is bad and exits the program
		if (firstRow[i] == secondRow[i]) {
			cout << "bad" << endl << "The output is bad because officer " << firstRow[i] << " is partnered with themself.";
			return 0;
		}
		// if the location of the name that is in the ith position of the second row in the first row is not equal 
		// to the location of the name that is in the ith position of the first row in the second row,
		// output bad since there is an inconsistent pair, output why it is inconsistent and end the program
		if (distance(firstRow, find(firstRow, firstRow + numOfNames, secondRow[i])) != distance(secondRow, find(secondRow, secondRow + numOfNames, firstRow[i]))) {
			cout << "bad" << endl << "The output is bad because officer " << firstRow[i] << " is partnered with " << secondRow[i] << " but officer " << firstRow[distance(firstRow, find(firstRow, firstRow + numOfNames, secondRow[i]))] << " is partnered with " << secondRow[distance(firstRow, find(firstRow, firstRow + numOfNames, secondRow[i]))];
			return 0;
		}
	}

	// output good if the for loop is completed 
	cout << "good" << endl;

	// deletes dynammically allocated arrays
	delete[] firstRow;
	delete[] secondRow;

	return 0;
}
