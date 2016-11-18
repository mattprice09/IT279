// Implementation file for AVL search tree

#include "HashDict.h"

HashDict::HashDict() {
  size = 13;
  n_elements = 0;
  table = new string[size];

  // Initialize empty table
  for (int i = 0; i < size; i++) {
    table[i] = "";
  }
}

HashDict::HashDict(const HashDict& orig) {
  this->copyDict(orig);
}

HashDict::~HashDict() {
  this->deleteDict();
}

void HashDict::setTable(string item, int i) {
  this->table[i] = item;
}

string* HashDict::getTable() {
  return this->table;
}

void HashDict::setSize(int i) {
  this->size = i;
}
int HashDict::getSize() {
  return this->size;
}

void HashDict::setNElements(int i) {
  this->n_elements = i;
}
int HashDict::getNElements() {
  return this->n_elements;
}

// Hash function
unsigned int HashDict::hash(string& word) {
  unsigned int hashVal = 0;

  for (int i = 0; i < word.size(); i++) {
    hashVal = 37 * hashVal + word[i];
  }

  return hashVal % this->size; 
}

void HashDict::rehash() {

  // Get items from current table
  int oldSize = this->size;
  string *temp = new string[this->size];
  for (int i = 0; i < oldSize; i++) {
    temp[i] = this->table[i];
  }

  // Delete and recreate the class table
  delete[] this->table;
  this->size *= 2;
  this->table = new string[this->size];
  
  // Insert elements from old table to new table
  for (int i = 0; i < oldSize; i++) {
    if (!temp[i].empty()) {

      // hash base value
      unsigned int hashVal = this->hash(temp[i]);
      // find first open table location via quadratic probing
      int hashLocation = this->resolveCollision("", hashVal);
      this->table[hashLocation] = temp[i];
    }
  }
  
  delete[] temp;
}

// When adding value, pass in empty string
// When finding value, pass in search term
// Returns the location of the matched string, returns -1 if not found
int HashDict::resolveCollision(string word, int base) {
	int i = 1;
  int curr = (base + i) % this->size;
	while(this->table[curr].compare(word) != 0 && !this->table[curr].empty()) {
    // Multiple index by 2 as long as there isn't a word match and the current index isn't empty
		i *= 2;
    curr = (base + i) % this->size;
	}
	
	if(!word.empty() && this->table[curr].empty()) {
		curr = -1;
	} 
	return curr;
}

HashDict& HashDict::operator=(const HashDict& orig) {
  return *this;
}

void HashDict::AddEntry(string anEntry) {
  int val = hash(anEntry);
  if(!table[val].empty()) {
    val = resolveCollision("",val);
  }
  table[val] = anEntry;
  this->n_elements ++;

  if ((float)this->n_elements / (float)this->size >= 0.5) {
    this->rehash();
  }
}

bool HashDict::FindEntry(string key) {
  bool found = false;
  int val = hash(key);
  if(!table[val].empty()) {
    if(table[val] == key) {
      found = true;
    }
  }
  else {
    val = resolveCollision("",val);
    if(val == -1) {
      found = false;
    }
    else {
      found = true;
    }
  } 
  return found;
}
	
void HashDict::PrintSorted(ostream& outStream) {
}

void HashDict::copyDict(const HashDict& orig) {
}

void HashDict:: deleteDict() {
}

bool isPrime(int size) {
  for (int i=2; i<size; i++) { 
    if(size % i == 0){
      return false;
   }
  }
  return true;
}

int main() {

  HashDict* dict = new HashDict();

  // dict->setTable("apple", 0);
  // dict->setTable("orange", 1);
  // dict->setTable("dfsasdf", 4);
  // dict->setTable("testing", 5);
  // dict->setTable("word", 9);

  dict->AddEntry("apple");
  dict->AddEntry("apple");
  dict->AddEntry("apple");
  dict->AddEntry("apple");
  dict->AddEntry("apple");
  dict->AddEntry("apple");
  dict->AddEntry("apple");
  // dict->AddEntry("apple");

  // dict->rehash();

  string* t = dict->getTable();

  for (int i = 0; i < dict->getSize(); i++) {
    cout << "Index: " << i << ", " + t[i] << endl;
  }
  
}
