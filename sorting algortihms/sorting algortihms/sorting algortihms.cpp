/*
Name: Abhay Sharma
Date: March 1, 2019
Description: The program reads in files that include n numbers, sorts the numbers using different sorting alogrithms, and output the time it took for each algorithm to sort the numbers
*/

#include "pch.h"
#include <ctime>	// for timing the results
#include <iostream>	// for cout
#include <stdio.h>	// c style output "printf"
#include <fstream>	// for reading in files
#include <string>	// to use strings
#include <vector>	// to use vectors
#include <chrono>	// for a high resolution clock

using namespace std;

void selectionSort(vector<int>& sortingNumbers, int size) {
	// pre:	 takes in a vector of integers and an integer size that is the length of the vector
	// post: sorts the vector's integers from smallest to greatest

	// variable to count through the numbers to sort
	int i, j;
	// variable to store the smallest number
	int iMin;

	// for loop that counts through the vector
	for (j = 0; j < size - 1; j++) {
		// set smallesst number to the current element, j
		iMin = j;
		// for loop that iterates through the rest of the numbers to check if iMin is the smallest number
		for (i = j + 1; i < size; i++) {
			// if i is less than the current lowest number, set i to the lowest number
			if (sortingNumbers[i] < sortingNumbers[iMin]) {
				iMin = i;
			}
		}
		// if the lowest number is not j, swap the 2 numbers
		if (iMin != j) {
			swap(sortingNumbers[j], sortingNumbers[iMin]);
		}
	}

}

void bubbleSort(vector<int>& sortingNumbers, int size) {
	// pre:	 takes in a vector of integers and an integer size that is the length of the vector
	// post: sorts the vector's integers from smallest to greatest

	// a do while loop that only exits when size = 0, which will only be possible if all numbers are sorted since n will equal 0 in that case
	do {
		// set n to 0
		int n = 0;
		// for loop that iterates through the numbers in the vector
		for (int i = 1; i < size; i++) {
			// if the element before i is greater than i, swap the element i-1 and i and set n equal to i
			if (sortingNumbers[i - 1] > sortingNumbers[i]) {
				swap(sortingNumbers[i - 1], sortingNumbers[i]);
				n = i;
			}
		}
		// set size equal to n
		size = n;

	} while (size != 0);
}

void merge(vector<int>& numbers, int l, int m, int r) {
	// pre:	 takes in a vector of integers, the left index, the middle index, and the right index of the vector
	// post: sorts the elements in the numbers vector from smallest to greatest

	// creates a vector that stores the sorted numbers
	vector<int> sorted;
	// declares integers to interate through the vector's elements
	int i = 0, j = 0;

	// a for loop where i iterates through the elements from l to m and j iterates through the elements from m+1 to r compare the elements in the vector and sort them
	for (i = l, j = m + 1; i <= m && j <= r;) {
		// if the element at i is less than j, add i to to the sorted and go to the next element in the first half of the vector (l to m+1)
		if (numbers[i] < numbers[j]) {
			sorted.push_back(numbers[i]);
			i++;
		}
		// else, add j to the sorted vector and go to the next element in the in the second half of the vector (m+1 to r)
		else {
			sorted.push_back(numbers[j]);
			j++;
		}
	}

	// while i is less than or equal to m, that means there are elements that have not been added to the sorted vector so this loop will add them to the vector
	while (i <= m) {
		sorted.push_back(numbers[i]);
		i++;
	}
	// while j is less than or equal to r, that means there are elements that have not been added to the sorted vector so this loop will add them to the vector
	while (j <= r) {
		sorted.push_back(numbers[j]);
		j++;
	}

	// for loop that puts the sorted integers into the numbers vector
	for (int i = 0; i < sorted.size(); i++)
		numbers[l + i] = sorted[i];
}

void mergeSort(vector<int>& sortingNumbers, int l, int r) {
	// pre:	 takes in a vector of integers, the left index (l), and the right index (r) of the vector
	// post: sorts the vector's integers from smallest to greatest

	if (r > l) {
		// finds the middle of the vector to split it half
		int middle = (l + r) / 2;
		// calls mergeSort for the first half of the vector
		mergeSort(sortingNumbers, l, middle);
		// calls mergeSort for the second half of the vector
		mergeSort(sortingNumbers, middle + 1, r);
		// calls the merge function to merge the vectors
		merge(sortingNumbers, l, middle, r);
	}
}

void mergeSort(vector<int>& sortingNumbers) {
	// pre:	 takes in a vector of integers
	// post: calls mergeSort to sort the numbers in the vector from smallest to greatest
	mergeSort(sortingNumbers, 0, sortingNumbers.size() - 1);
}

int partition(vector<int>& numbers, int l, int r) {
	// pre:	 takes in a vector of integers, the starting index (l), and the ending index (r) of the vector
	// post: places the pivot at the correct location and all numbers less than the pivot before it, and the numbers greater than the pivot after it

	// the pivot point is the element at l
	int pivot = numbers[l];
	// set a leftwall which is the index of the left most sorted element
	int leftwall = l;

	// for loop that iterates through the elements of the vector
	for (int j = l + 1; j <= r; j++) {
		// if the current element (j) is less than the pivot, add one to leftwall and swap the elements at j and at leftwall
		if (numbers[j] < pivot) {
			leftwall++;
			swap(numbers[leftwall], numbers[j]);
		}
	}
	// swap the element at leftwall with the element at l so the pivot is at the correct location
	swap(numbers[leftwall], numbers[l]);
	// return the leftwall to act as the partition index
	return leftwall;
}

void quickSort(vector<int>& sortingNumbers, int l, int r) {
	// pre:	 takes in a vector of integers, the starting index (l), and the ending index (r) of the vector
	// post: sorts the vector's integers from smallest to greatest

	if (l < r) {
		// set pi to the index of pivot point
		int pi = partition(sortingNumbers, l, r);
		// sort the elements from l to pi - 1
		quickSort(sortingNumbers, l, pi - 1);
		// sort the elements from pi + 1 to r
		quickSort(sortingNumbers, pi + 1, r);
	}
}

void quickSort(vector<int>& sortingNumbers) {
	// pre:	 takes in a vector of integers
	// post: calls quickSort to sort the numbers in the vector from smallest to greatest
	quickSort(sortingNumbers, 0, sortingNumbers.size() - 1);
}

void insertionSort(vector<int>& sortingNumbers, int size) {
	// pre:	 takes in a vector of integers and an integer size that is the length of the vector
	// post: sorts the vector's integers from smallest to greatest

	int i, j, value;

	// iterates through the vector of integers
	for (i = 1; i < size; i++) {
		// sets j to the index right before i
		j = i - 1;
		// sets the value to the element at index i
		value = sortingNumbers[i];

		// while j is greater than or equal to 0 and the element at j is less than the value, move the element ahead by one
		while (j >= 0 && value < sortingNumbers[j]) {
			sortingNumbers[j + 1] = sortingNumbers[j];
			j--;
		}
		// sets element at j+1 to value
		sortingNumbers[j + 1] = value;
	}
}


int main() {
	// set the number of elements to sort to 1;
	int n = 1;

	// while loop that will read and sort files with numbers up to n = 100000
	while (n < 100000) {
		// set the number of integers to use in the file 10 times greater than the previous
		n *= 10;
		// create vectors to store the numbers in the file, originalNumbers will always store the unsorted numbers
		vector<int> originalNumbers;
		vector<int> numbersToSort;

		int input;
		// open the file
		ifstream file("data100000.txt");
		// store the numbers in the file to vector originalNumbers
		for (int i = 0; i < n; i++) {
			file >> input;
			originalNumbers.push_back(input);
		}
		// close the file
		file.close();

		// for loop that runs 5 times, for each sorting alogrithm
		for (int y = 0; y < 5; y++) {

			// for loop that adds the numbers in originalNumbers to numbersToSort
			for (int i = 0; i < n; i++) {
				numbersToSort.push_back(originalNumbers[i]);
			}

			// set of if statements that decide which algorithm to run based on y's value
			if (y == 3) {
				// starts and clock, calls the sorting algorithm, and ends the clock
				chrono::high_resolution_clock::time_point begin = chrono::high_resolution_clock::now();
				selectionSort(numbersToSort, n);
				chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

				// outputs the time it took to sort the numbers (divides by 1000000000 to get the output in seconds)
				cout << "N = " << n << ", Selection Sort: ";
				cout << "Elapsed time is " << double((end - begin).count()) / double(1000000000) << " seconds.\n";

			}

			else if (y == 1) {
				chrono::high_resolution_clock::time_point begin = chrono::high_resolution_clock::now();
				bubbleSort(numbersToSort, n);
				chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

				cout << "N = " << n << ", Bubble Sort: ";
				cout << "Elapsed time is " << double((end - begin).count()) / double(1000000000) << " seconds.\n";
			}

			else if (y == 2) {
				chrono::high_resolution_clock::time_point begin = chrono::high_resolution_clock::now();
				mergeSort(numbersToSort);
				chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

				cout << "N = " << n << ", Merge Sort: ";
				cout << "Elapsed time is " << double((end - begin).count()) / double(1000000000) << " seconds.\n";
			}

			else if (y == 0) {
				chrono::high_resolution_clock::time_point begin = chrono::high_resolution_clock::now();
				quickSort(numbersToSort);
				chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

				cout << "N = " << n << ", Quick Sort: ";
				cout << "Elapsed time is " << double((end - begin).count()) / double(1000000000) << " seconds.\n";
			}

			else {
				chrono::high_resolution_clock::time_point begin = chrono::high_resolution_clock::now();
				insertionSort(numbersToSort, n);
				chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

				cout << "N = " << n << ", Insertion Sort: ";
				cout << "Elapsed time is " << double((end - begin).count()) / double(1000000000) << " seconds.\n\n";
			}

			// clears the numbers in numberToSort so the next sorting algorithm will sort the unsorted numbers
			numbersToSort.clear();
		}
		// clears originalNumbers so the elements from the current file do not remain in the vector when sorting the numbers in the next file
		originalNumbers.clear();
	}
	return 0;
}
