#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

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
	std::cout << std::endl;
	std::cout << std::endl;


	//int x = 1;
	//int y = 1;

	std::vector<std::pair <std::pair <int, int>, int>> path;
	//std::pair <int, int> coordinates(x, y);
	//coordinates = std::make_pair(coordinates.first + 1, coordinates.second + 2);
	//std::cout << coordinates.first << coordinates.second;

	std::queue<std::pair <int, int>> nodeToVisit;

	std::vector<bool> tempRow(width, false);
	std::vector<std::vector<bool>> isVisited(height, tempRow);

	/*for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			isVisited[i][j] = false;;
		} 
	}*/
	char direction = 'U';
	int x, y;
	int preX, preY;
	nodeToVisit.push(std::make_pair(1, 1)); 
	for (int step = 0; nodeToVisit.size() > 0; nodeToVisit.pop(), step++) {
		x = nodeToVisit.front().first;
		y = nodeToVisit.front().second;

		if (isVisited[y][x])
			continue;

		isVisited[y][x] = true;

		if (maze[y][x] == 'X') {
			/*std::vector<std::pair <std::pair <int, int>, int>>::iterator it;
			it = std::find(path.begin(), path.end(), std::make_pair(std::make_pair(preX, preY), step - 1));
			int index = std::distance(path.begin(), it);

			path.erase(path.begin() + index);
			step--;*/
			//it = std::find(path.begin(), path.end(), std::make_pair(std::make_pair(preX, preY), step - 1));
			//index = std::distance(path.begin(), it);
			//if (it == path.end())/*(path.back().first.first != x - 1 || path.back().first.first != x + 1 || path.back().first.first != x)*/ {
			//	maze[preY][preX] = ' ';
			//}
			continue;
		}

		preX = nodeToVisit.front().first;
		preY = nodeToVisit.front().second;

		if (maze[y][x] == '$') {
			path.push_back(std::make_pair(std::make_pair(x, y), step));
			std::cout << "found" << std::endl;
			break;
		}

		maze[y][x] = '*';

		if (y + 1 < height) {
			path.push_back(std::make_pair(std::make_pair(x, y), step));
			nodeToVisit.push(std::make_pair(x, y + 1));
		}

		if (x + 1 < width) {
			path.push_back(std::make_pair(std::make_pair(x, y), step));
			nodeToVisit.push(std::make_pair(x + 1, y));
		}

		if (y - 1 > 0) {
			path.push_back(std::make_pair(std::make_pair(x, y), step));
			nodeToVisit.push(std::make_pair(x, y - 1));
		}

		if (x - 1 > 0) {
			path.push_back(std::make_pair(std::make_pair(x, y), step));
			nodeToVisit.push(std::make_pair(x + 1, y));
		}

		/* alternate stuff
				if (y + 1 < height && maze[x][y+1] != 'X') {
			path.push_back(std::make_pair(std::make_pair(x, y), std::make_pair(x, y + 1)));
			nodeToVisit.push(std::make_pair(x, y + 1));
		}

		if (x + 1 < width && maze[x + 1][y] != 'X') {
			path.push_back(std::make_pair(std::make_pair(x, y), std::make_pair(x + 1, y)));
			nodeToVisit.push(std::make_pair(x + 1, y));
		}

		if (y - 1 > 0 && maze[x][y - 1] != 'X') {
			path.push_back(std::make_pair(std::make_pair(x, y), std::make_pair(x, y - 1)));
			nodeToVisit.push(std::make_pair(x, y - 1));
		}

		if (x - 1 > 0 && maze[x - 1][y] != 'X') {
			path.push_back(std::make_pair(std::make_pair(x, y), std::make_pair(x - 1, y)));
			nodeToVisit.push(std::make_pair(x + 1, y));
		}
		*/
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {

			std::cout << maze[i][j];
		}
		std::cout << std::endl;
	}


	return 0;
}