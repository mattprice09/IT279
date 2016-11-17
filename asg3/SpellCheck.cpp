
#include "Dictionary.h"
#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <set>

// Read the input file, return Dictionary
Dictionary readDict(string inputFile) {

}

// Add all permutations of the word possible by adding any letter in any position
void getWordsByAdding(set<string> &mainList, string word) {

  // vector of all letters
  string alph = "abcdefghijklmnopqrstuvwxyz";
  vector<char> letters(alph.begin(), alph.end());

  // add each letter in the alphabet to each possible position in the string
  for (int c = 0; c < letters.size(); c++) {
    for (int i = 0 ; i < word.size(); i++) {
      mainList.insert(word.substr(0, i) + letters[c] + word.substr(i));
    }
    mainList.insert(word + letters[c]);
  }
}

// Add words with removing letters
void getWordsByRemoving(set<string>& mainList, string word) {

  for (int i = 1; i < word.size(); i++) {
    mainList.insert(word.substr(0, i-1) + word.substr(i));
  }
  mainList.insert(word.substr(0, word.size()-1));
}

// Add words with exchanging letters
void getWordsByExchanging(set<string>& mainList, string word) {

  for (int i = 1; i < word.size(); i++) {
    mainList.insert(string() + word.substr(0, i-1) + word[i] + word[i-1] + word.substr(i+1));
  }
}

// Get all word options to search for
vector<string> getAllWords(string word) {

  // Initially store as set to avoid duplicates
  set<string> wordSet;
  getWordsByAdding(wordSet, word);
  getWordsByRemoving(wordSet, word);
  getWordsByExchanging(wordSet, word);

  wordSet.erase(word);

  // Convert set to vector, delete set
  vector<string> wordOptions;
  std::copy(wordSet.begin(), wordSet.end(), std::back_inserter(wordOptions));
  set<string>().swap(wordSet);

  return wordOptions;
}

// The main function that checks if the word is valid
// Returned vector will be empty if the word was valid. Otherwise, it contains
// all possible alternative words
vector<string> getWordAlts(Dictionary wordDict, vector<string> wordList) {

}

int main(int argc, char* argv[]){

  // string word = "testword";
  // vector<string> wordsToFind = getAllWords(word);

  // Require the input file as a CLI argument
  if(argc < 2) {
    cerr << "Usage: " << argv[0] << " INPUT_FILE"
      << endl;
    return 1;
  }

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
