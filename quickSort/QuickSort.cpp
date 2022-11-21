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

  auto start = std::chrono::high_resolution_clock::now();
  QuickSort(arr, MAX - MAX, MAX - 1);
  auto finish = std::chrono::high_resolution_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish -
                                                                    start)
                   .count()
            << "ns\n";

  for (int i = 0; i < MAX; i++) {
    cout << arr[i] << " ";
  }

  cout << endl;
  return 0;
}
