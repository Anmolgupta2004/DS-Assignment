#include <iostream>
#include <vector>
#include <algorithm> // for sort
#include <chrono> // for timing
using namespace std;
using namespace std::chrono;
// Binary Search function
bool binarySearch( const vector<int>& arr, int target) {
 int left = 0, right = arr.size() - 1;
 while (left <= right) {
 int mid = left + (right - left) / 2;
 if (arr[mid] == target)
 return true;
 else if (arr[mid] < target)
 left = mid + 1;
 else
 right = mid - 1;
 }
 return false;
}
bool linearSearch(const vector<int>& arr, int target) {
 for (int x : arr)
 if (x == target)
 return true;
 return false;
}
//For avarage time camparision of linear and binary search--->
void compareSearches(int n, int trials = 1000) {
 vector<int> data(n);
 for (int i = 0; i < n; ++i)
 data[i] = i;
 int target = n - 1;
 long long binaryTotal = 0, linearTotal = 0;
 for (int i = 0; i < trials; ++i) {
 auto start1 = high_resolution_clock::now();
 binarySearch(data, target);
 auto stop1 = high_resolution_clock::now();
 binaryTotal += duration_cast<nanoseconds>(stop1 - start1).count();
 auto start2 = high_resolution_clock::now();
 linearSearch(data, target);
 auto stop2 = high_resolution_clock::now();
 linearTotal += duration_cast<nanoseconds>(stop2 - start2).count();
 }
 cout<<"for "<<n<<"->";
 cout << "Binary Search avg: " << binaryTotal / trials << " ns" << endl;
 cout << "Linear Search avg: " << linearTotal / trials << " ns" << endl;
}
int main() {
compareSearches (1) ;
compareSearches (99);
compareSearches (100);
compareSearches (999);
compareSearches (1000);
compareSearches (99999);
compareSearches (100000);
compareSearches (1000000);
compareSearches (10000000);
 return 0;
}
