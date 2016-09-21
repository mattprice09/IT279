
#include "LLQueue.h"

LLQueue::LLQueue() {
  head = NULL;
  tail = NULL;
  length = 0;
}

void LLQueue::enqueue(int val) {
  node *n = new node;
  n->x = val;
  n->next = NULL;
  if (! head) {
    head = tail = n;
    length = 1;
  } else if (length == 1) {
    head->next = tail = n;
    length = 2;
  } else {
    tail->next = n;
    length += 1;
  }
}

int LLQueue::dequeue() {
  if (! head) {
    return 0;
  }
  int val = head->x;
  if (length == 1) {
    head = tail = NULL;
  } else {
    head = head->next;
  }

  length --;
  return val;
}
