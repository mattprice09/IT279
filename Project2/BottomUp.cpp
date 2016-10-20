#include "BottomUpMergesort.h"
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstdio>
#include <ctime>
#include <vector>
#include <iterator>
using namespace std;



int main(int argc, char* argv[]) {
	//line that  gets assigned to each line in fiel
	string line;
	int value;
	//clock algorithm to time sort
	std::clock_t start;
	//user inputs  
    	double duration;
	start = std::clock();
	ifstream myfile(argv[1]);
	//vector that takes int file
	vector<long> vect1;
	while (getline(myfile, line))
	{
		istringstream iss(line);
		int n;
		iss >> n;
		vect1.push_back(n);
	}
	cout<<"File Read \n";
	//temp array for sorting
	vector<long> vect2(vect1.size());
	BottomUpMergesort *arraySorter = new BottomUpMergesort;
	//Sort the vector
	arraySorter->BottomUpSort(vect1, vect2);
	//Micellaneous tasks
	cout<<"Sorting Complete \n";
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	std::cout<<"printf: "<< duration <<'\n';
	ofstream output_file(argv[2]);
	ostream_iterator<long> output_iterator(output_file, "\n");
	copy(arraySorter->temp1.begin(), arraySorter->temp1.end(), output_iterator);
	cout<<"Thank you";

   

   


}
