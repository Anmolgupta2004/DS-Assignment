#include<bits/stdc++.h>
using namespace std;
int binary_search(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            return mid; 
        } else if (arr[mid] < x) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    return -1; 
}
int main(){
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter sorted array elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Enter element to search: ";
    cin >> x;
    int result = binary_search(arr, n, x);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}


// Enter number of elements: 6
// Enter sorted array elements: 1
// 3
// 4
// 6
// 7
// 8
// Enter element to search: 6
// Element found at index: 3
