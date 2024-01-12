/*
Description
Viết chương trình nhập vào 1 dãy số nguyên dương a1 , a2 , …, an , sắp xếp dãy đã cho theo thứ tự không giảm bằng thuật toán sắp xếp lựa chọn

Dữ liệu (stdin) 
Dòng 1: ghi số nguyên dương n (1 ≤ n ≤ 10^6 ) 
Dòng 2: ghi a1 , a2 , …, an , (1 ≤ ai ≤ 10^6 ) 

Kết quả (stdout) 
Ghi dãy đã được sắp xếp theo thứ tự không giảm, các phần tử cách nhau bởi 1 dấu cách
*/

#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr, int start) {
    if (start >= arr.size() - 1) {
        return;
    }
    
    int min_index = start;
    for (int i = start + 1; i < arr.size(); i++) {
        if (arr[i] < arr[min_index]) {
            min_index = i;
        }
    }
    swap(arr[start], arr[min_index]);
    
    selectionSort(arr, start + 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selectionSort(arr, 0);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}