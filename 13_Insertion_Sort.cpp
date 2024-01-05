/*
Description
Viết chương trình nhập vào 1 dãy số nguyên dương a1 , a2 , …, an , sắp xếp dãy đã cho theo thứ tự không giảm bằng thuật toán sắp xếp chèn

Dữ liệu (stdin) 
Dòng 1: ghi số nguyên dương n (1 ≤ n ≤ 10^6 ) 
Dòng 2: ghi a1 , a2 , …, an , (1 ≤ ai ≤ 10^6 ) 

Kết quả (stdout) 
Ghi dãy đã được sắp xếp theo thứ tự không giảm, các phần tử cách nhau bởi 1 dấu cách
*/

#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    insertionSort(arr);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}