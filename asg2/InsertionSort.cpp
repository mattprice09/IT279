/*
 * ShortcutInsertionSort.cpp
 *
 * Sorts numbers read from a file using insertion sort and a linked list
 *
 *  Created on: Oct 13, 2016
 *      Authors: Michael Donner, Matt Price, John Reape
 */

#include "stdlib.h"
#include "InsertionSort.h"
#include <fstream>
#include <iostream>
#include <iomanip>

InsertionSort::Node::Node() {
	data = 0;
	next = NULL;
}
InsertionSort::Node::Node(const int& dataValue, Node* nextValue){
	data = dataValue;
	next = nextValue;
}

InsertionSort::InsertionSort() {
	size = 0;
	unsorted = sorted = NULL;
}

InsertionSort::~InsertionSort() {
	Node* current;
	// Delete all Nodes that were created durring readFile()
	// independent of if sort() was run or not.
	while (sorted != NULL) {
		current = sorted;
		sorted = sorted->next;
		delete current;
	}
	while (unsorted != NULL) {
		current = unsorted;
		unsorted = unsorted->next;
		delete current;
	}
}

void InsertionSort::readFile(const char* filename) {
	std::ifstream inputFile(filename);
	std::string line;
	int data;
	// need to add data to tail to match order of input file
	Node* tail;

	if (inputFile.is_open()) {
		// Assume there is at least one valid int in the input file
		inputFile >> data;
		tail = unsorted = new Node(data, NULL);
		size++;
		while(inputFile >> data) {
			tail = tail->next = new Node(data, NULL);
			size++;
		}
		inputFile.close();
	} else {
		std::cerr << "Unable to open file" << std::endl;
		exit (EXIT_FAILURE);
	}
}

void InsertionSort::outputFile(const char* filename) {
	std::ofstream outputFile (filename);
	if (outputFile.is_open()) {
		Node *current = sorted;
		while (current != NULL) {
			// use '\n' instead of endl to match Unix `sort` terminal output
			// and make diff easier to compare
			outputFile << current->data << '\n';
			current = current->next;
		}
		outputFile.close();
	} else {
		std::cerr << "Unable to open output file" << std::endl;
		exit (EXIT_FAILURE);
	}
}

void InsertionSort::sort() {
	Node *current = unsorted;
	Node *next;
	while(current != NULL) {
		unsorted = current->next;
		insert(current);
		current = unsorted;
	}
}

void InsertionSort::insert(Node* current) {
	int data = current->data;
	// Special case if the list is empty or if data is smaller than sorted->data.
	if (sorted == NULL || data < sorted->data) {
		current->next = sorted;
		sorted = current;
		return;
	}
	// Otherwise check the rest of the list
	Node* target = sorted;
	while (target->next != NULL && data > target->next->data) {
		target = target->next;
	}
	current->next = target->next;
	target->next = current;
}

int main(int argc, char* argv[]) {
	if(argc < 3) {
		std::cerr << "Usage: " << argv[0] << " INPUT_FILE OUTPUT_FILE"
			<< std::endl;
		return 1;
	}

	InsertionSort sort;
	sort.readFile(argv[1]);
	sort.sort();
	sort.outputFile(argv[2]);
}
