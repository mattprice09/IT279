// file to implement a hash table
// duplicated and name kept from prompt file to allow us to use the
// same driver program, SpellCheck.cpp

#ifndef WDGRAPH_H
#define WDGRAPH_H

using namespace std;
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "DisjointSets.h"

class WDGraph {
 private:
  // Represents a vertex in the graph.
  class node {
  public:

    node();
    node(string n, int k);

    bool operator()(const node* lhs, const node* rhs);

    string name;
    int key;
    bool visited;
    int weight;
  };
  
  // Map node names to node objects so that we can efficiently get information on a vertex
  map<string, node*> nodes;
  // Each node is an item in the adjacency list containing a vector of edges (represented by pairs).
  // pair.first -> the destination node
  // pair.second -> the destination weight
  vector< vector< pair<int, int> > > adjacencyList;
  int weight;

 public:

  class edge {
  public:

    edge();
    edge(int src, int snk, int w);

    bool operator()(const edge* lhs, const edge* rhs);

    int source;
    int sink;
    int weight;
  };

  WDGraph();

  virtual ~WDGraph();
  // Destructor

  int getDegree();
  int getSize();
  int getTotalWeight();

  void readGraph(string fname);

  void addVertex(string name);

  void addEdge(string source, string sink, int weight);

  int edgeWeight(int source, int sink);

  void topologicalSort();

  void shortestPath();

  void minSpanTree();

  void printGraph();

  map<int, string> getKeysToNames();

 private:

};

#endif
