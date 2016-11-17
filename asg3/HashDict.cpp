// Implementation file for AVL search tree

#include "HashDict.h"

HashDict::HashDict() {
  size = 13;
  table = new string[size];
}

HashDict::HashDict(const HashDict& orig) {
  this->copyDict(orig);
}

HashDict::~HashDict() {
  this->deleteDict();
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

