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
