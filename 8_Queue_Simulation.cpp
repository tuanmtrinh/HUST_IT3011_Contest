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

int main() {
    std::queue<int> q;
    std::string command;
    int value;

    while (std::cin >> command) {
        if (command == "PUSH") {
            std::cin >> value;
            q.push(value);
        } else if (command == "POP") {
            if (!q.empty()) {
                std::cout << q.front() << std::endl;
                q.pop();
            } else {
                std::cout << "NULL" << std::endl;
            }
        } else if (command == "#") {
            break;
        }
    }

    return 0;
}
