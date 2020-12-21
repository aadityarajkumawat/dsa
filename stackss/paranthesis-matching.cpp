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

int main() {
	Stack *stack = new Stack();
	
	stack->size = 80;
	stack->top = -1;
	stack->arr = new char[stack->size];
	
	string expression = "(34*12)+22";
	char arrayOfExpressionCharcters[expression.length()];
	for(int i  = 0; i < expression.length(); i++) {
		arrayOfExpressionCharcters[i] = expression[i];
	}

	return 0;
}
