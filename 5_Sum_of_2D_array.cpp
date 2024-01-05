/* 
Description
Viết chương trình tính tổng giá trị của một mảng 2 chiều m hàng, n cột.

Input:
Dòng 1: chứa số hàng, cột của mảng m,n
Dòng 2: Chứa từng phần tử ở hàng 1 của mảng (từ cột 1 đến cột n)
Dòng 3: Chứa từng phần tử ở hàng 2 của mảng (từ cột 1 đến cột n)
..........................................................................................................................................
Dòng m+1: Chứa từng phần tử ở hàng m của mảng (từ cột 1 đến cột n)

Ouput:
Tổng giá trị các phần tử của mảng.

Ví dụ:

Input1
2 3
1 2 3
4 5 6

Output1
21

Input2
3 2
10 20
-1 -1
30 40

Output2
98 
*/

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
