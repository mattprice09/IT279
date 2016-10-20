#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;
class BottomUpMergesort
{
private:
  
public:
	vector<long> temp1;
	//BottomUpMergesort Constructor
	BottomUpMergesort();
	void BottomUpSort(vector<long> *arr1,vector<long> arr2);
	void BottomUpMerge(vector<long> *arr1, int indexLeft, int indexRight, int indexEnd);
	/*BottomUpMergesort destructor*/
	virtual ~BottomUpMergesort();
};