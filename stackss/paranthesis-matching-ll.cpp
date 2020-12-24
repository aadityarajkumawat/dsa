#include <iostream>
#include <string>
using namespace std;

class Node {
	public:
		char data;
		Node* next;
};

int isFull(Node* top) {
	Node* newNode = new Node();
	if(newNode == NULL) {
		return 1;
	}
	return 0;
}

int isEmpty(Node* top) {
	if(top == NULL) {
		return 1;
	}
	return 0;
}

Node* push(Node* top, char data) {
	if(isFull(top)) {
		return top;
	}
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = top;
	top = newNode;
	return top;
}

char pop(Node* top) {

}

char peek(Node** top, int index) {
	
}

int main() {
	Node* top = NULL;
	string expression = "(8+5)*6+2";
	char charcterArray[expression.length()];

	for(int i = 0; i < expression.length(); i++) {
		charcterArray[i] = expression[i];
		top = push(top, charcterArray[i]);
		cout << charcterArray[i];
	}
	cout << endl;

	return 0;
}
