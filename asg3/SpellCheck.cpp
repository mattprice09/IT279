
#include "Dictionary.h"
#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>

// Read the input file, return Dictionary
Dictionary readDict(string inputFile) {

}

// Add all permutations of the word possible by adding any letter in any position
void getWordsByAdding(vector<string> &mainList, string word) {

  // vector of all letters
  string alph = "abcdefghijklmnopqrstuvwxyz";
  vector<char> letters(alph.begin(), alph.end());

  // add each letter in the alphabet to each possible position in the string
  for (int c = 0; c < letters.size(); c++) {
    for (int i = 0 ; i < word.size(); i++) {
      mainList.push_back(word.substr(0, i) + letters[c] + word.substr(i));
    }
    mainList.push_back(word + letters[c]);
  }
}

// Add words with removing letters
void getWordsByRemoving(vector mainList, string word) {

}

// Add words with exchanging letters
void getWordsByExchanging(vector mainList, string word) {

}

// The main function that checks if the word is valid
// Returned vector will be empty if the word was valid. Otherwise, it contains
// all possible alternative words
vector getWordAlts(Dictionary wordDict, vector wordList) {

}

int main(int argc, char* argv[]){

  vector<string> wordOptions;
  getWordsByAdding(wordOptions, "dog");

  Require the input file as a CLI argument
  if(argc < 2) {
    cerr << "Usage: " << argv[0] << " INPUT_FILE"
      << endl;
    return 1;
  }

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
