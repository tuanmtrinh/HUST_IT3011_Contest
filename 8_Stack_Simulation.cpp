// P__Simulation Stack

#include <iostream>
#include <stack>
#include <string>

int main() {
    std::stack<int> stack;

    std::string command;
    while (std::cin >> command) {
        if (command == "PUSH") {
            int value;
            std::cin >> value;
            stack.push(value);
        } else if (command == "POP") {
            if (stack.empty()) {
                std::cout << "NULL" << std::endl;
            } else {
                int top = stack.top();
                stack.pop();
                std::cout << top << std::endl;
            }
        }
    }

    return 0;
}
