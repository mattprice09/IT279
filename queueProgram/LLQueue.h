
#ifndef LLQUEUE_H
#define LLQUEUE_H

#include <iostream>
#include <string>

using namespace std;

struct node {
  int x;
  struct node *next;
};

class LLQueue {
  
public:
  LLQueue();

  struct node *head;
  struct node *tail;
  int length;

  void enqueue(int val);
  int dequeue();
};

#endif
