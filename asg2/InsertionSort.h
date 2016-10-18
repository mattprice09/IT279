/*
 * InsertionSort.h
 *
 *  Created on: Oct 17, 2016
 *      Author: User
 */

#ifndef ASG2_INSERTIONSORT_H_
#define ASG2_INSERTIONSORT_H_
class InsertionSort {
protected:
	class Node {
	public:
		int data;
		Node* next;
		Node();
		Node(const int& dataValue, Node* nextValue);
	};
public:
	InsertionSort();
	void printList();
	void readFile(const char* filename);
	void outputFile(const char* filename);
	void sort();
private:
	int size;
	Node *sorted;
	Node *unsorted;
	void insert(Node* current);
};



#endif /* ASG2_INSERTIONSORT_H_ */
