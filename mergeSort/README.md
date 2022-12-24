### Lab 4
#### **OBJECTIVE:** TO IMPLEMENT MERGE SORT AND EXAMINE ITS TIME EXPENDITURE

**THEORY:** The Merge Sort algorithm is a sorting algorithm that is based on the Divide and Conquer paradigm. In this algorithm, the array is initially divided into two equal halves and then they are combined in a sorted manner. Think of it as a recursive algorithm continuously splits the array in half until it cannot be further divided.

**SOURCE CODE:**
```java
class MergeSort {
  void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[] = new int[n1];
    int R[] = new int[n2];

    for (int i = 0; i < n1; ++i)
      L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
      R[j] = arr[m + 1 + j];

    int i = 0, j = 0;

    int k = l;
    while (i < n1 && j < n2) {
      if (L[i] <= R[j]) {
        arr[k] = L[i];
        i++;
      } else {
        arr[k] = R[j];
        j++;
      }
      k++;
    }

    while (i < n1) {
      arr[k] = L[i];
      i++;
      k++;
    }

    while (j < n2) {
      arr[k] = R[j];
      j++;
      k++;
    }
  }

  void sort(int arr[], int l, int r) {
    if (l < r) {
      int m = (l + r) / 2;

      sort(arr, l, m);
      sort(arr, m + 1, r);

      merge(arr, l, m, r);
    }
  }

  static void printArray(int arr[]) {
    int n = arr.length;
    for (int i = 0; i < n; ++i)
      System.out.print(arr[i] + " ");
    System.out.println();
  }

  public static void main(String args[]) {
    int arr[] = { 12, 11, 13, 5, 6, 7 };

    System.out.println("Given Array");
    printArray(arr);

    System.out.print("Time in nanosecond: ");
    System.out.println(System.nanoTime());

    MergeSort ob = new MergeSort();
    ob.sort(arr, 0, arr.length - 1);

    System.out.print("Time in nanosecond: ");
    System.out.println(System.nanoTime());

    System.out.println("\nSorted array");
    printArray(arr);
  }
}
```

**OUTPUT:** 
```bash
Given Array
12 11 13 5 6 7

Time in nanosecond: 5441556165655
Time in nanosecond: 5441556294344

Sorted array
5 6 7 11 12 13

```

**OBSERVATION:** From output we can observe that time spent to sort an array was 5441556165655 - 5441556294344 = 128689 nanosecond.
