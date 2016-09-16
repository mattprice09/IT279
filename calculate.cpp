#include <iostream>
#include <stack>

using namespace std;

struct node {
	int x;
	node *next;
};

int clear();
int undo();
int redo();
int calculate(int curr, int oper, int operand);
int parseNumber(std::string input);

int main ()
{

	stack <int> activeStack;
	stack <int> inactiveStack;

	// Set of operators, O(1) lookup time
	std::string operatorArr[] = {'+', '-', '*', '/', '%'};
	std::set<std::string> operators(operatorList, sizeof(operatorArr));

	std::string input;
	std::transform(input.begin(), input.end(), input.begin(), ::tolower);

	cout << "input an item to the linked list" << endl;
	cin >> input;
	node *current;

	// Accept user input until they quit
	while (input != 'q') {
		node *root;
		
		if (input == 'c') {
			clear();
		}
		else if (input == 'u') {
			undo();
		}
		else if (input == 'r') {
			redo();
		}
		else {
			std::string operatorStr = input.substr(0);

			// Validate operator, O(1)
			if (operators.find(operatorStr) == operators.end()) {
				cout << "Invalid operator. Please try again." << endl;
				cin >> input;
			}

			// Validate integer operand
			int intOperand = parseNumber(input.subtr(1))
			if (! intOperand) {
				cout << "Invalid input. Please try again." << endl;
				cin >> input;
			}

			int newValue = calculate(current->x, operatorStr, intOperand);

			// Push new node, assign current node's "next" to the new node. 
			root = new node;
			root->x = newValue;
			current->next = root;
			activeStack.push(root); 
			current = root;
		}

		cout << activeStack.size() << endl;

		cout << "input an item to the linked list" << endl;
		cin >> input;
	}
	cout << 'Goodbye!' << endl;
}

// This Function will set the current calucated value equal to zero
int clear() {
	return 0;
}
// This Function will set the current calucated value equal to the one before it
int undo() {
	return 0;
}
// This Function will disable the Undo and return the value before 
int redo() {
	return 0;
}

int calculate(int curr, int oper, int operand) {
	return 0;
}

bool parseNumber(std::string str) {
	try {
		int parsedOperand = atoi(str.c_str());
	} catch (...) {
		return;
	}
	return parsedOperand;
}