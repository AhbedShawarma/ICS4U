/*
Name:		 Abhay Sharma
Date:		 February 4, 2019
Description: The program prompts the user to play a game that involves the user trying to guess
			 a code of 4 elements, after every guess, there will be a hint displayed to the user
			 that indicates how many elements in their guess are the same element in the correct
			 location and how many are in the password but not in the same location.
			 The user can choose to play as many times as they want and they can choose their
			 difficulty level which can change their hint or the number of guesses they have.
*/

#include "pch.h"
#include <iostream> // for console input and output
#include <ctime> // for srand which generates random numbers every run of the program
#include <string> // to work with strings
#include <windows.h> // windows api header
#include <algorithm> // for find function


using namespace std;

void instructionsDisplayer(string input, HANDLE colour) {
	//pre:	takes in user input to check if they want instructions
	//post:	if user input equals "I", outputs instructions
	SetConsoleTextAttribute(colour, 4);

	if (input == "I") {
		cout << "\nINSTRUCTIONS: \n";
		cout << "You must find the correct order to use four spells to stop the golems. These spells are \n" 
			<< "based on the 4 elements, Fire, Water, Air, and Earth. The order only consists of the 4 \n"
			<< "elemental spells but there could be duplicates so not all 4 must be present in the \n"
			<< "correct order. Fortunately, the golems have eyes that will glow in a way that will give \n" 
			<< "you some clues. Their eyes will glow RED for each element that is in the correct \n" 
			<< "location.Their eyes will glow BLUE for each element that is correctly included, but in \n" 
			<< "the wrong location. You will enter your guess which will consist of 4 letters, F for \n" 
			<< "fire, W for water, A for air, and E for earth and you will recieve a hint consisting \n" 
			<< "of Rs and Bs. \n\n\n";
	}
	SetConsoleTextAttribute(colour, 4);

}

void toUpperCase(string &str) {
	//pre:	The function takes in a string as a reference that needs to have its letters be changed to uppercase
	//post:	The function changes all characters in the string to uppercase

	for (int i = 0; i < str.length(); i++) {
		str[i] = toupper(str[i]);
	}

}

bool inputChecker(int length, string validInput, string input) {
	//pre:	takes in the user input that needs to be checked, the length of the appropriate input, and a string containing the characters allowed in the input
	//post:	the function returns true if the input is valid and false if it is invalid

	// checks if the length of the user input matches with the valid length, returns false if they are not equal in length
	if (input.length() != length) {
		return false;
	}
	// a for loop that runs for every character of input and checks if each character of user input is found in the string of valid input
	// if a character is not found, the function returns false
	for (int i = 0; i < length; i++) {
		if (validInput.find(input[i]) == std::string::npos) {
			return false;
		}
	}
	// if the input passes the if statement and for loop, it means that it is valid so the function returns true
	return true;
}

string hintMaker(string password, string guess, string difficulty) {
	//pre:	the function takes in the password and a valid user guess and valid user input of the difficulty level
	//post:	the function returns a hint of Rs and Bs, R indicating an element in the guess is present in the password at the same location
	//		and B indicating that an element in the guess is present in the password but not in the same spot
	//		there will also be an X in the hint indicating that an element is not present in the password if the user chose the easy difficulty

	// declares both types of hints
	string easyHint = "XXXX";
	string mediumHint;

	// a for loop that runs for each character of input, if the character at the ith position is the same for both the guess and password,
	// 'R' is added to the hint and that character is changed to an arbitrary character in both the password and the guess (but different for
	// both of them and one that is not possible to be in the guess or password) so the function does not add a 'B' to the guess in the next loop
	// when checking through the characters again
	for (int i = 0; i < guess.size(); i++) {
		if (password[i] == guess[i]) {
			easyHint[i] = 'R';
			mediumHint += "R";
			password[i] = '?';
			guess[i] = '-';
		}
	}

	// a for loop that runs for each character of input, if the character in the ith position of guess is found in the password, 'B' is added to the
	// hint and the character that was found in the password is changed to the same arbitrary character as in the previous for loop so that it is not
	// checked again
	for (int i = 0; i < guess.length(); i++) {
		size_t found = password.find(guess[i]);
		if (found != std::string::npos) {
			mediumHint += "B";
			easyHint[i] = 'B';
			password[found] = '?';
		}
	}

	// returns the hint corresponding to the difficulty level
	if (difficulty == "E") {
		return easyHint;
	}

	return mediumHint;
}

string passwordCreator() {
	//pre:	none
	//post:	returns a randomly generated character for the password

	// generates a random number from 0 to 3
	int randomNum = (rand() % 4);

	string element;
	// switch statement that changes the letter of the element based on the nummber that was randomly generated
	switch (randomNum) {
	case 0: element = "F";
		break;
	case 1: element = "W";
		break;
	case 2: element = "A";
		break;
	case 3: element = "E";
		break;
	}
	// returns the element
	return element;
}

void secretHintMaker(string password, string guess, HANDLE consoleColour) {
	//pre:	the function takes in the password and a valid user guess
	//post: the function outputs if the selected element is either in the correct location, present in the password but not in the correct locatio, or if it is not present in the password

	// declares a string to store user input
	string hintLetter;
	// declares and initializes a string that stores valid user input
	string hintInput = "0123";

	// prompts user to input the element they would like the hint for
	cout << "Which element would you like to know about, try inputting 0 for " << guess[0] << ", 1 for " << guess[1] << ", 2 for " << guess[2] << ", or 3 for " << guess[3] << ": ";
	cin >> hintLetter;
	// only capatilizes input in the case of the user entering "i" for instructions
	toUpperCase(hintLetter);

	// a do while loop that keeps letting the user input and only exits when the user enters a valid input
	while (!(inputChecker(1, hintInput, hintLetter))) {
		// calls on instructionsDisplayer to output instructions if the user wanted them
		instructionsDisplayer(hintLetter, consoleColour);
		if (hintLetter != "I") {
			cout << "INVALID ENTRY!" << endl;
		}
		cout << "Which element would you like to know about, try inputting 0 for " << guess[0] << ", 1 for " << guess[1] << ", 2 for " << guess[2] << ", or 3 for " << guess[3] << ": ";
		cin >> hintLetter;
		toUpperCase(hintLetter);
	}

	// stores user input as an int
	int hintLocation = stoi(hintLetter);
	// calls hintMaker at easy difficulty to find if the element the user chose is 'R', 'B', or 'X'
	string hint = hintMaker(password, guess, "E");
	// set of if statements that output the hint by checking if the element is 'R', 'B', or 'X'
	if (hint[hintLocation] == 'R') {
		cout << "That element is in the correct location." << endl;
	}
	else if (hint[hintLocation] == 'B') {
		cout << "That element is included in the password but is not at the correct location." << endl;
	}
	else {
		cout << "That element is not in the password." << endl;
	}
}


int main()
{
	// enables changing the colour for console output
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// makes sure there is a random seed everytime the program is run so the password is truly random
	srand(time(0));

	// declares variables that will store user input
	string userGuess;
	string difficulty;
	string playAgain;
	string instructions;

	// declares variables for hint and the number of guesses the user will receive
	string hint;
	int numOfGuesses;

	// declares and initializes strings that store the valid user input for the different inputs the user will be asked to enter
	string validYNInput = "YN";
	string validDifficultyInput = "EMH";
	string validPasswordInput = "FWAE";

	// an introduction to the game with the instructions
	cout << "WELCOME TO GOLEMS: \n"
		<< "You, as the city watch of Ankh Morpork have to use control spells to disable the golems before they destroy the city. \n" << endl;



	// a do while loop that will only exit when the user says that they no longer want to play
	do {
		// creates the password and stores it in a string
		string password = passwordCreator() + passwordCreator() + passwordCreator() + passwordCreator();

		// asks the user if they want instructions and capitalizes input
		cout << "Enter \"I\" for instructions (you can enter \"I\" at any time to receive instructions: ";
		cin >> instructions;
		toUpperCase(instructions);
		// calls on instructionsDisplayer to output instructions if the user wanted them
		instructionsDisplayer(instructions, hConsole);

		// difficulty descriptions, prompts the user to enter their preferred difficulty
		cout << "Choose your difficulty \n"
			<< "E - Easy: \n"
			<< "Each hint tells you which letters in your guess are in the correct place, correctly included,\n"
			<< "or if they are not in the hint by outputting X. You get 10 tries to guess the password. \n"
			<< "M - Medium: \n"
			<< "Each hint tells you if any letters are in the correct place or correctly included. \n"
			<< "You get 10 tries to guess the password (plus you might get a bonus hint). \n"
			<< "H - Hard: \n"
			<< "Each hint tells you if any letters are in the correct place or correctly included. \n"
			<< "You get 5 tries to guess the password."
			<< endl;

		// stores the user input in a variable and makes it all uppercase
		cin >> difficulty;
		toUpperCase(difficulty);

		// a while loop that checks if the user input is valid and keeps prompting the user to enter until they enter a valid response
		while (!(inputChecker(1, validDifficultyInput, difficulty))) {
			// calls on instructionsDisplayer to output instructions if the user wanted them
			instructionsDisplayer(difficulty, hConsole);
			if (difficulty != "I") {
				cout << "INVALID ENTRY!" << endl;
			}
			cout << "Choose your difficulty (Enter E, M, or H): ";
			cin >> difficulty;
			toUpperCase(difficulty);
		}

		// changes the number of user guesses depending on their selected difficulty
		if (difficulty == "H") {
			numOfGuesses = 5;
		}
		else {
			numOfGuesses = 10;
		}

		// a while loop that keeps looping until the user it out of guesses or it will exit early if the user guesses the correctly
		while (numOfGuesses--) {

			// prompts the user to enter their guess and stores it with all charactes being uppercase
			cout << "Enter the password: ";
			cin >> userGuess;
			toUpperCase(userGuess);

			// a while loop that checks if the user input is valid and keeps prompting the user to enter until they enter a valid response
			while (!(inputChecker(4, validPasswordInput, userGuess))) {
				// calls on instructionsDisplayer to output instructions if the user wanted them
				instructionsDisplayer(userGuess, hConsole);
				if (userGuess != "I") {
					cout << "INVALID ENTRY!" << endl;
				}
				cout << "The password is 4 letters long, using only the characters F, W, A, and E." << endl;
				cout << "Enter the password: ";
				cin >> userGuess;
				toUpperCase(userGuess);
			}

			// calls hintMaker to create the hint and stores it as a variable
			hint = hintMaker(password, userGuess, difficulty);

			// a for loop that loops for every character in the hint and changes the colour of the output according to the letter, red for 'R', blue for 'B' and grey for 'X'
			for (int x = 0; x < hint.length(); x++) {
				if (hint[x] == 'R') {
					SetConsoleTextAttribute(hConsole, 4);
					cout << hint[x];
				}
				else if (hint[x] == 'B') {
					SetConsoleTextAttribute(hConsole, 9);
					cout << hint[x];
				}
				else {
					SetConsoleTextAttribute(hConsole, 7);
					cout << hint[x];
				}
			}

			// sets the output colour back to grey
			SetConsoleTextAttribute(hConsole, 7);
			cout << "\n";

			// if the user guessed correctly, so the hint is "RRRR", a "you win" message is outputted and the looping ends
			if (hint == "RRRR") {
				cout << "CONGRATULATIONS! \n"
					<< "You casted the spells in the correct order and disabled the golems to save the city!" << endl;
				break;
			}

			// if the user is on their fith guess and have chosen medium difficulty, the user is prompted with a secret hint
			if (numOfGuesses == 5 && difficulty == "M") {
				cout << "Psst, hey there, you only have 5 guesses remaining, I'll give you a bonus hint about the password based on the elements you just guessed." << endl;
				secretHintMaker(password, userGuess, hConsole);
			}
		}

		// if all of the user used all of their guesses and did not get the password, a "you lose" message is outputted
		if (hint != "RRRR") {
			cout << "OH NO! \n"
				<< "You have failed us all! The golems are going to destroy the city!" << endl;
		}

		// prompts the user to enter if they want to play again
		cout << "Do you want to play again? Enter Y for yes, N for no: ";
		cin >> playAgain;
		toUpperCase(playAgain);

		// a while loop that checks if the user input is valid and keeps prompting the user to enter until they enter a valid response
		while (!(inputChecker(1, validYNInput, playAgain))) {
			cout << "INVALID ENTRY!" << endl;
			cout << "Do you want to play again? Enter Y for yes, N for no: ";
			cin >> playAgain;
			toUpperCase(playAgain);
		}

	} while (playAgain == "Y");

	return 0;
}
