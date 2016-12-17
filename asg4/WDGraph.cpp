
#include "WDGraph.h"

WDGraph::node::node() {
  name = "";
  key = -1;
  visited = false;
  weight = -1;
}

WDGraph::node::node(string n, int k) {
  name = n;
  key = k;
  visited = false;
  weight = -1;
}

bool WDGraph::node::operator ()(const node* lhs, const node* rhs) {
  return lhs->weight > rhs->weight;
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

// Get # of nodes
int WDGraph::getDegree() {
  return adjacencyList.size();
}

// Get # of edges
int WDGraph::getSize() {
  int eNum = 0;
  for (int i = 0; i < adjacencyList.size(); i++) {
    eNum = eNum + adjacencyList[i].size();
  }
  return eNum;
}

// Get total graph weight
int WDGraph::getTotalWeight() {
  int tot = 0;
  for (int i = 0; i < adjacencyList.size(); i++) {
    for (int j = 0; j < adjacencyList[i].size(); j++) {
      tot += adjacencyList[i][j].second;
    }
  }
  return tot;
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
    cout << "> Name: " << iterator->first << ", key: " << i << endl;

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

void WDGraph::topologicalSort() {

  int vertices = adjacencyList.size();

  vector< vector <int> > modList;

  for (int i = 0; i < adjacencyList.size(); i++)
  {
    for (int j = 0; j < adjacencyList.at(i).size(); j++)
    {
      int& whatever = adjacencyList.at(i).at(j).first;

      modList[i].push_back(whatever);
    }
  }

  int visitCount = 0;

  queue<int> mainQueue;
  
  //vector of size however many vertices there are, all indegrees set to 0
  vector <int> inDegrees(vertices, 0);

  vector <int> topResult;

  for (int i = 0; i < vertices; i++)
  {

    for (int j = 0; j < adjacencyList.at(i).size(); j++)
    {
      inDegrees[adjacencyList.at(i).at(j).first]++;
    }
  }

  for (int i = 0; i < vertices; i++)
  {
    if (inDegrees[i] == 0)
    {
      mainQueue.push(i);
    }
  }

  while (!mainQueue.empty())
  {
    int temp = mainQueue.front();
    mainQueue.pop();

    topResult.push_back(temp);


    for (int i = 0; i < adjacencyList.at(temp).size(); i++)
    {
      if ((inDegrees[i] - 1) == 0)
      {
        mainQueue.push(i);
      }

      visitCount++;
    }
  }

  if (visitCount != vertices)
  {
    cout << "Error: Cycle in the graph\n";
    return;
  }

  for (int i = 0; i < topResult.size(); i++)
  {
    cout << topResult[i] << " ";
  }
  cout << endl;
}

void WDGraph::readGraph(string fname) {
  ifstream file;

  file.open(fname.c_str());
  string line;
  int vertVals;
  int vertices;
  int edges = 0;
  if (!file) {
    cout << "Error: Could not find the requested file.";
    return;
  }
  else {
    //find amount of vertices there will be
    getline(file, line);
    cout << line << endl;
    vertices = atoi(line.c_str());
  }
  //get vertices 
  while(file && vertices > 0) {
    vertices--;
    getline(file,line);
    cout << line << endl;
    //add vertices
    addVertex(line);
  }
  if (getline(file, line)) {
    cout << line << endl;
    edges = atoi(line.c_str());
  }
  
  while(getline(file, line)) {
    stringstream lineStream(line);

    string value;
    int c = 0;
    string fr;
    string to;
    while (lineStream >> value) {
      if (c == 0) {
        fr = value;
      } else if (c == 1) {
        to = value;
      } else if (c == 2) {
        edges--;
        //add edge
        int edgeVal = atoi(value.c_str());
        addEdge(fr, to, edgeVal);
      }
      c++;
    }
  }
  file.close();
}

void WDGraph::shortestPath() {
  string sourceNode;

  cout << endl;
  printGraph();
  cout << endl;
  cout << "Please enter the source node: " << endl;
  cin >> sourceNode;

  if (nodes.find(sourceNode) == nodes.end()) {
    cout << "Invalid node name. Please try again." << endl;
    return;
  }

  // Get map containing keys mapped to names
  map<int, string> keysToNames = getKeysToNames();

  // Initialize current weights to infinity(total graph weight + 1)
  int infinity = getTotalWeight()+1;
  priority_queue<node*, vector<node*>, node> pq;
  for (int i = 0; i < adjacencyList.size(); i++) {
    if (i != nodes[sourceNode]->key) {
      nodes[keysToNames[i]]->weight = infinity;
    }
  }
  nodes[sourceNode]->weight = 0;
  pq.push(nodes[sourceNode]);

  // Begin Dijkstra's algorithm
  vector<int> from;
  for (int i = 0; i < adjacencyList.size(); i++) {
    from.push_back(-1);
  }
  int numComplete = 0;
  while (numComplete < adjacencyList.size()) {
    node* v = pq.top();
    pq.pop();

    // Handle incomplete graphs
    if (adjacencyList[v->key].size() == 0) {
      cout << endl << "ERROR: Graph is not connected. Please use a valid graph." << endl;
      return;
    }

    if (v->visited == false) {
      // Check all adjacent nodes of current node
      for (int w = 0; w < adjacencyList[v->key].size(); w++) {
        int cw = adjacencyList[v->key][w].second;
        int cn = adjacencyList[v->key][w].first;

        // Check if we need to decrease weight
        if (nodes[keysToNames[cn]]->visited == false && v->weight + cw < nodes[keysToNames[cn]]->weight) {
          nodes[keysToNames[cn]]->weight = v->weight + cw;
          from[cn] = v->key;
          pq.push(nodes[keysToNames[cn]]);
        }
      }
      v->visited = true;
      numComplete++;
    }
  }

  // Print results
  cout << endl << "Shortest path(s): " << endl;
  for (int i = 0; i < from.size(); i++) {
    int curr = i;
    vector<int> path;
    path.push_back(i);
    int pathWeight = 0;
    while (from[curr] > 0) {
      path.push_back(from[curr]);
      pathWeight = pathWeight + edgeWeight(from[curr], curr);
      curr = from[curr];
    }
    if (path.size() > 0) {
      cout << "To vertex " << keysToNames[i] << "--> ";
      for (int j = path.size()-1; j >= 0; j--) {
        cout << keysToNames[path[j]] << ", ";
      }
      cout << "path weight: " << pathWeight << endl;
    }
  }
  
  // Reset graph so that it can be used again
  for (int i = 0; i < adjacencyList.size(); i++) {
    nodes[keysToNames[i]]->visited = false;
    nodes[keysToNames[i]]->weight = -1;
  }
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
  cout << "Minimum spanning tree: " << endl;;
  map<int, string> keysToNames = getKeysToNames();
  for (int i = 0; i < ds.getSets().size(); i++) {
    if (ds.getSets()[i] != -1) {
      string src = keysToNames[i];
      string snk = keysToNames[ds.getSets()[i]];
      cout << "Edge: " << src << " -> " + snk << ", weight: " << edgeWeight(i, ds.getSets()[i]) << endl;
    }
  }
}

