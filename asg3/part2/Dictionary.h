// file to implement a hash table
// duplicated and name kept from prompt file to allow us to use the
// same driver program, SpellCheck.cpp

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
using namespace std;

class Dictionary {
 private:
  string* table;
  int nElements;
  int size;

 public:

  Dictionary();
  // Creates an empty dictionary;

  Dictionary(const Dictionary& orig);
  // Copy constructor

  virtual ~Dictionary();
  // Destructor

  Dictionary& operator=(const Dictionary& orig);
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

  void copyDict(const Dictionary& orig);
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