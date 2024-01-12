/* 

Description
Cho bốn số nguyên dương phân biệt sao cho tổng của mỗi hai số chia hết cho 2 và tổng của mỗi ba số chia hết cho 3. Tìm giá trị nhỏ nhất của tổng bốn số này?

Input:

Output:
Tổng_nhỏ_nhất
Số_1 Số_2 Số_3 Số_4 
*/

#include <iostream>
#include <vector>

bool isDivisibleByTwo(int num) {
    return num % 2 == 0;
}

bool isDivisibleByThree(int num) {
    return num % 3 == 0;
}

bool findSmallestSum(std::vector<int>& currentNumbers, int currentSum, int currentNumber) {
    if (currentNumbers.size() == 4) {
        if (isDivisibleByTwo(currentNumbers[0] + currentNumbers[1]) &&
            isDivisibleByTwo(currentNumbers[0] + currentNumbers[2]) &&
            isDivisibleByTwo(currentNumbers[0] + currentNumbers[3]) &&
            isDivisibleByTwo(currentNumbers[1] + currentNumbers[2]) &&
            isDivisibleByTwo(currentNumbers[1] + currentNumbers[3]) &&
            isDivisibleByTwo(currentNumbers[2] + currentNumbers[3]) &&
            isDivisibleByThree(currentNumbers[0] + currentNumbers[1] + currentNumbers[2]) &&
            isDivisibleByThree(currentNumbers[0] + currentNumbers[1] + currentNumbers[3]) &&
            isDivisibleByThree(currentNumbers[0] + currentNumbers[2] + currentNumbers[3]) &&
            isDivisibleByThree(currentNumbers[1] + currentNumbers[2] + currentNumbers[3])) {
            std::cout << currentSum << std::endl;
            for (int num : currentNumbers) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
            return true;
        }
        return false;
    }

    for (int num = currentNumber; num <= 100; num++) {
        currentNumbers.push_back(num);
        if (findSmallestSum(currentNumbers, currentSum + num, num + 1)) {
            return true;
        }
        currentNumbers.pop_back();
    }

    return false;
}

int main() {
    std::vector<int> currentNumbers;
    int currentSum = 0;
    int currentNumber = 1;
    findSmallestSum(currentNumbers, currentSum, currentNumber);

    return 0;
}
