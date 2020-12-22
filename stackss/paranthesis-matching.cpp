#include <iostream>
#include <string>
using namespace std;
/**
 * Condition for a balanced expression
 * 1) While popping stack should not underflow
 * 2) At end of expression(\0) the stack must be empty 
*/

class Stack {
	public:
		int size;
		int top;
		char* arr;
};

int isEmpty(Stack* stack) {
	if(stack->top == -1) {
		return 1;
	}
	return 0;
}

int isFull(Stack* stack) {
	if(stack->top == stack->size - 1) {
		return 1;
	}
	return 0;
}

void push(Stack* stack, char data) {
	if(isFull(stack)) {
		cout << "Stack Overflow" << endl;
	}
	else {
		(stack->top)++;
		stack->arr[stack->top] = data;
	}
}

char pop(Stack* stack) {
	if(isEmpty(stack)) {
		cout << "Stack Underflow" << endl;
		return 'A';
	}
	else {
		char poppedChar = stack->arr[stack->top];
		(stack->top)--;
		return poppedChar;
	}
}

int main() {
	Stack *stack = new Stack();
	
	stack->size = 80;
	stack->top = -1;
	stack->arr = new char[stack->size];
	
	string expression = "(34)*12+22";
	char arrayOfExpressionCharcters[expression.length()];
	for(int i  = 0; i < expression.length(); i++) {
		arrayOfExpressionCharcters[i] = expression[i];
		if(expression[i] == '(') {
			push(stack, expression[i]);
		}
		else if(expression[i] == ')') {
			pop(stack);
		}
		else if(expression.length()-1 ==  i) {
			if(stack->top == -1) {
				cout << "Paranthesis Matched" << endl;
			}
			else {
				cout << "Paranthesis not matched" << endl;
			}
		}
	}
	return 0;
}
