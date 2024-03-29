/* 
Description
Đếm tần suất xuất hiện của kí tự trong bảng chữ cái Alphabet trong xâu ký tự cho trước (Các ký tự đều là chũ in hoa).

Input: Xâu tối đa 255 kí tự bao gồm cả khoảng trắng

Output: Tần xuất xuất hiện của các kí tự có lần xuất hiện > 0.

Ví dụ:

Input: DAI HOC BACH KHOA

Output: A 3
              B 1
              C 2
              D 1
              H 3
              I  1
              K 1
              O 2 
*/

#include <iostream>
#include <string>
#include <map>
#include <cctype>

std::map<char, int> countCharsRecursively(const std::string& input, int index, std::map<char, int>& charCounts) {
    if (index == input.size()) {
        return charCounts;
    }
    
    char c = input[index];
    if (c != ' ') {
        charCounts[std::toupper(c)]++;
    }
    
    return countCharsRecursively(input, index + 1, charCounts);
}

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::map<char, int> charCounts;
    charCounts = countCharsRecursively(input, 0, charCounts);

    for (const auto& pair : charCounts) {
        std::cout << pair.first << ":" << pair.second << " ";
    }
    std::cout << std::endl;

    return 0;
}