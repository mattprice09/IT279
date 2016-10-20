#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;
class BottomUpMergesort
{
  
public:
	//vector to store the sorted vector
	vector<long> temp1;
	//vector to store the full unsorted vector
	vector<long> temp2;
	//BottomUpMergesort Constructor
	BottomUpMergesort();
	//Method that gets the incraments to merge 1,2,4,8,8,16
	void BottomUpSort(vector<long> arr1,vector<long> arr2);
	//Method that does the sorting when the vector is being merged together 
	void BottomUpMerge(int indexLeft, int indexRight, int indexEnd);
	/*BottomUpMergesort destructor*/
	virtual ~BottomUpMergesort();
};