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
