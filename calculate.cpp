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
	
	//Takes Input From the User
	cout << "add an item to the linked list" << endl;
	cin >> add;
	//Check  Input From the User to See if it is a recognized by the program 
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
// This Function will set the current calucated value equal to zero
int clear() {
	return 0;
}
// This Function will set the current calucated value equal to the one before it
int undo() {
	return 0;
}
// This Function will disable the Undo and return the value before 
int repeat() {
	return 0;
}
// This Function will quit the program and return "Goodbye"
int quit() {
	cout << "quit";
	return 0;
}
