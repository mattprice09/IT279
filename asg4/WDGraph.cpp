
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

void WDGraph::printGraph() {

  typedef map<string, node*>::iterator it_type;

  // Get map containing keys mapped to names
  map<int, string> keysToNames;
  for (it_type iterator = nodes.begin(); iterator != nodes.end(); iterator++) {
    keysToNames[iterator->second->key] = iterator->first;
  }

  cout << endl << "Total combined graph weight: " << weight << endl;

  // Print all node information
  cout << endl << "NODES" << endl;
  for (it_type iterator = nodes.begin(); iterator != nodes.end(); iterator++) {
    int i = iterator->second->key;
    cout << "Name: " << iterator->first << ", key: " << i << endl;

    // Print node's edge information
    for (int e = 0; e < adjacencyList[i].size(); e++) {
      int j = adjacencyList[i][e].first;
      cout << "Source: " << i << " (" << iterator->first << ")";
      cout << ", Sink: " << j << " (" << keysToNames[j] << ")";
      cout << ", Weight: " << adjacencyList[i][e].second << endl;;
    }
  }
}

void WDGraph::minSpanTree() {
  // Initialize disjoint sets
  // DisjointSets ds(adjacencyList.size());
  
  // Create priority queue containing edges
  priority_queue<edge*, vector<edge*>, edge> pq;
  for (int i = 0; i < adjacencyList.size(); i++) {
    for (int j = 0; j < adjacencyList[i].size(); j++) {
      // Create new edge, push into priority queue
      edge* e = new edge(i, adjacencyList[i][j].first, adjacencyList[i][j].second);
      pq.push(e);
    }
  }

  // Print out priority queue
  while (!pq.empty()) {
    cout << pq.top()->weight << endl;
    pq.pop();
  }

}

// adjacencyList:
// index 0: 

int main() {
  WDGraph testGraph;

  string v1 = "Bobs vertex";
  string v2 = "Johns vertex";
  string v3 = "johnny";
  string v4 = "jessica";
  string v5 = "james";
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
  testGraph.printGraph();
  testGraph.minSpanTree();
}
