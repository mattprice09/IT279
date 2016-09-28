
#ifndef LLSTACK_H
#define LLSTACK_H

#include <iostream>
#include <string>

using namespace std;

// Node class
template <class T>
class node {
public:
  T data;
  node<T> *next;
};

// LLStack class headers
template <class T>
class LLStack {
public:
  LLStack();

  int size;
  node<T> *top;

  void push(T val);
  T pop();
  T peek();
  void printStack();
};

// ~~ Class implementation below

// Default constructor
template <class T>
LLStack<T>::LLStack() {
  size = 0;
  top = NULL;
}

// Push value onto top of stack
template <class T>
void LLStack<T>::push(T val) {
  node<T> *n = new node<T>;
  n->data = val;
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

// Pop/return value from top of stack
template <class T>
T LLStack<T>::pop() {

  T val = top->data;
  if (top->next == NULL) {
    delete top;
  } else {
    node<T> *tmp = top->next;
    delete top;
    top = tmp;
  }
  size --;
  return val;
}

template <class T>
T LLStack<T>::peek() {
//    if (!empty()) {
//        throw std::out_of_range("underflow");
//    }
    return top->data;
}


// Helper for debugging - prints the stack
template <class T>
void LLStack<T>::printStack() {
  cout << "Printing stack from top to bottom..." << endl;

  node<T> *curr = top;
  while (curr) {
    // Depending on instance's data type, could throw exception here.
    cout << "val=" << " " << curr->data << endl;
    curr = curr->next;
  }
  cout << "Finished printing stack." << endl;
}

#endif
