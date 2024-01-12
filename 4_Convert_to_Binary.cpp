/* 
Description
Viết chương trình chuyển đỏi một số n ở hệ cơ số 10 sang hệ cơ số 2.

Input:
Dòng 1: Chứa số n.

Output: 
- Trường hợp không hợp lệ  (n< 0) thì hiển thị giá trị: 0
- Số n biểu diễn ở cơ số 2 (các chữ số 1, 0 ở cơ số 2 liền nhau).

Ví dụ:

Input:
15

Output:
1111 
*/

#include <iostream>

int main() {
    int decimal, binary = 0, base = 1;
    std::cin >> decimal;
    while (decimal > 0) {
        int rem = decimal % 2;
        binary += rem * base;
        base *= 10;
        decimal /= 2;
    }
    std::cout << binary << std::endl;
    return 0;
}
