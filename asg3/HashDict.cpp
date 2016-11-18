// Implementation file for AVL search tree

#include "HashDict.h"

// Helper used by HashDict::nextPrime
bool isPrime(int size) {
  for (int i=2; i<size; i++) { 
    if(size % i == 0){
      return false;
   }
  }
  return true;
}

// Helper to find next prime number
int nextPrime(int size) {
  while (!isPrime(size)) { 
    size++;
  }
  return size;
}

// Default constructor
HashDict::HashDict() {
  size = 13;
  nElements = 0;
  table = new string[size];

  // Initialize empty table
  for (int i = 0; i < size; i++) {
    table[i] = "";
  }
}

// Copy constructor
HashDict::HashDict(const HashDict& orig) {
  this->copyDict(orig);
}

// Deconstructor
HashDict::~HashDict() {
  this->deleteDict();
}

// "Assignment" operator
HashDict& HashDict::operator=(const HashDict& orig) {
  return new HashDict(orig);
}

// GETTERS/SETTERS START
void HashDict::setTable(string item, int i) {
  this->table[i] = item;
}

string* HashDict::getTable() const {
  return this->table;
}

string HashDict::getTableItem(int i) const {
  return this->table[i];
}

void HashDict::setSize(int i) {
  this->size = i;
}
int HashDict::getSize() const {
  return this->size;
}

void HashDict::setNElements(int i) {
  this->nElements = i;
}
int HashDict::getNElements() const {
  return this->nElements;
}
// GETTERS/SETTERS END

// Hash function
unsigned int HashDict::hash(string& word) {
  unsigned int hashVal = 0;

  for (int i = 0; i < word.size(); i++) {
    hashVal = 37 * hashVal + word[i];
  }

  return hashVal % this->size; 
}

// Rehash the table/reinsert all elements
void HashDict::rehash() {

  // Get items from current table
  int oldSize = this->size;
  string *temp = new string[this->size];
  for (int i = 0; i < oldSize; i++) {
    temp[i] = this->table[i];
  }

  // Delete and recreate the class table
  delete[] this->table;
  this->size = nextPrime(this->size * 2);
  this->table = new string[this->size];
  this->nElements = 0;
  
  // Insert elements from old table to new table
  for (int i = 0; i < oldSize; i++) {
    if (!temp[i].empty()) {
      this->AddEntry(temp[i]);
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
	
  // Return -1 if we did not find a search term
	if(!word.empty() && this->table[curr].empty()) {
		curr = -1;
	} 
	return curr;
}

// Add an entry
void HashDict::AddEntry(string anEntry) {
  unsigned int val = hash(anEntry);

  cout << "Root index: " << val << ", word: " << anEntry << endl;

  if(!this->table[val].empty()) {
    // Resolve collision using quadratic probing
    val = this->resolveCollision("",val);
  }
  this->table[val] = anEntry;
  this->nElements ++;

  // Rehash if table capacity is >= 50%
  if ((float)this->nElements / (float)this->size >= 0.5) {
    this->rehash();
  }
}

// Search for an item in the dictionary
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

// Deep copy a dictionary
void HashDict::copyDict(const HashDict& orig) {

  this->deleteDict();

  // Deep copy the provided HashDict
  for (int i = 0; i < orig.getSize(); i++) {
    this->table[i] = orig.getTableItem(i);
  }
  this->size = orig.getSize();
  this->nElements = orig.getNElements();
}

// Delete dictionary data
void HashDict::deleteDict() {
  delete[] this->table;
  this->size = 0;
  this->nElements = 0;
}


int main() {

  HashDict* dict = new HashDict();

  bool debug = false;

  if (debug){
    for (int x = 0; x < 8; x++) {
      dict->AddEntry("apple");
      cout << endl << "Added 'apple', current dict capacity: " << dict->getNElements();
      cout << " / " << dict->getSize() << endl;
      for (int i = 0; i < dict->getSize(); i++) {
        cout << "Index: " << i << ", " + dict->getTableItem(i) << endl;
      }

      cout << "Press enter to view next iteration" << endl;
      cin.ignore();
    }
  }

  if (dict->FindEntry("apple")) {
    cout << "Found" << endl;
  }
}
