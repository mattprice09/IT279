// file to implement a hash table
// duplicated and name kept from prompt file to allow us to use the
// same driver program, SpellCheck.cpp

#ifndef WDGRAPH_H
#define WDGRAPH_H

using namespace std;
#include <map>
#include <string>
#include <utility>
#include <vector>



class WDGraph {
 private:
  // Map node names to node objects so that we can efficiently get information on a vertex
  map<int, node> nodes;
  // Each node is an item in the adjacency list containing a vector of edges (represented by pairs).
  // pair.first -> the destination node
  // pair.second -> the destination weight
  vector< vector< pair<int, int>>> adjacencyList;

 public:

  // Represents a vertex in the graph.
  class node {
  public:

    node();
    node(string n);

    string name;
    int key;
    bool visited;
  }

  WDGraph();
  // Creates an empty WDGraph;

  WDGraph(const WDGraph& orig);
  // Copy constructor

  virtual ~WDGraph();
  // Destructor

  void addVertex(string name);

  void addEdge(string source, string dest, int weight);

  void topologicalSort();

  void shortestPath(string sourceNode);

  void minSpanTree();

 private:

};

#endif