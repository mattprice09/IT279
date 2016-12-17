#ifndef GRAPHMENU_H
#define GRAPHMENU_H

#include "WDGraph.h"

class GraphMenu {
private:
  vector<WDGraph> graphs;

public:

  virtual ~GraphMenu();

  void run();

  void createGraph();

  void viewGraphs();

  void graphOperation();
};

#endif