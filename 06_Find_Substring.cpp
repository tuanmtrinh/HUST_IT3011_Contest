/* 
Description
Viết chương trình tìm kiếm chuỗi con trong 1 chuỗi. Yêu cầu là tìm kiếm đếm một chuỗi con xem chuỗi con đó xuất hiện  bao nhiêu lần trong một chuỗi.

Input:
Dòng 1: Chứa chuỗi con cần đếm.
Dòng 2: Chứa chuỗi lớn.

Ouput:
Số lần xuất hiện.
Ví dụ:

Input
te
dai hoc kinh te quoc dan

Output
1
*/

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
