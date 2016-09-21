#include <algorithm>
#include <set>

#include "LLStack.h"

int clear();
int undo();
int redo();
int calculate(int curr, string oper, int operand);
int parseNumber(string input);

int main () {

  int DEBUG = 0;

  LLStack *activeStack = new LLStack;
  LLStack *inactiveStack = new LLStack;

  // Set of operators, O(1) lookup time
  string arr[] = {"+", "-", "*", "/", "%"};
  std::set<string> operators(arr, arr + sizeof(arr) / sizeof(arr[0]));

  string input;
  cout << "> ";

  cin >> input;
  std::transform(input.begin(), input.end(), input.begin(), ::tolower);

  // Insert the root node (value of 0)
  node *current = new node;
  current->x = 0;
  current->next = NULL;
  activeStack->push(current);

  // Accept user input until they quit
  while (input != "q") {
    node *root;
    
    if (input == "c") {
      clear();
    }
    else if (input == "u") {
      undo();
    }
    else if (input == "r") {
      redo();
    }
    else {
      string operatorStr = input.substr(0,1);

      // Validate operator, O(1)
      if (operators.find(operatorStr) == operators.end()) {
        cout << "Invalid operator. Please try again." << endl;
        cin >> input;
      }

      // Validate integer operand
      int intOperand = parseNumber(input.substr(1));
      if (! intOperand) {
        cout << "Invalid input. Please try again." << endl;
        cin >> input;
      }

      if (DEBUG == 2) {
        cout << "Operator:" << endl;
        cout << operatorStr << endl;
        cout << "Operand" << endl;
        cout << intOperand << endl;
      }

      int newValue = calculate(current->x, operatorStr, intOperand);

      // Push new node, keep track of its value. 
      root = new node;
      root->x = newValue;
      root->next = current;
      current = root;
      activeStack->push(root); 
    }

    if (DEBUG == 1) {
      activeStack->printStack();
    }

    cout << current->x << endl;
    cout << "> ";
    cin >> input;
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
  }
  cout << "Goodbye!" << endl;
}

// @timfield
// This Function will set the current calucated value equal to zero
int clear() {
  return 0;
}

// @timfield
// This Function will set the current calucated value equal to the one before it
int undo() {
  return 0;
}

// @nickmessina
// This Function will disable the Undo and return the value before 
int redo() {
  return 0;
}

// Run basic arithmetic calculation
int calculate(int curr, string oper, int operand) {
  if (oper == "+") {
    return curr + operand;
  } else if (oper == "-") {
    return curr - operand;
  } else if (oper == "*") {
    return curr * operand;
  } else if (oper == "/") {
    return curr / operand;
  } else {
    return curr % operand;
  }
}

// Parse out a number from text
int parseNumber(string str) {
  int parsedOperand;
  try {
    parsedOperand = atoi(str.c_str());
  } catch (...) {}
  return parsedOperand;
}
