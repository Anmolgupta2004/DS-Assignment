#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib> // For rand()
#include <ctime> // For time()
using namespace std;
using namespace std::chrono;
// Bubble Sort
void bubbleSort(vector<int>& arr) {
 int n = arr.size();
 for (int i = 0; i < n - 1; i++)
 for (int j = 0; j < n - i - 1; j++)
 if (arr[j] > arr[j + 1])
 swap(arr[j], arr[j + 1]);
}
// Insertion Sort
void insertionSort(vector<int>& arr) {
 int n = arr.size();
 for (int i = 1; i < n; i++) {
 int key = arr[i];
 int j = i - 1;
 while (j >= 0 && arr[j] > key) {
 arr[j + 1] = arr[j];
 j--;
 }
 arr[j + 1] = key;
 }
}
// Generate random array
vector<int> generateRandomArray(int size) {
 vector<int> arr(size);
 for (int i = 0; i < size; i++)
 arr[i] = rand() % 10000; // Random values up to 100000
 return arr;
}
// Measure and print execution time
void testSorts(int size) {
 cout << "\n--- Testing with " << size << " elements ---\n";
 vector<int> arr1 = generateRandomArray(size);
 vector<int> arr2 = arr1; // Copy for fair comparison
 auto start = high_resolution_clock::now();
 insertionSort(arr1);
 auto stop = high_resolution_clock::now();
 auto duration = duration_cast<milliseconds>(stop - start);
 cout << "Insertion Sort Time: " << duration.count() << " ms\n";
 start = high_resolution_clock::now();
 bubbleSort(arr2);
 stop = high_resolution_clock::now();
 duration = duration_cast<milliseconds>(stop - start);
 cout << "Bubble Sort Time: " << duration.count() << " ms\n";
}
int main() {
 srand(time(0)); // Seed random generator
 testSorts(10);
 testSorts(100);
 testSorts(500);
 testSorts(1000);
 testSorts(1500);
 testSorts(10000); 
 return 0;
}
