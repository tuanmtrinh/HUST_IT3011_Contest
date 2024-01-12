/*
Description
Perform a sequence of operations over a queue, each element is an integer:
PUSH v: push a value v into the queue
POP: remove an element out of the queue and print this element to stdout (print NULL if the queue is empty)

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
1
2
3 
*/

#include <iostream>
#include <queue>
#include <string>

struct Node {
    int value;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void pop() {
        if (front == nullptr) {
            std::cout << "NULL" << std::endl;
        } else {
            Node* temp = front;
            std::cout << temp->value << std::endl;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Queue q;
    std::string command;
    int value;

    while (std::cin >> command) {
        if (command == "PUSH") {
            std::cin >> value;
            q.push(value);
        } else if (command == "POP") {
            q.pop();
        } else if (command == "#") {
            break;
        }
    }

    return 0;
}
