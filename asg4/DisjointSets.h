// file to implement a hash table
// duplicated and name kept from prompt file to allow us to use the
// same driver program, SpellCheck.cpp

#ifndef DISJOINTSETS_H
#define DISJOINTSETS_H

using namespace std;
#include <vector>


class DisjointSets {
 private:
  vector <int> s;

 public:

  DisjointSets();

  DisjointSets(int numVertices);

  virtual ~DisjointSets();
  // Destructor

  int find(int x);

  void unionSets(int root1, int root2);

  vector<int> getSets();

};

#endif
