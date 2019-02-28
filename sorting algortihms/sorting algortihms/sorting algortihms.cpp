// sorting algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <ctime>
#include <iostream>
#include <stdio.h>  //c style output "printf"
#include <fstream>
#include <string>
#include <vector>

using namespace std;


void selectionSort(vector<int>& sortingNumbers) {

	int size = sortingNumbers.size();
	int i, j;
	int iMin;

	for (j = 0; j < size - 1; j++) {
		iMin = j;
		for (i = j + 1; i < size; i++) {
			/* if this element is less, then it is the new minimum */
			if (sortingNumbers[i] < sortingNumbers[iMin]) {
				/* found new minimum; remember its index */
				iMin = i;
			}
		}

		if (iMin != j) {
			swap(sortingNumbers[j], sortingNumbers[iMin]);
		}
	}

}

void bubbleSort(vector<int>& sortingNumbers) {
	int size = sortingNumbers.size();
	do {
		int n = 0;
		for (int i = 1; i < size; i++) {
			if (sortingNumbers[i - 1] > sortingNumbers[i]) {
				swap(sortingNumbers[i - 1], sortingNumbers[i]);
				n = i;
			}
		}
		size = n;

	} while (size != 0);
}

void merge(vector<int>& numbers, int l, int m, int r) {
	vector<int> sorted;
	int i = 0, j = 0;
	for (i = l, j = m + 1; i <= m && j <= r;) {
		if (numbers[i] < numbers[j]) {
			sorted.push_back(numbers[i]);
			i++;
		}
		else {
			sorted.push_back(numbers[j]);
			j++;
		}
	}

	while (i <= m) {
		sorted.push_back(numbers[i]);
		i++;
	}
	while (j <= r) {
		sorted.push_back(numbers[j]);
		j++;
	}

	for (int i = 0; i < sorted.size(); i++)
		numbers[l + i] = sorted[i];
}

void mergeSort(vector<int>& sortingNumbers, int l, int r) {
	if (r > l) {
		int middle = (l + r) / 2;
		mergeSort(sortingNumbers, l, middle);
		mergeSort(sortingNumbers, middle + 1, r);
		merge(sortingNumbers, l, middle, r);
	}
}

void mergeSort(vector<int>& sortingNumbers) {
	mergeSort(sortingNumbers, 0, sortingNumbers.size() - 1);
}

int partition(vector<int>& numbers, int low, int high) {
	int pivot = numbers.at(low);
	int leftwall = low;

	for (int j = low + 1; j <= high; j++) {
		if (numbers[j] < pivot) {
			leftwall++;
			swap(numbers[leftwall], numbers[j]);
		}
	}
	swap(numbers[leftwall], numbers[low]);
	return leftwall;
}

void quickSort(vector<int>& sortingNumbers, int low, int high) {
	if (low < high) {
		int pi = partition(sortingNumbers, low, high);
		quickSort(sortingNumbers, low, pi - 1);
		quickSort(sortingNumbers, pi + 1, high);
	}
}

void quickSort(vector<int>& sortingNumbers) {
	quickSort(sortingNumbers, 0, sortingNumbers.size() - 1);
}

void insertionSort(vector<int>& sortingNumbers) {
	int i, j;
	int value;
	int size = sortingNumbers.size();
	for (i = 1; i < size; i++) {
		j = i - 1;
		value = sortingNumbers[i];

		while (j >= 0 && value < sortingNumbers[j]) {
			sortingNumbers[j + 1] = sortingNumbers[j];
			j--;
		}
		sortingNumbers.at(j + 1) = value;
	}
}

void algorithmToUse(int n, vector<int> &originalNumbers) {
	vector<int> numbersToSort;
	for (int i = 0; i < originalNumbers.size(); i++) {
		numbersToSort.push_back(originalNumbers[i]);
	}

	if (n == 0) {
		clock_t begin = clock();
		selectionSort(numbersToSort);
		clock_t end = clock();

		double elapsed_secs = double(end - begin) / double(CLOCKS_PER_SEC);
		printf("Elapsed time is %.9f seconds. \n", elapsed_secs);
	}
	else if (n == 1) {
		clock_t begin = clock();
		bubbleSort(numbersToSort);
		clock_t end = clock();

		double elapsed_secs = double(end - begin) / double(CLOCKS_PER_SEC);
		printf("Elapsed time is %.9f seconds. \n", elapsed_secs);
	}
	if (n == 2) {
		clock_t begin = clock();
		mergeSort(numbersToSort);
		clock_t end = clock();

		double elapsed_secs = double(end - begin) / double(CLOCKS_PER_SEC);
		printf("Elapsed time is %.9f seconds. \n", elapsed_secs);
	}
	if (n == 3) {
		clock_t begin = clock();
		quickSort(numbersToSort);
		clock_t end = clock();

		double elapsed_secs = double(end - begin) / double(CLOCKS_PER_SEC);
		printf("Elapsed time is %.9f seconds. \n", elapsed_secs);
	}
	else {
		clock_t begin = clock();
		insertionSort(numbersToSort);
		clock_t end = clock();

		double elapsed_secs = double(end - begin) / double(CLOCKS_PER_SEC);
		printf("Elapsed time is %.9f seconds. \n", elapsed_secs);
	}

}

int main() {
	int n = 1;
	while (n < 100000) {
		n *= 10;
		vector<int> sortingNumbers;
		vector<int> numbersToSort;
		int input;

		ifstream file("data" + to_string(n) + ".txt");

		while (file >> input) {
			sortingNumbers.push_back(input);
		}



		for (int y = 0; y < 5; y++) {
			for (int i = 0; i < n; i++) {
				numbersToSort.push_back(sortingNumbers[i]);
			}
			if (y == 0) {
				clock_t begin = clock();
				selectionSort(numbersToSort);
				clock_t end = clock();

				double elapsed_secs = double(end - begin) / double(CLOCKS_PER_SEC);
				cout << "N = " << n << ", Selection Sort: ";
				printf("Elapsed time is %.9f seconds. \n", elapsed_secs);

			}

			else if (y == 1) {
				clock_t begin = clock();
				bubbleSort(numbersToSort);
				clock_t end = clock();

				double elapsed_secs = double(end - begin) / double(CLOCKS_PER_SEC);
				cout << "N = " << n << ", Bubble Sort: ";
				printf("Elapsed time is %.9f seconds. \n", elapsed_secs);
			}
			else if (y == 2) {
				clock_t begin = clock();
				mergeSort(numbersToSort);
				clock_t end = clock();

				double elapsed_secs = double(end - begin) / double(CLOCKS_PER_SEC);
				cout << "N = " << n << ", Merge Sort: ";
				printf("Elapsed time is %.9f seconds. \n", elapsed_secs);
			}
			else if (y == 3) {
				clock_t begin = clock();
				quickSort(numbersToSort);
				clock_t end = clock();

				double elapsed_secs = double(end - begin) / double(CLOCKS_PER_SEC);
				cout << "N = " << n << ", Quick Sort: ";
				printf("Elapsed time is %.9f seconds. \n", elapsed_secs);
			}
			else {
				clock_t begin = clock();
				insertionSort(numbersToSort);
				clock_t end = clock();

				double elapsed_secs = double(end - begin) / double(CLOCKS_PER_SEC);
				cout << "N = " << n << ", Insertion Sort: ";
				printf("Elapsed time is %.9f seconds. \n\n", elapsed_secs);
			}
			numbersToSort.clear();
		}

		sortingNumbers.clear();
	}
	return 0;
}
