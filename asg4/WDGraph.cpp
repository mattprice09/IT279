
#include "WDGraph.h"


WDGraph::node::node(string n, int k) {
  name = n;
  key = k;
  visited = false;
}

WDGraph::edge::edge() {
  source = -1;
  sink = -1;
  weight = -1;
}

WDGraph::edge::edge(int src, int snk, int w) {
  source = src;
  sink = snk;
  weight = w;
}

bool WDGraph::edge::operator ()(const edge* lhs, const edge* rhs) {
  return lhs->weight > rhs->weight;
}

WDGraph::WDGraph() {
  weight = 0;
}

WDGraph::~WDGraph() {
  nodes.clear();
  vector<vector <pair<int, int> > >().swap(adjacencyList);
}

void WDGraph::addVertex(string name) {
  int i = adjacencyList.size();

  node* n = new node(name, i);
  nodes[name] = n;

  vector<pair<int, int> > nodeList;
  adjacencyList.push_back(nodeList);
}

void WDGraph::addEdge(string source, string sink, int w) {
  int sourceI = nodes[source]->key;
  int sinkI = nodes[sink]->key;

  pair<int, int> p = make_pair(sinkI, w);
  adjacencyList[sourceI].push_back(p);
  weight = weight + w;
}

map<int, string> WDGraph::getKeysToNames() {
  typedef map<string, node*>::iterator it_type;

  // Get map containing keys mapped to names
  map<int, string> keysToNames;
  for (it_type iterator = nodes.begin(); iterator != nodes.end(); iterator++) {
    keysToNames[iterator->second->key] = iterator->first;
  }

  return keysToNames;
}

void WDGraph::printGraph() {

  map<int, string> keysToNames = getKeysToNames();

  cout << endl << "Total combined graph weight: " << weight << endl;

  // Print all node information
  cout << endl << "NODES" << endl;
  typedef map<string, node*>::iterator it_type;
  for (it_type iterator = nodes.begin(); iterator != nodes.end(); iterator++) {
    int i = iterator->second->key;
    cout << "Name: " << iterator->first << ", key: " << i << endl;

    // Print node's edge information
    for (int e = 0; e < adjacencyList[i].size(); e++) {
      int j = adjacencyList[i][e].first;
      cout << "Source: " << i << " (" << iterator->first << ")";
      cout << ", Sink: " << j << " (" << keysToNames[j] << ")";
      cout << ", Weight: " << adjacencyList[i][e].second << endl;
    }
  }
}

int WDGraph::edgeWeight(int source, int sink) {
  if (source >= adjacencyList.size()) {
    return -1;
  }
  for (int i = 0; i < adjacencyList[source].size(); i++) {
    if (adjacencyList[source][i].first == sink) {
      return adjacencyList[source][i].second;
    }
  }
  return -1;
}

// Determine the minimum spanning tree of a directed graph using Kruskal's algorithm.
// REQUIRES: The tree must be connected.
void WDGraph::minSpanTree() {

  // Initialize disjoint sets
  DisjointSets ds(adjacencyList.size());
  
  // Create priority queue containing edges
  priority_queue<edge*, vector<edge*>, edge> pq;
  for (int i = 0; i < adjacencyList.size(); i++) {
    for (int j = 0; j < adjacencyList[i].size(); j++) {
      // Create new edge, push into priority queue
      edge* e = new edge(i, adjacencyList[i][j].first, adjacencyList[i][j].second);
      pq.push(e);
    }
  }

  // Apply Kruskal's algorithm
  int edgesDone = 0;
  while (edgesDone < adjacencyList.size()-1) {
    int u = pq.top()->source;
    int v = pq.top()->sink;
    int w = pq.top()->weight;
    pq.pop();
    
    int uSet = ds.find(u);
    int vSet = ds.find(v);
    if (uSet != vSet) {
      edgesDone++;
      ds.unionSets(v, u);
    }
  }

  // Print out minimuim spanning tree
  map<int, string> keysToNames = getKeysToNames();
  for (int i = 0; i < ds.getSets().size(); i++) {
    if (ds.getSets()[i] != -1) {
      string src = keysToNames[i];
      string snk = keysToNames[ds.getSets()[i]];
      cout << "Edge: " << src << " -> " + snk << ", weight: " << edgeWeight(i, ds.getSets()[i]) << endl;
    }
  }
}

int main() {
  WDGraph testGraph;

  string v1 = "A";
  string v2 = "B";
  string v3 = "C";
  string v4 = "D";
  string v5 = "E";
  testGraph.addVertex(v1);
  testGraph.addVertex(v2);
  testGraph.addVertex(v3);
  testGraph.addVertex(v4);
  testGraph.addVertex(v5);
  testGraph.addEdge(v1, v2, 8);
  testGraph.addEdge(v2, v1, 20);
  testGraph.addEdge(v2, v5, 12);
  testGraph.addEdge(v3, v4, 10);
  testGraph.addEdge(v4, v2, 6);
  testGraph.addEdge(v5, v3, 9);
  // testGraph.printGraph();
  testGraph.minSpanTree();
}
