/* 
Description
Given two integer n and M. Write a program that generates all ordered collection (X1, X2, ..., Xn) such that: X1 + X2 + . . . + Xn = M

Input
Line 1: contains 2 integers n and M (2 <= n <= 10, 1 <= M <= 20)

Output
Write in each line X1, X2, ..., Xn separated by a SPACE character

Example

Input
3  5

Output
1 1 3
1 2 2
1 3 1
2 1 2
2 2 1
3 1 1 
*/

#include <iostream>
#include <vector>

void distributeCandies(int n, int m, std::vector<int>& currentDistribution, int remainingCandies, int currentChild) {
    if (currentChild == n) {
        if (remainingCandies == 0) {
            for (int i = 0; i < n; i++) {
                std::cout << currentDistribution[i];
                if (i < n - 1) {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }
        return;
    }

    for (int i = 1; i <= remainingCandies; i++) {
        currentDistribution[currentChild] = i;
        distributeCandies(n, m, currentDistribution, remainingCandies - i, currentChild + 1);
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;

    if (m < n) {
        std::cerr << "Invalid input. The number of candies must be greater than or equal to the number of children." << std::endl;
        return 1;
    }

    std::vector<int> currentDistribution(n);
    distributeCandies(n, m, currentDistribution, m, 0);

    return 0;
}
