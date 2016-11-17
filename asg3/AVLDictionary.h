// file to implement a binary search tree of Entry objects

#ifndef AVLDICTIONARY_H
#define AVLDICTIONARY_H

#include <iostream>
#include <string>

using namespace std;

struct AVLTreeNode
{
  string data;
  int height;
  AVLTreeNode* left;
  AVLTreeNode* right;
};

class AVLDictionary
{
 private:
  AVLTreeNode* root;
  int size;

 public:

  AVLDictionary();
  // Creates an empty dictionary;

  AVLDictionary(const AVLDictionary& orig);
  // Copy constructor

  virtual ~AVLDictionary();
  // Destructor

  AVLDictionary& operator=(const AVLDictionary& orig);
  // assignment operator

  void AddEntry(string anEntry);
  // Preconditions: anEntry has a key not already in the dictionary
  // Postconditions: anEntry has been added to the dictionary

  bool FindEntry(string key);
  // Postconditions: if key is found in the dictionary, returns true; 
  //   otherwise returns false

  void PrintSorted(ostream& outStream);
  // Postconditions: has printed contents of the dictionary in order

 private:

  void copyDict(const AVLDictionary& orig);
  // copies the contents of orig to this dictionary

  void deleteDict();
  // properly frees all memory occupied by this AVLDictionary

};

#endif