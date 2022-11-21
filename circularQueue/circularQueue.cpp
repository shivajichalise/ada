#include <chrono>
#include <iostream>
using namespace std;

class CircularQueue {
private:
  int front;
  int rear;
  int arr[5];
  int itemCount;

public:
  CircularQueue() {
    itemCount = 0;
    front = -1;
    rear = -1;
    for (int i = 0; i < 5; i++) {
      arr[i] = 0;
    }
  }

  bool isEmpty() {
    if (front == -1 && rear == -1) {
      return true;
    }
    return false;
  }

  bool isFull() {
    if (((rear + 1) % 5) == front) {
      return true;
    }
    return false;
  }

  void enqueue(int item) {
    if (isFull()) {
      cout << "Queue is full" << endl;
      return;
    } else if (isEmpty()) {
      rear = 0;
      front = 0;
    } else {
      rear = (rear + 1) % 5;
    }
    arr[rear] = item;
    itemCount++;
  }

  int dequeue() {
    int temp;
    if (isEmpty()) {
      cout << "Queue is empty" << endl;
      return 0;
    } else if (front == rear) {
      temp = arr[front];
      arr[front] = 0;
      rear = -1;
      front = -1;
    } else {
      temp = arr[front];
      arr[front] = 0;
      front = (front + 1) % 5;
    }
    itemCount--;
    return temp;
  }

  int count() { return (itemCount); }

  void traverse() {
    int f = front, r = rear;
    if (f == -1) {
      printf("Queue is Empty");
      return;
    }
    printf("Queue is : ");
    if (f <= r) {
      while (f <= r) {
        printf("%d ", arr[f]);
        f = f + 1;
      }
    }
    f = 0;
    cout << endl;
  }
};

int main() {
  CircularQueue q1;
  auto start = std::chrono::high_resolution_clock::now();

  q1.enqueue(6);
  cout << "Enqueued!" << endl;

  auto finish = std::chrono::high_resolution_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish -
                                                                    start)
                   .count()
            << "ns\n";

  auto sstart = std::chrono::high_resolution_clock::now();

  q1.dequeue();
  cout << "Dequeued!" << endl;

  auto ffinish = std::chrono::high_resolution_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(ffinish -
                                                                    sstart)
                   .count()
            << "ns\n";

  /* auto ssstart = std::chrono::high_resolution_clock::now(); */

  /* q1.traverse(); */
  /* cout << "Traversed!" << endl; */

  /* auto fffinish = std::chrono::high_resolution_clock::now(); */
  /* std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(fffinish
   * - */
  /*                                                                   ssstart)
   */
  /*                  .count() */
  /*           << "ns\n"; */
  /* q1.enqueue(9); */
  /* q1.enqueue(6); */
  /* q1.enqueue(6); */
  /* q1.enqueue(6); */
  return 0;
}
