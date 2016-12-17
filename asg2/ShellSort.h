/*
 * ShellSort.h
 *
 *  Created on: Oct 17, 2016
 *      Authors: Michael Donner, Matt Price, John Reape
 */

#ifndef ASG2_SHELLSORT_H_
#define ASG2_SHELLSORT_H_

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class ShellSort {
public:
  ShellSort();

  std::vector<int> data;

  void printList();
  void readFile(const char* filename);
  void outputFile(const char* filename);
  void sort();
};

#endif /* ASG2_SHELLSORT_H_ */
