/*
Description
Perform a sequence of operations over a stack, each element is an integer:
PUSH v: push a value v into the stack
POP: remove an element out of the stack and print this element to stdout (print NULL if the stack is empty)

Input
Each line contains a command (operration) of type 
PUSH  v
POP

Output
Write the results of POP operations (each result is written in a line)

Example

Input
PUSH 1
PUSH 2
PUSH 3
POP
POP
PUSH 4
PUSH 5
POP
#

Output
3
2
5 
*/

#include <iostream>
#include <string>

struct Node {
    int value;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int value) {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            return NULL;
        } else {
            int poppedValue = top->value;
            Node* temp = top;
            top = top->next;
            delete temp;
            return poppedValue;
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack stack;

    std::string command;
    while (std::cin >> command) {
        if (command == "PUSH") {
            int value;
            std::cin >> value;
            stack.push(value);
        } else if (command == "POP") {
            int poppedValue = stack.pop();
            if (poppedValue == NULL) {
                std::cout << "NULL" << std::endl;
            } else {
                std::cout << poppedValue << std::endl;
            }
        }
    }

    return 0;
}
