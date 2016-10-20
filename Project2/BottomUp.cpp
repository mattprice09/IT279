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



int main() {
	
	string line;
	int value;
	std::clock_t start;
	     
    	double duration;

    	start = std::clock();
	ifstream myfile("input.txt");
	vector<long> vect1;
	while (getline(myfile, line))
	{
		istringstream iss(line);
		int n;
		iss >> n;
		vect1.push_back(n);
	}
	cout<<"File Read \n";
	vector<long> vect2(vect1.size());
	BottomUpMergesort *arraySorter = new BottomUpMergesort;
	arraySorter->BottomUpSort(vect1, vect2);
	cout<<"Sorting Complete \n";
	 duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	std::cout<<"printf: "<< duration <<'\n';
	ofstream output_file("output.txt");
	ostream_iterator<long> output_iterator(output_file, "\n");
	copy(arraySorter->temp1.begin(), arraySorter->temp1.end(), output_iterator);
	cout<<"Check output.txt for results";

   

   


}
