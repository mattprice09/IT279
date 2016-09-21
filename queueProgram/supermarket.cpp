#include <algorithm>

#include "LLQueue.h"

int parseNumber(string input);

int main() {
  string input;
  cout << "Welcome! Please enter your max X integer value: " << endl;
  cin >> input;

  // Get the 'X' input from the user
  int x = parseNumber(input);
  while (! x) {
    cout << "Invalid input. Please enter your max X integer value: " << endl;
    cin >> input;
    x = parseNumber(input);
  }

  int TIME = 0;
  int nextArrival = rand() % x + (TIME+1);
  int serviceCompletion;
  int custNum = 1;

  int longestWait = 0;
  int maxLength = 0;
  LLQueue<int> *line = new LLQueue<int>;

  // Skip ahead to the first arrival time
  TIME = nextArrival;
  serviceCompletion = TIME + (rand() % x + 1);

  while (TIME < 720) {

    // A customer is arriving at this minute
    if (TIME == nextArrival) {
      cout << "Customer " << custNum + line->length << " arrived at " << TIME << '.' << endl;
      line->enqueue(nextArrival);
      // Get time of next arrival event
      nextArrival = rand() % x + (TIME+1);

      // Keep track of longest line
      maxLength = max(maxLength, line->length);
    }

    // A customer is leaving at this minute
    if (TIME == serviceCompletion) {
      cout << "Customer " << custNum << " left at " << TIME << '.' << endl;
      custNum ++;
      // Get time of next service completion event
      int serviceTime = rand() % x + 1;
      serviceCompletion = TIME + serviceTime;

      // Keep track of longest wait
      int upNext = line->dequeue();
      if (upNext) {
        longestWait = max(longestWait, (TIME - upNext));
      }
    }
    
    // Go to the time of the next event (to avoid iterating through each minute unnecessarily)
    TIME = min(nextArrival, serviceCompletion);
  }

  cout << "Maximum queue length at one time: " << maxLength << endl;
  cout << "Maximum wait for a single customer: " << longestWait << endl;
}

// Parse out a number from text
int parseNumber(string str) {
  int parsedOperand;
  try {
    parsedOperand = atoi(str.c_str());
  } catch (...) {}
  return parsedOperand;
}
