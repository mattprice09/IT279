
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

// LLQueue class headers
template <class T>
class LLQueue {  
public:
  LLQueue();

  node<T> *head;
  node<T> *tail;
  T length;

  void enqueue(T val);
  T dequeue();
  T peek();
};

// ~~ Class implementation below

// Default constructor
template <class T>
LLQueue<T>::LLQueue() {
  head = NULL;
  tail = NULL;
  length = 0;
}

// Add an item to the queue
template <class T>
void LLQueue<T>::enqueue(T val) {
  node<T> *n = new node<T>;
  n->data = val;
  n->next = NULL;
  if (! head) {
    // Queue is empty
    head = tail = n;
    length = 1;
  } else if (length == 1) {
    // Queue only has 1 element
    head->next = tail = n;
    length = 2;
  } else {
    tail->next = n;
    length += 1;
  }
}

// Remove/return the item at the front of the queue
template <class T>
T LLQueue<T>::dequeue() {
  if (! head) {
    // Queue is empty
    return 0;
  }
  T val = head->data;
  if (length == 1) {
    head = tail = NULL;
  } else {
    head = head->next;
  }

  length --;
  return val;
}

// View the item at the front of the queue
template <class T>
T LLQueue<T>::peek() {
  if (! head) {
    return 0;
  }
  return head->data;
}
