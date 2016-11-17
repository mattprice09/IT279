#include "Dictionary.h"
#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include <fstream>
int main(){
	int lineCount = 0;
	string dictTemp = "";
	string checkTemp = "";
	string checkFile = "";
	Dictionary dict;
	ifstream data ("dict.txt");
		if (data.is_open()) {
			while (getline(data,dictTemp) ){ 
				int i =0;
				char c;
				while(dictTemp[i]) {
					c=dictTemp[i];
					dictTemp.c_str();
					c = (tolower(c));
					i++;
				}
				dict.AddEntry(dictTemp);
				cout << dictTemp << endl;
			}
	    		data.close();
	  	}
		
	cout << "Please enter the name of a text file to check" << endl;
	cin >> checkFile;
	ifstream infile(checkFile);
	if(!infile.is_open()) {
		cerr << "Unable to open file" <<endl;
		exit(EXIT_FAILURE);
	}
	while(!infile.eof()) {
		checkTemp = "";
		char c;
		infile.get(c);
		c = tolower(c);
		while(isalpha(c)) {
			checkTemp += c;
			infile.get(c);
			c = tolower(c);
			if(c == '\n') {
				lineCount++;
			}
		}
		cout << "line: " << lineCount << " word: " << checkTemp << endl;
	}
}
	
	
	
//	
//	
//	
//	
//	
//	
//	ifstream data2 (checkThis);
//	if (data2.is_open()) {
//		string currentWord = "";
//		string temp2 = "";
//		string* arr = new string[30];
//		int lineCount = 0;
//		while (getline(data2,temp) ){ //get a line and store it in temp
//			//NEED Parse for one word store in array, create new array for each line
//			lineCount++;
//			for(int i=0; i<arr.length; i++) {
//				currentWord = arr[i];//store in currentWord
//				if(dictionary.FindEntry(currentWord)==true) {//Search dictionary.  If true, move on
//				continue;
//				}
//				else {  //If false Start logic for possible cantidates, print line and misspelled word
//					cout << "Line: " + lineCount +" Incorrect Word: " currentWord + " Possible Correct Word(s): ";
//					for(j=0; j <currentWord.length; j++) {
//						if(j==0) {
//							if(dictionary.FindEntry(currentWord.
//								cout << currentWord
//						}
//						if(j==currentWord.length-1) {
//							if(dictionary.FindEntry(currentWord.
//						}
//					}//NEED Remove a letter: For currentWord less than length.  Remove first letter search. write to  screen if true.  Remove second letter.....
//					//NEED Exchange two adjacent letters: For temp2 less than legth.  
//						//Search for temp2 with first and second letters swapped.  write to screen if true.  Search for second and third swapped....
//					//NEED Add a letter.  Temp2:  Add a letter to first spot and search.  If true right to screen.  Continue for all letters.
//						//Add a letter to second spot......
//				}
//			}
//				//Done with first word, move on to next word in line 
//		}
//    		data2.close();
//  	}

