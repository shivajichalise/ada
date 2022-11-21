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
