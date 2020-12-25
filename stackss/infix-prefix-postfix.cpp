#include <iostream>
#include <string>
using namespace std;

/**
 * Notations to write an expression
 * Infix- operand <operator> operand
 *
 * Prefix- <operator> operand_one operand_two
 *
 * Postfix- operand_one operand_two <operator>
 *
 * Infix   Prefix   Postfix
 *  a+b     +ab       ab+
*/

// Expression: x-y/z-k*d (infix)

class Stack {
public:
	int size;
	int top;
	char* arr;
};

int isEmpty(Stack* stack) {
	if (stack->top == -1) {
		return 1;
	}
	return 0;
}

int isFull(Stack* stack) {
	if (stack->top == stack->size - 1) {
		return 1;
	}
	return 0;
}

void push(Stack* stack, char data) {
	if (isFull(stack)) {
		cout << "Stack Overflow" << endl;
	}
	else {
		(stack->top)++;
		stack->arr[stack->top] = data;
	}
}

char pop(Stack* stack) {
	if (isEmpty(stack)) {
		cout << "Stack Underflow" << endl;
		// asumming 'A' won't be there in expression
		return 'A';
	}
	else {
		char poppedChar = stack->arr[stack->top];
		(stack->top)--;
		return poppedChar;
	}
}

int stackTop(Stack* stack) {
	return stack->arr[stack->top];
}

// string* infixToPostfix(string* infix) {
// 	Stack* sp;
// 	sp->size = 100;
// 	sp->top = -1;
// 	sp->arr = new char[sp->size];

// 	char* postfix = new char[(*infix).length() + 1];
// 	int i = 0;
// 	int j = 0;

// 	while((*infix).length() - 1 != i) {

// 	}
// }

int main() {
	string expression = "a-b+t/6";
	string* infix = &expression;
	return 0;
}
