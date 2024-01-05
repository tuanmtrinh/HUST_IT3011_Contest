#include <iostream>
#include <string>
#include <map>
#include <cctype>

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::map<char, int> charCounts;
    for (char c : input) {
        if (c != ' ') {
            charCounts[std::toupper(c)]++;
        }
    }

    for (const auto& pair : charCounts) {
        std::cout << pair.first << ":" << pair.second << " ";
    }
    std::cout << std::endl;

    return 0;
}
