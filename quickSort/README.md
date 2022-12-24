### Lab 2
#### **OBJECTIVE:** TO IMPLEMENT QUICK SORT AND EXAMINE ITS TIME EXPENDITURE

**THEORY:** QuickSort is a Divide and Conquer algorithm. It picks an element as a pivot and partitions the given array around the picked pivot. There are many different versions of quickSort that pick pivot in different ways.

**SOURCE CODE:**
```cpp
#include <chrono>
#include <iostream>
using namespace std;
#define MAX 10

int partition(int arr[], int s, int e) {
  int pivot = arr[e];
  int pindex = s;
  for (int i = s; i < e; i++) {
    if (arr[i] <= pivot) {
      int temp = arr[i];
      arr[i] = arr[pindex];
      arr[pindex] = temp;
      pindex++;
    }
  }
  int temp = arr[e];
  arr[e] = arr[pindex];
  arr[pindex] = temp;

  return pindex;
}

void QuickSort(int arr[], int s, int e) {
  if (s < e) {
    int p = partition(arr, s, e);
    QuickSort(arr, s, p - 1);
    QuickSort(arr, p + 1, e);
  }
}

int main() {
  int arr[MAX] = {32, 342, 231, 43, 231, 65, 32, 65, 32, 5};

  cout << "Before Sorting: " << endl;
  for (int i = 0; i < MAX; i++) {
    cout << arr[i] << " ";
  }

  cout << endl;
  auto start = chrono::high_resolution_clock::now();
  QuickSort(arr, MAX - MAX, MAX - 1);
  auto finish = chrono::high_resolution_clock::now();
  cout << chrono::duration_cast<chrono::nanoseconds>(finish - start).count()
       << "ns\n";

  cout << "After Sorting: " << endl;
  for (int i = 0; i < MAX; i++) {
    cout << arr[i] << " ";
  }

  cout << endl;
  return 0;
}
```

**OUTPUT:** 
```bash
Before Sorting:
32 342 231 43 231 65 32 65 32 5
1285ns
After Sorting:
5 32 32 32 43 65 65 231 231 342
```

**OBSERVATION:** From output we can observe that time spent to sort an array was 1285 nanosecond i.e. 0.000001285 second
