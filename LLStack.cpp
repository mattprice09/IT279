
#include "LLStack.h"

LLStack::LLStack() {
  size = 0;
  top = NULL;
}

void LLStack::push(node*& n) {
  if (top) {
    // Stack not empty
    n->next = top;
  } else {
    // Stack is empty
    n->next = NULL;
  }
  top = n;
  size ++;
}

node* LLStack::pop() {
  if (! top) {
    return NULL;
  }

  node *temp = top;

  if (top->next == NULL) {
    top = NULL;
  } else {
    top = top->next;
  }
  size --;
  return temp;
}

void LLStack::printStack() {
  cout << "Printing stack from top to bottom..." << endl;

  node *curr = top;
  while (curr) {
    cout << "val=" << " " << curr->x << endl;
    curr = curr->next;
  }

  cout << "Finished printing stack." << endl;
}