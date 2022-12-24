#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

bool las_vegas(int arr[], int n, int a) {
  int i = 0;

  bool tag = false;

  while (true) {
    int b = rand() % n;
    b = arr[b];
    i += 1;

    if (b == a) {
      tag = true;
      break;
    }
  }
  return tag;
}

int main() {
  int arr[5] = {0, 5, 3, 6, 2};
  if (las_vegas(arr, sizeof(arr) / sizeof(arr[0]), 5)) {
    cout << "Yes" << endl;
    return 0;
  }

  cout << "No" << endl;
}
