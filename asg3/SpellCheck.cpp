#include "Dictionary.h"

using namespace std;

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>


// Read the input file, return Dictionary
Dictionary readDict() {
  Dictionary dict;
  string dictTemp = "";
  ifstream data ("dict.txt");
  if (data.is_open()) {
    while (getline(data,dictTemp)) { 
      int i =0;
      char c;
      while(dictTemp[i]) {
        c=dictTemp[i];
        dictTemp.c_str();
        c = (tolower(c));
        i++;
      }
      dict.AddEntry(dictTemp);
    }
    data.close();
  }

  return dict;
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
vector<string> getWordOptions(string word) {

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
vector<string> getWordAlts(Dictionary& wordDict, vector<string>& wordList) {

  vector<string> matches;

  for (int i = 0; i < wordList.size(); i++) {
    if (wordDict.FindEntry(wordList[i])) {
      matches.push_back(wordList[i]);
    }
  }

  return matches;
}

void spellCheck(string checkFile, Dictionary& dict) {

  // Handle exceptions from opening file
  ifstream infile(checkFile.c_str());
  if(!infile.is_open()) {
    cerr << "Unable to open file" <<endl;
    exit(EXIT_FAILURE);
  }

  cout << endl << "Spellchecking..." << endl << endl;

  // Read input file word by word
  int numMisspelled = 0;
  int lineCount = 0;
  string checkTemp = "";
  while(!infile.eof()) {

    // Parse in the entire word
    checkTemp = "";
    char c;
    infile.get(c);
    c = tolower(c);
    while(isalpha(c) && !infile.eof()) {
      checkTemp += c;
      infile.get(c);
      c = tolower(c);
    }
    // TODO: Currently doesn't handle punctuation

    // Spellcheck word
    if (!dict.FindEntry(checkTemp)) {
      // word doesn't exist. find alternatives
      numMisspelled ++;
      vector<string> wordVariations = getWordOptions(checkTemp);
      vector<string> similarWords = getWordAlts(dict, wordVariations);

      cout << "> Spelling Error - line " << lineCount << endl;
      cout << "Misspelled word: " + checkTemp << endl;
      if (similarWords.size() > 0) {
        // print all potential word matches
        cout << "Did you mean to enter one of the following: ";
        for (int i = 0; i < similarWords.size(); i++) {
          cout << similarWords[i];
          if (i == similarWords.size() - 1) {
            cout << endl << endl;
          } else {
            cout << ", ";
          }
        }
      } else {
        // no potential matches
        cout << "There were no potential word matches." << endl << endl;;
      }
      
    }

    if (c == '\n') {
      // newline
      lineCount ++;
    }
  }

  if (!numMisspelled) {
    cout << "Success! There were no misspellings." << endl;
  } else {
    cout << "Found " << numMisspelled << " misspelled words. Please see details above." << endl;
  }
}

int main(int argc, char* argv[]){

  Dictionary dict = readDict();

  cout << "Please enter the name of a text file to check" << endl;
  cout << "> ";
  string checkFile = "";
  cin >> checkFile;

  spellCheck(checkFile, dict);
  
}
