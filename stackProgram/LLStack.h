
#ifndef LLSTACK_H
#define LLSTACK_H

#include <iostream>
#include <string>

using namespace std;

struct node {
  int x;
  struct node *next;
};

class LLStack {
  
public:
  LLStack();

  int size;
  struct node *top;

  void push(node*& n);
  node* pop();
  void printStack();
};

#endif
