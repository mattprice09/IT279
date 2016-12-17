
#include "DisjointSets.h"

DisjointSets::DisjointSets() {}

DisjointSets::DisjointSets(int numVertices) {
  for (int i = 0; i < numVertices; i++) {
    s.push_back(-1);
  }
}

DisjointSets::~DisjointSets() {
  vector<int>().swap(s);
}

int DisjointSets::find(int x) {
  if (s[x] < 0) {
    return x;
  }
  return find(s[x]);
}

void DisjointSets::unionSets(int root1, int root2) {
  s[root2] = root1;
}

vector<int> DisjointSets::getSets() {
  return s;
}
