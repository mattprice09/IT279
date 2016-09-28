#include <algorithm>
#include <set>

#include <cstdlib>
#include <string>
#include <stack>
#include <iostream>

#include "LLStack.h"
using namespace std;


int clear();
int undo();
int redo();
int calculate(int curr, string oper, int operand);
int parseNumber(string input);

int main() {

  int DEBUG = 0;

	LLStack<int> *activeStack = new LLStack<int>;
	LLStack<int> *inactiveStack = new LLStack<int>;

  // Set of operators, O(1) lookup time
  string arr[] = {"+", "-", "*", "/", "%"};
  std::set<string> operators(arr, arr + sizeof(arr) / sizeof(arr[0]));

  string input;
  cout << "> ";

  cin >> input;

  std::transform(input.begin(), input.end(), input.begin(), ::tolower);

  // Insert the root node (value of 0)
  int current = 0;
  activeStack->push(current);

  // Accept user input until they quit
  while (input != "q") {
    node<int> *root;

    if (input == "c") {

		inactiveStack->push(current);
		current = 0;
		activeStack->push(current);

		clear();


    }
    else if (input == "u") {
    	current  = inactiveStack->pop();
    	//I need the peek to work before i finish this -Tim

//    	undo();
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

      current = calculate(current, operatorStr, intOperand);

      // Push new node, keep track of its value. 
      activeStack->push(current); 
      
      // Clear out inactive stack
      while (*inactiveStack) {
        curr = (*inactiveStack)->next;
        delete *inactiveStack;
        *inactiveStack = curr;
      }
    }

    if (DEBUG == 1) {
      activeStack->printStack();
    }

    cout << current << endl;

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
//I need the peek to work before i finish this -Tim
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
