#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
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

	return 0;
}