// file to implement a binary search tree of Entry objects

#ifndef AVLDICT_H
#define AVLDICT_H

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

class AVLDict
{
 private:
  AVLTreeNode* root;
  int size;

 public:

  AVLDict();
  // Creates an empty dictionary;

  AVLDict(const AVLDict& orig);
  // Copy constructor

  virtual ~AVLDict();
  // Destructor

  AVLDict& operator=(const AVLDict& orig);
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

  void copyDict(const AVLDict& orig);
  // copies the contents of orig to this dictionary

  void deleteDict();
  // properly frees all memory occupied by this AVLDict

};

#endif