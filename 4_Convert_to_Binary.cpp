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
