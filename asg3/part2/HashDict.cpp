// Implementation file for AVL search tree

#include "Dictionary.h"
#include <algorithm>
#include <iostream>
#include <vector>

// Default constructor
Dictionary::Dictionary() {
  size = 13;
  nElements = 0;
  table = new string[size];

  // Initialize empty table
  for (int i = 0; i < size; i++) {
    table[i] = "";
  }
}

// Copy constructor
Dictionary::Dictionary(const Dictionary& orig) {
  copyDict(orig);
}

// Deconstructor
Dictionary::~Dictionary() {
  deleteDict();
}

// "Assignment" operator
Dictionary& Dictionary::operator=(const Dictionary& orig) {
  // return new Dictionary(orig);
  return *this;
}

// Hash function
unsigned int Dictionary::hash(string& word) {
  unsigned int hashVal = 0;

  for (int i = 0; i < word.size(); i++) {
    hashVal = 37 * hashVal + word[i];
  }

  return hashVal % size; 
}

// Rehash the table/reinsert all elements
void Dictionary::rehash() {
  // Get items from current table
  int oldSize = size;
  string *temp = new string[size];
  for (int i = 0; i < oldSize; i++) {
    temp[i] = table[i];
  }

  // Delete and recreate the class table
  delete[] table;
  size = nextPrime(size * 2);
  table = new string[size];
  nElements = 0;
  
  // Insert elements from old table to new table
  for (int i = 0; i < oldSize; i++) {
    if (!temp[i].empty()) {
      AddEntry(temp[i]);
    }
  }
  delete[] temp;
}

// When adding value, pass in empty string
// When finding value, pass in search term
// Returns the location of the matched string, returns -1 if not found
int Dictionary::resolveCollision(string word, int base) {
	int i = 1;
  int curr = (base + i) % size;
	while(table[curr].compare(word) != 0 && !table[curr].empty()) {
    // Multiply index by 2 as long as there isn't a word match and the current index isn't empty
		i *= 2;
    curr = (base + i) % size;
	}
	
  // Return -1 if we did not find a search term
	if(!word.empty() && table[curr].empty()) {
		curr = -1;
	} 
	return curr;
}

// Add an entry
void Dictionary::AddEntry(string anEntry) {
  unsigned int val = hash(anEntry);

  if(!table[val].empty()) {
    // Resolve collision using quadratic probing
    val = resolveCollision("",val);
  }
  table[val] = anEntry;
  nElements ++;

  // Rehash if table capacity is >= 50%
  if ((float)nElements / (float)size >= 0.5) {
    rehash();
  }
}

// Search for an item in the dictionary
bool Dictionary::FindEntry(string key) {
  bool found = false;
  int val = hash(key);

  if(table[val] == key) {
    found = true;
  }
  // if the value stored at the base index is not empty
  // attempt to resove conflict
  else if(table[val] != "") {
    val = resolveCollision(key,val);
    if(val != -1) {
      found = true;
    }
  } 
  return found;
}
	
void Dictionary::PrintSorted(ostream& outStream) {
  vector<string> sortVals; 
  for(int i = 0;i<size;i++) {
    if(table[i] != "") {
      sortVals.push_back (table[i]);
    }
  }
  std::sort (sortVals.begin(), sortVals.end());
  vector<string>::iterator it;
    for (it = sortVals.begin(); it < sortVals.end(); ++it) {
      outStream << *it << endl;
    }
}

// Deep copy a dictionary
void Dictionary::copyDict(const Dictionary& orig) {

  deleteDict();

  // Deep copy the provided Dictionary
  for (int i = 0; i < orig.size; i++) {
    table[i] = orig.table[i];
  }
  this->size = orig.size;
  this->nElements = orig.nElements;
}

// Delete dictionary data
void Dictionary::deleteDict() {
  delete[] table;
  size = 0;
  nElements = 0;
}

// Helper used by Dictionary::nextPrime
bool Dictionary::isPrime(int size) {
  for (int i=2; i<size; i++) { 
    if(size % i == 0){
      return false;
   }
  }
  return true;
}

// Helper to find next prime number
int Dictionary::nextPrime(int size) {
  while (!isPrime(size)) { 
    size++;
  }
  return size;
}