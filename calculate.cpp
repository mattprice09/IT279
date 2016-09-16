#include <iostream>
#include <stack>

using namespace std;

struct node {
	int x;
	node *next;
};

int clear();
int undo();
int repeat();	
int quit();

int main ()
{

	
	node *root;
	node *current;
	int add;
	
	
	cout << "add an item to the linked list" << endl;
	cin >> add;
	if(add == 'c' || 'C') {clear();}
	else if(add == 'u' || 'U') {undo();}
	else if(add == 'r' || 'R') {repeat();}
	else if(add == 'q' || 'Q') {quit();}
	else {
	root = new node;
	root->next=0;
	root->x=add;
	}

	stack <int> calculate;
	calculate.push(root->x); 




	cout << calculate.size() << endl;
	calculate.pop();
	cout << calculate.size() << endl;


}

int clear() {
	return 0;
}
int undo() {
	return 0;
}
int repeat() {
	return 0;
}
int quit() {
	cout << "quit";
	return 0;
}
