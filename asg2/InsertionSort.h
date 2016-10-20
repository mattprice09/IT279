/*
 * InsertionSort.h
 *
 *  Created on: Oct 17, 2016
 *      Authors: Michael Donner, Matt Price, John Reape
 */

#ifndef ASG2_INSERTIONSORT_H_
#define ASG2_INSERTIONSORT_H_
/*
 *	Create a class to hold the Node class, linked list, and required methods
 *	to perform an insertion sort 
 */
class InsertionSort {
public:
	/*	Construct a new InsertionSort object with
	 *	empty unsorted and sorted lists
	 */
	InsertionSort();
	~InsertionSort();
	/*	Print the current state of the sorted and unsorted protions 
	 *	of internal lists. Used for debugging only small inputs
	 */
	void printList();
	/*	Make a new unsorted linked list from input file */
	void readFile(const char* filename);
	/* 	Output sorted list to file. Outputs empty file if not yet sorted */
	void outputFile(const char* filename);
	/*	Begin sorting list read from readFile() */
	void sort();
private:
	class Node {
	public:
		int data;
		Node* next;
		/*	New Node with data value 0 and next NULL */
		Node();
		/*	Create new Node using input data and next values */
		Node(const int& dataValue, Node* nextValue);
	};
	/*	Head node for the sorted list */
	Node *sorted;
	/*	Head node for the unsorted list */
	Node *unsorted;
	/*	Helper to insert individual node into the sorted list*/
	void insert(Node* current);
	int size;
};



#endif /* ASG2_INSERTIONSORT_H_ */
