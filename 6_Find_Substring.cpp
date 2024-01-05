// P__IT3011_C1B10: Tìm kiếm chuỗi con trong một chuỗi

#include <iostream>
#include <string>

int countOccurrences(const std::string& input, const std::string& search) {
    int count = 0;
    size_t pos = 0;
    
    while ((pos = input.find(search, pos)) != std::string::npos) {
        count++;
        pos += search.length();
    }
    
    return count;
}

int main() {
    std::string input;
    std::string search;
    std::getline(std::cin, search);
    std::getline(std::cin, input);
    
    int occurrences = countOccurrences(input, search);
    
    std::cout << occurrences << std::endl;
    
    return 0;
}
