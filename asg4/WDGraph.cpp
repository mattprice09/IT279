
#include "WDGraph.h"

WDGraph::node::node(string n, int k) {
  name = n;
  key = k;
  visited = false;
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
    for (int edge = 0; edge < adjacencyList[i].size(); edge++) {
      int j = adjacencyList[i][edge].first;
      cout << "Source: " << i << " (" << iterator->first << ")";
      cout << ", Sink: " << j << " (" << keysToNames[j] << ")";
      cout << ", Weight: " << adjacencyList[i][edge].second << endl;;
    }
  }
}

int main() {
  WDGraph testGraph;

  string v1 = "Bobs vertex";
  string v2 = "Johns vertex";
  testGraph.addVertex(v1);
  testGraph.addVertex(v2);
  testGraph.addEdge(v1, v2, 8);
  testGraph.addEdge(v2, v1, 20);
  testGraph.printGraph();
}
