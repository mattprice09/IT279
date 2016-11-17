// file to implement a binary search tree of Entry objects

#ifndef HASHDICT_H
#define HASHDICT_H

#include <iostream>
#include <string>

using namespace std;


class HashDict
{
 private:
  string[] table;
  int size;

 public:

  HashDict();
  // Creates an empty dictionary;

  HashDict(const HashDict& orig);
  // Copy constructor

  virtual ~HashDict();
  // Destructor

  HashDict& operator=(const HashDict& orig);
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

  void copyDict(const HashDict& orig);
  // copies the contents of orig to this dictionary

  void deleteDict();
  // properly frees all memory occupied by this HashDict

};

#endif
