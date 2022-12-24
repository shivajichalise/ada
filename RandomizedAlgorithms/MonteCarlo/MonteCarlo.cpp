#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

bool monte_carlo(int arr[], int n, int a, int x) {
  srand(time(0));
  int i = 0;
  bool tag = false;

  while (i <= x) {
    int b = rand() % 5;
    b = arr[b];
    i += 1;
    if (b == a) {
      tag = true;
    }
  }

  return tag;
}

int main() {
  int arr[5] = {0, 5, 3, 6, 2};
  if (monte_carlo(arr, sizeof(arr) / sizeof(arr[0]), 5, 9)) {
    cout << "Yes" << endl;
    return 0;
  }

  cout << "No" << endl;
}
