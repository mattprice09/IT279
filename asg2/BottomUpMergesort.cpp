#include <algorithm>
#define NOMINMAX
#include "BottomUpMergesort.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <vector>
using namespace std;


BottomUpMergesort::BottomUpMergesort() {
}
void BottomUpMergesort::BottomUpSort(vector<long> arr1, vector<long> arr2)
{
	temp2 = arr1;
	temp1 = arr2;
	int width;
	//Get the incraments in which to merge 
	for (width = 1; width < (int)temp2.size(); width = 2 * width)
	{
		int i;
		//Now iterate through the vector with the incraments to find the specific spots to merge and sort 
		for (i = 0; i < (int)temp2.size(); i = i + 2 * width)
		{
			BottomUpMerge(i, min((i+width),(int)arr1.size()) ,min((i+2*width),(int)arr1.size()));
		}
		copy(temp1.begin(), temp1.end(), temp2.begin());
	}
	int x = 0;
	
}
void BottomUpMergesort::BottomUpMerge(int indexLeft, int indexMid, int lastindex)
{
	int x = 0;
	int i = indexLeft;
	int k = indexLeft;
	int j = indexMid;
	//Where the sorting actually happens with indexing the vector and merging them
	while ((i < indexMid) || (j < lastindex))
	{
		if ((i < indexMid) && (j < lastindex))
		{
			if (temp2[i] < temp2[j])
				temp1[k++] = temp2[i++];
			else
				temp1[k++] = temp2[j++];
		}
		else if (i == indexMid)
			temp1[k++] = temp2[j++];	   // a is empty
		else if (j == lastindex)
			temp1[k++] = temp2[i++];	   // b is empty
	}
}
BottomUpMergesort::~BottomUpMergesort()
{
	
}