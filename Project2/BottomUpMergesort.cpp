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
void BottomUpMergesort::BottomUpSort(vector<long> &arr1, vector<long> arr2)
{
	int width;
	temp1 = arr2;
	for (width = 1; width < (int)arr1.size(); width = 2 * width)
	{
		int i;
		for (i = 0; i < (int)arr1.size(); i = i + 2 * width)
		{
			BottomUpMerge(&arr1,i, min((i+width),(int)arr1.size()) ,min((i+2*width),(int)arr1.size()));
		}
		copy(temp1.begin(), temp1.end(), arr1.begin());
	}
	int x = 0;
	
}
void BottomUpMergesort::BottomUpMerge(vector<long> *arr1, int indexLeft, int indexMid, int lastindex)
{
	int x = 0;
	int i = indexLeft;
	int k = indexLeft;
	int j = indexMid;

	while ((i < indexMid) || (j < lastindex))
	{
		if ((i < indexMid) && (j < lastindex))
		{
			if (arr1[i] < arr1[j])
				temp1[k++] = arr1[i++];
			else
				temp1[k++] = arr1[j++];
		}
		else if (i == indexMid)
			temp1[k++] = arr1[j++];	   // a is empty
		else if (j == lastindex)
			temp1[k++] = arr1[i++];	   // b is empty
	}
}
BottomUpMergesort::~BottomUpMergesort()
{
	
}