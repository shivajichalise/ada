### Lab 5
#### **OBJECTIVE:** TO IMPLEMENT HEAP SORT AND EXAMINE ITS TIME EXPENDITURE

**THEORY:** Heap sort is a comparison-based sorting technique based on Binary Heap data structure. It is similar to the selection sort where we first find the minimum element and place the minimum element at the beginning. Repeat the same process for the remaining elements.

**SOURCE CODE:**
```cpp
#include <chrono>
#include <ctime>
#include <iostream>
using namespace std;

// WORKS WITH NEWER COMPILERS. TRY cpp.sh in web

void heapify(int arr[], int n, int i) {
  int largest = i;   // Initialize largest as root
  int l = 2 * i + 1; // left = 2*i + 1
  int r = 2 * i + 2; // right = 2*i + 2

  // If left child is larger than root
  if (l < n && arr[l] > arr[largest])
    largest = l;

  // If right child is larger than largest so far
  if (r < n && arr[r] > arr[largest])
    largest = r;

  // If largest is not root
  if (largest != i) {
    swap(arr[i], arr[largest]);

    // Recursively heapify the affected sub-tree
    heapify(arr, n, largest);
  }
}

// main function to do heap sort
void heapSort(int arr[], int n) {
  // Build heap (rearrange array)
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  // One by one extract an element from heap
  for (int i = n - 1; i >= 0; i--) {
    // Move current root to end
    swap(arr[0], arr[i]);

    // call max heapify on the reduced heap
    heapify(arr, i, 0);
  }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n) {
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
  cout << "\n";
}

int main() {
  int arr[] = {12, 11, 13, 5, 6, 7};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Unsorted array is \n";
  printArray(arr, n);

  auto start = chrono::high_resolution_clock::now();

  heapSort(arr, n);

  auto finish = chrono::high_resolution_clock::now();
  cout << chrono::duration_cast<chrono::nanoseconds>(finish - start).count()
       << "ns\n";

  cout << "Sorted array is \n";
  printArray(arr, n);
}
```

**OUTPUT:** 
```bash
Unsorted array is
12 11 13 5 6 7
1380ns
Sorted array is
5 6 7 11 12 13
```

**OBSERVATION:** From output we can observe that time spent to sort an array was 1380 nanosecond.
