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
	if (newNode == NULL) {
		return 1;
	}
	return 0;
}

int isEmpty(Node* top) {
	if (top == NULL) {
		return 1;
	}
	return 0;
}

Node* push(Node* top, char data) {
	if (isFull(top)) {
		return top;
	}
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = top;
	top = newNode;
	return top;
}

char pop(Node** top) {
	if (isEmpty(*top)) {
		return 'A';
	}
	Node* temp = *top;
	char poppedCharcter = (*top)->data;
	*top = (*top)->next;
	return poppedCharcter;
}

int main() {
	Node* top = NULL;
	string expression = "(8+5)*6+2";

	for (int i = 0;i < expression.length(); i++) {
		if (expression[i] == '(') {
			top = push(top, expression[i]);
		}
		else if (expression[i] == ')') {
			pop(&top);
		}
		else if (expression.length() - 1 == i) {
			if (top == NULL) {
				cout << expression << endl;
				cout << "Paranthesis matched" << endl;
			}
			else {
				cout << expression << endl;
				cout << "Paranthesis not matched" << endl;
			}
		}
	}

	return 0;
}
