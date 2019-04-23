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

	std::cout << "This is the maze that the file contained:" << std::endl;
	// calls printMaze to ouptut the maze that was read
	printMaze(maze, height, width);
	// waits for keypress to continue
	std::cout << "Press any key to start solving the maze";
	_getch();


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
	// adds the coordinate (1, 1) to the queue as it is the starting point of the maze
	nodeToVisit.push(std::make_pair(std::make_pair(1, 1), ""));

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
		std::cout << "no valid solution" << std::endl;
		return 0;
	}

	// set x and y to 1 (the starting coordinate)
	x = 1;
	y = 1;

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
	outputMap['$'] = '#';

	// create a strigstream that stores the coordinates of the solution
	std::stringstream solutionCoords;

	// for loop that iterates through each direction in the solution to output it onto the maze
	for (int i = 0; i < solution.size(); i++) {
		// clears the screen
		system("CLS");

		// sets the character at the current coordinate corresponding to the character in the ith element of the solution
		maze[y][x] = outputMap[solution[i]];

		// adds the current coordinates to solutionCoords
		solutionCoords << "(" << y << ", " << x << ") ";
		
		// adds to x and y based on the character in the ith element of the solution to know the next coordinate in the solution
		x += directionMap[solution[i]].first;
		y += directionMap[solution[i]].second;

		// calls on printMaze to output the maze along with the current path it is taking
		printMaze(maze, height, width);
		// outputs the coordinates of the current path
		std::cout << "Current path: " << solutionCoords.str();
		// waits for 1 second and then continues (to make an animation of the program going to each coordinate in the solution)
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	return 0;
}