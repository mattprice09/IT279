
#include "GraphMenu.h"

// Helper for code cleanliness
void printLine() {
  for (int i = 0; i < 90; i++) {
    cout << "-";
  }
  cout << endl;
}

// Helper that gets user input
string getInput() {
  string inp;
  cout << "Please choose an option: " << endl;

  printLine();
  printf("%-15s%-25s%-25s\n", "Option", "Action", "Description"); 
  printLine();
  printf("%-15s%-25s%-25s\n", "1", "Create graph", "Create a new directed weighted graph"); 
  printf("%-15s%-25s%-25s\n", "2", "View graphs", "View your graphs"); 
  printf("%-15s%-25s%-25s\n", "3", "Perform operation", "Perform an operation on a graph");
  printf("%-15s%-25s%-25s\n", "9", "Exit", "Exit out of the program");  
  printLine();
  cin >> inp;

  return inp;
}


GraphMenu::~GraphMenu() {
  vector<WDGraph>().swap(graphs);
}

// Create a graph from a file name
void GraphMenu::createGraph() {
  
  string fname;
  cout << "Please enter the name of the file containing your graph: " << endl;
  cin >> fname;

  WDGraph graph;
  graph.readGraph(fname);

  // string v1 = "A";
  // string v2 = "B";
  // string v3 = "C";
  // string v4 = "D";
  // string v5 = "E";
  // graph.addVertex(v1);
  // graph.addVertex(v2);
  // graph.addVertex(v3);
  // graph.addVertex(v4);
  // graph.addVertex(v5);
  // graph.addEdge(v1, v2, 8);
  // graph.addEdge(v2, v1, 20);
  // graph.addEdge(v2, v5, 12);
  // graph.addEdge(v3, v4, 10);
  // graph.addEdge(v4, v2, 6);
  // graph.addEdge(v5, v3, 9);

  graphs.push_back(graph);

}

// View all graphs 
void GraphMenu::viewGraphs() {

  if (graphs.size() == 0) {
    cout << endl << "You don't have any graphs to run operations on. You must first create a graph." << endl;
    return;
  }
  cout << endl;

  printLine();
  printf("%-15s%-15s%-15s%-15s\n", "Graph #", "Degree", "Size", "Total Weight"); 
  printLine();

  for (int i = 0; i < graphs.size(); i++) {
    // graphs[i].printGraph();
    printf("%-15i%-15i%-15i%-15i\n", i, graphs[i].getDegree(), graphs[i].getSize(), graphs[i].getTotalWeight()); 
  }

  printLine();
  cout << endl;
}

// Perform a graph operation on a graph
void GraphMenu::graphOperation() {

  if (graphs.size() == 0) {
    cout << endl << "You don't have any graphs to run operations on. You must first create a graph." << endl;
    return;
  }

  viewGraphs();

  // Get graph # from user
  cout << "Please select a graph to operate on: " << endl;
  string resp;
  cin >> resp;
  int graphNum = atoi(resp.c_str());
  if (graphNum >= graphs.size()) {
    cout << "Graph doesn't exist." << endl;
    return;
  }

  // Map input variables to graph operations
  map<string, void (WDGraph::*)()> functionMap;
  functionMap["1"] = &WDGraph::topologicalSort;
  functionMap["2"] = &WDGraph::shortestPath;
  functionMap["3"] = &WDGraph::minSpanTree;
  functionMap["4"] = &WDGraph::printGraph;

  // Print out algorithm options
  cout << endl;
  printLine();
  printf("%-15s%-25s%-25s\n", "Operation #", "Operation", "Description"); 
  printLine();
  printf("%-15s%-25s%-25s\n", "1", "Topological Sort", "Perform the topological sort algorithm");
  printf("%-15s%-25s%-25s\n", "2", "Shortest paths", "Find shortest paths using Dijkstra's algorithm");
  printf("%-15s%-25s%-25s\n", "3", "Minimum Spanning Tree", "Get the minimum spanning tree using Kruskal's algorithm");
  printf("%-15s%-25s%-25s\n", "4", "Print graph details", "Print vertices and edges of the graph");
  printLine();
  cout << endl; 
  cout << "Please choose an operation to run: " << endl;
  cin >> resp;

  // Perform algorithm
  map<string, void (WDGraph::*)()>::iterator iter = functionMap.find(resp);
  if (iter != functionMap.end()) {
    // Call function requested from user
    cout << endl << "Results: " << endl;
    (graphs[graphNum].*iter->second)();
    cout << endl;
  } else {
    cout << "Invalid input. Please enter a valid response.";
  }
}

// Run the menu loop
void GraphMenu::run() {
  string inp = getInput();

  // Map string response values to function calls
  map<string, void (GraphMenu::*)()> functionMap;
  functionMap["1"] = &GraphMenu::createGraph;
  functionMap["2"] = &GraphMenu::viewGraphs;
  functionMap["3"] = &GraphMenu::graphOperation;

  while (inp != "9") {

    // Handle user response
    map<string, void (GraphMenu::*)()>::iterator iter = functionMap.find(inp);
    if (iter != functionMap.end()) {
      // Call function requested from user
      (this->*iter->second)();
    } else {
      cout << "Invalid input. Please enter a valid response.";
    }

    inp = getInput();
  }
}

int main() {
  GraphMenu mainMenu;
  mainMenu.run();
}
