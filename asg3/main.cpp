#include "Dictionary.h"
#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include <fstream>
int main(){
	string temp = "";
	string checkThis = "";
	cout <<"Please enter the name of a text file to check"
	cin >> checkThis
	ifstream data (dict.txt);
	if (data.is_open()) {
		while (getline(data,temp) ){ //get a line and store it in temp
			//NEED Add temp to dictionary here
		}
    		data.close();
  	}
	ifstream data2 (checkThis);
	if (data2.is_open()) {
		string currentWord = "";
		string temp2 = "";
		string* arr = new string[30];
		int lineCount = 0;
		while (getline(data2,temp) ){ //get a line and store it in temp
			//NEED Parse for one word store in array, create new array for each line
			lineCount++;
			for(int i=0; i<arr.length; i++) {
				currentWord = arr[i];//store in currentWord
				if(dictionary.FindEntry(currentWord)==true) {//Search dictionary.  If true, move on
				continue;
				}
				else {  //If false Start logic for possible cantidates, print line and misspelled word
					cout << "Line: " + lineCount +" Incorrect Word: " currentWord + " Possible Correct Word(s): ";
					for(j=0; j <currentWord.length; j++) {
						if(j==0) {
							if(dictionary.FindEntry(currentWord.
								cout << currentWord
						}
						if(j==currentWord.length-1) {
							if(dictionary.FindEntry(currentWord.
						}
					}//NEED Remove a letter: For currentWord less than length.  Remove first letter search. write to  screen if true.  Remove second letter.....
					//NEED Exchange two adjacent letters: For temp2 less than legth.  
						//Search for temp2 with first and second letters swapped.  write to screen if true.  Search for second and third swapped....
					//NEED Add a letter.  Temp2:  Add a letter to first spot and search.  If true right to screen.  Continue for all letters.
						//Add a letter to second spot......
				}
			}
				//Done with first word, move on to next word in line 
		}
    		data2.close();
  	}
}
