### Lab 1
#### **OBJECTIVE:** TO IMPLEMENT STACK AND EXAMINE PUSH & POP TIME EXPENDITURE

**THEORY:** Stack is a linear data structure that follows a particular order in which the operations are performed. The order may be LIFO(Last In First Out) or FILO(First In Last Out).

**SOURCE CODE:**
```java
class Stack {
  static final int MAX = 6;
  int top;
  int[] stack = new int[MAX];

  public static void printTime() {
    System.out.print("Time in nanoseconds = ");
    System.out.println(System.nanoTime());
  }

  Stack() {
    top = -1;
  }

  boolean isEmpty() {
    if (top == -1) {
      return true;
    }
    return false;
  }

  boolean isFull() {
    if (top == 5) {
      return true;
    }
    return false;
  }

  boolean push(int item) {
    if (isFull()) {
      System.out.println("Stack Overflow");
      return false;
    }
    stack[++top] = item;
    return true;
  }

  boolean pop() {
    if (isEmpty()) {
      System.out.println("Stack Underflow");
      return false;
    }
    stack[top] = 0;
    top--;
    return true;
  }

  int topValue() {
    return stack[top];
  }

  public static void main(String[] args) {
    Stack s = new Stack();
    printTime();

    s.push(10);
    System.out.println("Element pushed");

    printTime();

    s.pop();
    System.out.println("Element popped");

    printTime();
  }
}
```

**OUTPUT:** 
```bash
Time in nanoseconds = 4178633231041
Element pushed
Time in nanoseconds = 4178633489538
Element popped
Time in nanoseconds = 4178633690865
```

**OBSERVATION:** From output we can observe that time spent to push an element in the Stack was 4178633231041 - 4178633489538 = 258497 nanosecond i.e. 0.0002585 second
