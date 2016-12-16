// file to implement a hash table
// duplicated and name kept from prompt file to allow us to use the
// same driver program, SpellCheck.cpp

#ifndef WDGRAPH_H
#define WDGRAPH_H

using namespace std;
#include <utility>
#include <vector>

class WDGraph {
 private:
  vector< vector< pair<int, int>>> adjacencyList;

 public:

  WDGraph();
  // Creates an empty WDGraph;

  WDGraph(const WDGraph& orig);
  // Copy constructor

  virtual ~WDGraph();
  // Destructor

 private:

};

#endif