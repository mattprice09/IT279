// Implementation file for AVL search tree

#include "HashDict.h"

HashDict::HashDict() {
  size = 13;
  n_elements = 0;
  table = new string[size];

  // Initialize empty table
  for (int i = 0; i < table.size(); i++) {
    table[i] = "";
  }
}

HashDict::HashDict(const HashDict& orig) {
  this->copyDict(orig);
}

HashDict::~HashDict() {
  this->deleteDict();
}

// Hash function
unsigned int HashDict::hash(string& word) {
  unsigned int hashVal = 0;

  for (char ch : word)
    hashVal = 37 * hashVal + ch

  return hashVal % this.size; 
}

void HashDict::rehash() {

  // Get items from current table
  string* temp = new string[this.size * 2];
  for (int i = 0; i < this.size; i++) {
    temp[i] = this.table[i];
  }
}

// When adding value, pass in empty string
// When finding value, pass in search term
// Returns the location of the matched string, returns -1 if not found
int HashDict::resolveCollision(string word, int base) {
	int i = 1;
	while(table[base + i].compare(word) != 0 || table[base + i].empty()) {
		i *= 2;
	}
	
	if(!word.empty() && table[base+i].empty) {
		base = -1;
	} else {
		base += i;
	}
	return base;
}

HashDict& HashDict::operator=(const HashDict& orig) {
  return *this;
}

void HashDict::AddEntry(string anEntry) {
}

bool HashDict::FindEntry(string key) {
}
	
void HashDict::PrintSorted(ostream& outStream) {
}

void HashDict::copyDict(const HashDict& orig) {
}

void HashDict:: deleteDict() {
}

