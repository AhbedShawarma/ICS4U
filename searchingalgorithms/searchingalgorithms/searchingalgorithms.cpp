/*
Name: Abhay Sharma
Date: April 18, 2019
Description: This program takes in a file that includes the dimensions of the maze along with a maze where walls are denoted by 'X', valid paths are ' ', and the end is '$'
			 The program then uses breadth first search to find a valid solution to get to the end of the maze from a certain starting point
			 If a valid path was found, the program outputs the coordinates of the path along with playing an animation of the path it took
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <conio.h>
#include <sstream>
#include <thread>
#include <chrono>
#include <windows.h>

std::string colourChanger(int colour = 7, std::string text = "") {
	//pre:	take in an integer for the colour and a string (it does not need to take in parameters as it will use the default parameters to change the colour to gray)
	//post:	changes the colour of the console output and returns text

	// changes the colour of the console output based on the number the user entered
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);

	return text;
}

void printMaze(std::vector<std::string>& vecToPrint, int height, int width) {
	// pre:	 takes in a vector of strings and integer height and width, assumes that height is the number of strings in vecToPrint and width is the length of each string in vecToPrint
	// post: outputs vecToPrint as a grid

	// for loop that iterates through the number of elements in vecToPrint
	for (int i = 0; i < height; i++) {
		// for loop that iterates through the number of characters in each string in vecToPrint
		for (int j = 0; j < width; j++) {
			if (vecToPrint[i][j] == 'X' || vecToPrint[i][j] == '$')
				colourChanger();
			else
				colourChanger(10);
			// outputs the character at the jth position of the string at the ith element in vecToPrint
			std::cout << vecToPrint[i][j];
		}
		// goes to next line to output the next element in vecToPrint on the next line (like a grid)
		std::cout << std::endl;
	}
	colourChanger();
}

void animatePath(int x, int y, std::string directions, std::map<char, std::pair <int, int>> &dirMap, std::map<char, char> &output, std::vector<std::string>& vecToPrint, int height, int width, int sleepTime, bool animEachFrame) {
	/* pre:	takes in integer values for x and y which should be set to the starting point of the maze, takes in a string of directions that should only contain characters d, r, u, l and $
			takes in 2 different maps, both of which use d, r, u, l and possibly $ as keys. The keys for dirMap should map to a pair of integers that represent the values that should be added to x and y
			takes in a vector of strings that needs to be printed (the maze), the width and height of the maze., the time each frame should be shown on screen (in seconds),
			and takes in a bool that changes if each step in the path should be animated individually, or if the entire path is displayed at once
	  post:	makes an animation (or simply outputs path, based on parameters) that displays a path on the screen with the coordinates of each step in the path*/
	
	// clears the screen
	system("CLS");

	// create a strigstream that stores the coordinates of the solution
	std::stringstream coords;

	// for loop that iterates through each direction in the solution to output it onto the maze
	for (int i = 0; i < directions.size(); i++) {

		// sets the character at the current coordinate corresponding to the character in the ith element of the solution
		vecToPrint[y][x] = output[directions[i]];

		// adds the current coordinates to solutionCoords
		coords << "(" << y << ", " << x << ") ";

		// adds to x and y based on the character in the ith element of the solution to know the next coordinate in the solution
		x += dirMap[directions[i]].first;
		y += dirMap[directions[i]].second;

		// if animEachFrame is true, the animate each step of the path
		if (animEachFrame) {
			// clears the screen
			system("CLS");
			// calls on printMaze to output the maze along with the current path it is taking
			printMaze(vecToPrint, height, width);
			// outputs the coordinates of the current path
			std::cout << "Current path: " << coords.str();
			// waits for a variable amount of seconds and then continues (to make an animation of the program going to each coordinate in the solution)
			std::this_thread::sleep_for(std::chrono::seconds(sleepTime));
		}
	}
	// if animEachFrame is false, show the final path
	if (!animEachFrame) {
		// calls on printMaze to output the maze along with the current path it is taking
		printMaze(vecToPrint, height, width);
		// outputs the coordinates of the current path
		std::cout << "Current path: " << coords.str();
		// waits for 1 second and then continues (to make an animation of the program going to each coordinate in the solution)
		std::this_thread::sleep_for(std::chrono::seconds(sleepTime));
	}

	// reset the maze so that the path that was displayed is no longer shown
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (vecToPrint[i][j] == '<' || vecToPrint[i][j] == '>' || vecToPrint[i][j] == '^' || vecToPrint[i][j] == 'v')
				vecToPrint[i][j] = ' ';
		}
	}
}

int main()
{
	// open the file with the maze
	std::ifstream mazeFile("maze.txt");
	// string that will store any input
	std::string input;
	// integer variables to store the maze's height and width
	int height, width;
	// vector of strings that acts as a grid to store the maze
	std::vector<std::string> maze;
	
	// read in the maze's height
	std::getline(mazeFile, input);
	// convert input to integer to store it
	height = std::stoi(input);
	// read in the maze's width
	std::getline(mazeFile, input);
	// convert input to integer to store it
	width = std::stoi(input);

	// for loop that stores each row of the maze as a string and adds the string as an element to the maze vector
	for (int i = 0; i < height; i++) {
		std::getline(mazeFile, input);
		maze.push_back(input);
	}
	// closes the file
	mazeFile.close();

	std::cout << "Welcome to the maze solving aglorithm.\nPlease enter the point where the maze begins:" << std::endl;
	// declares variables to store the starting x and y values
	int startX, startY;
	// loop that keeps looping until user enters a valid starting coordinate
	while (true) {
		// prompts user to enter starting x and y values and converts input as string to integer values so the input can be stored in startX and startY
		std::cout << "Enter the x coordinate you are starting at: ";
		std::cin >> startX;
		// keeps prompting user to input until it is an integer
		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "Enter integer values only: ";
			std::cin >> startX;
		}
		std::cout << "Enter the y coordinate you are starting at: ";
		std::cin >> startY;
		// keeps prompting user to input until it is an integer
		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "Enter integer values only: ";
			std::cin >> startY;
		}
		// if the values entered by user are out of bounds (outside of the maze's size), output that so the user knows to change their input (and change colour to red)
		if (startY > height || startY < 0 || startX > width || startX < 0)
			std::cout << colourChanger(12, "That is an invalid starting point as the coordinate is outside of the maze's size.") << std::endl;
		// if the coordinate is at a wall, output that to the user (chang colour to red)
		else if (maze[startY][startX] == 'X')
			std::cout << colourChanger(12, "That is an invalid starting point as there is a wall there.") << std::endl;
		// if the coordinate is at the treasure, output that the treasure has been found and end the program (and change colour to green)
		else if (maze[startY][startX] == '$') {
			std::cout << colourChanger(10, "Your starting point is the location of the treasure, so the treasure has been found at (") << startY << ", " << startX << ")";
			colourChanger();
			return 0;
		}
		// else the user chose a valid coordinate to start at so break out of the loop
		else
			break;
		// change the colour back to normal
		colourChanger();

	}
	// clears the screen
	system("CLS");
	// output the maze with the user's chosen staring point
	std::cout << "This is the maze and your starting point is indicated with a 'S':\n\n";
	maze[startY][startX] = 'S';
	// calls printMaze to ouptut the maze that was read
	printMaze(maze, height, width);
	
	// declare an integer to store animation method
	int typeOfAnim;
	// prompts user to enter their preferred way to see the solution and stores it
	std::cout << "\nHow would you like to display the solution?";
	std::cout << "\nEnter " << colourChanger(3, "1"); 
	std::cout << colourChanger(7, " to show all the paths the program tried before it found the solution");
	std::cout << "\nEnter " << colourChanger(5, "2");
	std::cout << colourChanger(7, " to only animate the correct path");
	std::cout << "\nEnter " << colourChanger(6, "3");
	std::cout << colourChanger(7, " to only display the correct path without animations") << std::endl;
	std::cin >> input;
	// if input is not 1, 2, or 3, keep prompting the user to only enter one of those numbers until one of the three are entered
	while (input != "1" && input != "2" && input != "3") {
		std::cout << "Only enter 1, 2, or 3 to choose how the maze's path is displayed:";
		std::cin >> input;
	}
	typeOfAnim = std::stoi(input);
	
	// waits for keypress to continue
	std::cout << "\nPress any key to start solving the maze";
	_getch();
	

	// creates a map that takes a char as a key that maps to a pair of integers
	// the map is used to change the coordinates by adding the first integer to x and second integer to y
	// these integers are based on the direction that the next coordinate is in the solution
	// for example, if the solution says go down ('d'), add 0 to x and 1 to y
	std::map<char, std::pair <int, int>> directionMap;
	directionMap['d'] = std::make_pair(0, 1);
	directionMap['r'] = std::make_pair(1, 0);
	directionMap['u'] = std::make_pair(0, -1);
	directionMap['l'] = std::make_pair(-1, 0);

	// creates a map that takes in a char as a key that maps to another char
	// this is used to ouput the correct direction arrow to the maze so the user can see the direction the solution is going in
	// for example, if the solution says go down ('d'), the corresponding output would be 'v' (downwards arrow)
	std::map<char, char> outputMap;
	outputMap['d'] = 'v';
	outputMap['r'] = '>';
	outputMap['u'] = '^';
	outputMap['l'] = '<';
	outputMap['$'] = '$';

	// creates a queue that stores the coordinates of the location in the maze that needs to be visited
	// the string stores the directions that the program has followed to get to that location (right, left, up, down)
	std::queue<std::pair <std::pair <int, int>, std::string>> nodeToVisit;
	
	// creates 2D vector of size height * width that stores if each coordinate has been visited or not, setting all values to false as default
	std::vector<bool> tempRow(width, false);
	std::vector<std::vector<bool>> isVisited(height, tempRow);

	// for loop that iterates through maze and sets all coordinates where 'X' is present to visited
	// as the program does not need to check places that are walls
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (maze[i][j] == 'X')
				isVisited[i][j] = true;
		}
	}

	// declares variables for the coordinates
	int x, y;
	// delcares a variable that stores the directions to get to the end of the maze
	std::string solution;
	// sets a bool variable to false (only true if the program reaches the end of the maze)
	bool foundEnd = false;
	// adds the coordinate (startX, startY) to the queue as it is the starting point of the maze
	nodeToVisit.push(std::make_pair(std::make_pair(startX, startY), ""));

	// for loop that only exits when nodeToVisit is empty (all values are checked), and pops off the top node for each iteration to proceed to check next node
	for (; nodeToVisit.size() > 0; nodeToVisit.pop()) {
		// sets x and y values to the coordinate values of the element at the front of nodeToVisit
		x = nodeToVisit.front().first.first;
		y = nodeToVisit.front().first.second;
		// sets path to the string of directions that reside in the front element of nodeToVisit
		std::string path = nodeToVisit.front().second;

		// if the coordinate has already been visisted, go to the next iteration of the for loop
		if (isVisited[y][x])
			continue;

		// set isVisited at the coordinate to be true to check off the node as visited
		isVisited[y][x] = true;


		// if the end of the maze is at the current coordinate,
		if (maze[y][x] == '$') {
			// set foundEnd to true
			foundEnd = true;
			// set solution to be the current path + '$'
			solution = path + "$";
			// break out of the loop
			break;
		}

		// if typeOfAnim is 1, then display each path that the program is trying to take to solve the maze
		if (typeOfAnim == 1)
			animatePath(startX, startY, path, directionMap, outputMap, maze, height, width, 1, false);


		// Set of if statements that add adjacent coordinates as nodes to nodeToVisit to continue searching for the end of the maze:
		// if the coordinate directly below the current coordinate is within the bounds of the maze,
		if (y + 1 < height)
			// add coordinate (x, y+1) to nodeToVisit and add "d" to the path (indicating to go down to get to the new coordinate)
			nodeToVisit.push(std::make_pair(std::make_pair(x, y + 1), path + "d"));
		
		// if the coordinate directly to the right of the current coordinate is within the bounds of the maze,
		if (x + 1 < width)
			// add coordinate (x+1, y) to nodeToVisit and add "r" to the path (indicating to go right to get to the new coordinate)
			nodeToVisit.push(std::make_pair(std::make_pair(x + 1, y), path + "r"));

		// if the coordinate directly above the current coordinate is within the bounds of the maze,
		if (y - 1 > 0)
			// add coordinate (x, y-1) to nodeToVisit and add "u" to the path (indicating to go up to get to the new coordinate)
			nodeToVisit.push(std::make_pair(std::make_pair(x, y - 1), path + "u"));

		// if the coordinate directly to the left of the current coordinate is within the bounds of the maze,
		if (x - 1 > 0)
			// add coordinate (x-1, y) to nodeToVisit and add "l" to the path (indicating to go left to get to the new coordinate)
			nodeToVisit.push(std::make_pair(std::make_pair(x - 1, y), path + "l"));
	}

	// foundEnd is not true, output that there is no solution and end the program
	if (!foundEnd) {
		std::cout << colourChanger(4, "\nThere is no valid solution for this maze at the given starting points.") << std::endl;
		colourChanger();
		return 0;
	}

	// if typeOfAnim equals 2, animate each frame of the maze's correct path
	if (typeOfAnim == 2)
		animatePath(startX, startY, solution, directionMap, outputMap, maze, height, width, 1, true);
	// else, only display the correct path
	else
		animatePath(startX, startY, solution, directionMap, outputMap, maze, height, width, 1, false);

	return 0;
}