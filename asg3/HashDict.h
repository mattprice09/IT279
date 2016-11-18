// file to implement a binary search tree of Entry objects

#ifndef HASHDICT_H
#define HASHDICT_H

#include "Dictionary.h"

class HashDict: public Dictionary {
 private:
  string* table;
  int nElements;
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

  void setTable(string item, int i);
  string* getTable() const;

  string getTableItem(int i) const;

  void setSize(int i);
  int getSize() const;

  void setNElements(int i);
  int getNElements() const;

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
  // properly frees all memory occupied by this Dictionary

  void rehash();

  unsigned int hash(string& word);

  // When adding value, pass in empty string
  // When finding value, pass in search term
  // Returns the location of the matched string, returns -1 if not found
  int resolveCollision(string word, int base);

  // Helpers to find next prime number
  int nextPrime(int size);
  bool isPrime(int size);


};

#endif