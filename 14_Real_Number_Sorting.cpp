/*
Description
Viết chương trình nhập vào 1 số n, sau đó nhập vào 1 dãy n số thực, các giá trị số được ngăn cách bởi khoảng trắng.
Sau đó sắp xếp và in ra các số theo thứ tự giảm dần, mỗi giá trị 1 dòng,
các gía trị được làm tròn tới 2 chữ số phần thập phân.

Ví dụ:

Đầu vào:
3
2.3 1.17 3.90

Đầu ra:
3.90
2.30
1.17
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), greater<double>());

    cout << fixed << setprecision(2);
    for (double num : arr) {
        cout << num << "\n";
    }

    return 0;
}
