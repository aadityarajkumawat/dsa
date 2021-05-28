/**
 * |       |
 * |   5   |  -> Top
 * |   9   |
 * |   2   |
 * |   4   |
 * |_______|
 *
 */

function Stack() {
    let stackArray = [];
    const publicAPI = {
        top() {
            if (this.isEmpty()) {
                console.log("Stack is empty");
                return;
            }
            return stackArray[stackArray.length - 1];
        },
        push(value) {
            stackArray.push(value);
        },
        pop() {
            if (this.isEmpty()) {
                console.log("Stack is empty");
                return;
            }
            const poppedElement = stackArray.pop();
            return poppedElement;
        },
        isEmpty() {
            return stackArray.length === 0;
        },
    };
    return publicAPI;
}

// class Stack {
//     constructor() {
//         this.stackArray = [];
//     }
//     top() {
//         if (this.isEmpty()) {
//             console.log("Stack is empty");
//             return;
//         }
//         return this.stackArray[this.stackArray.length - 1];
//     }
//     push(value) {
//         this.stackArray.push(value);
//     }
//     pop() {
//         if (this.isEmpty()) {
//             console.log("Stack is empty");
//             return;
//         }
//         const poppedElement = this.stackArray.pop();
//         return poppedElement;
//     }
//     isEmpty() {
//         return this.stackArray.length === 0;
//     }
// }

const stack = new Stack();

console.log(stack.isEmpty());

stack.push(3);
stack.push(4);
stack.push(5);

stack.pop();

console.log(stack.top());
console.log(stack.isEmpty());
