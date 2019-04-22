#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
//#include <Windows.h>

int main()
{
	// open the file with the maze
	std::ifstream mazeFile("maze.txt");
	std::string input;
	int height;
	int width;
	std::vector<std::string> maze;
	std::getline(mazeFile, input);
	height = std::stoi(input);
	std::getline(mazeFile, input);
	width = std::stoi(input);

	for (int i = 0; i < height; i++) {
		std::getline(mazeFile, input);
		maze.push_back(input);
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			
			std::cout << maze[i][j];
		}
		std::cout << std::endl;
	}

	std::queue<std::pair <std::pair <int, int>, std::string>> nodeToVisit;

	std::vector<bool> tempRow(width, false);
	std::vector<std::vector<bool>> isVisited(height, tempRow);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (maze[i][j] == 'X')
				isVisited[i][j] = true;
		}
	}

	int x, y;
	std::string solution;
	nodeToVisit.push(std::make_pair(std::make_pair(1, 1), "")); 
	for (; nodeToVisit.size() > 0; nodeToVisit.pop()) {
		x = nodeToVisit.front().first.first;
		y = nodeToVisit.front().first.second;
		std::string path = nodeToVisit.front().second;

		if (isVisited[y][x])
			continue;

		isVisited[y][x] = true;

		if (maze[y][x] == 'X')
			continue;

		if (maze[y][x] == '$') {
			solution = path;
			nodeToVisit.push(std::make_pair(std::make_pair(x, y), path + "$"));
			std::cout << solution << std::endl;
			break;
		}

		if (y + 1 < height)
			nodeToVisit.push(std::make_pair(std::make_pair(x, y + 1), path + "d"));

		if (x + 1 < width)
			nodeToVisit.push(std::make_pair(std::make_pair(x + 1, y), path + "r"));

		if (y - 1 > 0)
			nodeToVisit.push(std::make_pair(std::make_pair(x, y - 1), path + "u"));

		if (x - 1 > 0)
			nodeToVisit.push(std::make_pair(std::make_pair(x - 1, y), path + "l"));
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {

			std::cout << maze[i][j];
		}
		std::cout << std::endl;
	}


	return 0;
}