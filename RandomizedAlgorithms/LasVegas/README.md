### Lab 6
#### **OBJECTIVE:** TO IMPLEMENT LAS VEGAS RANDOMIZED ALGORITHM

**THEORY:** Las Vegas algorithm is a randomized algorithm that always gives correct results; that is, it always produces the correct result or it informs about the failure. However, the runtime of a Las Vegas algorithm differs depending on the input.

**SOURCE CODE:**
```cpp
#include <cstdlib>
#include <iostream>
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
```

**CONCLUSION:** We finally understood Las Vegas Alorithm and implemented it using C++ in lab.
