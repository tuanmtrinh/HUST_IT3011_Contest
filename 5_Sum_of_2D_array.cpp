#include <iostream>

int main() {
  int m, n;
  std::cin >> m >> n;

  int arr[m][n];
  int sum = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> arr[i][j];
      sum += arr[i][j];
    }
  }

  std::cout << sum << std::endl;

  return 0;
}
