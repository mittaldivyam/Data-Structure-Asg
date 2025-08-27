#include <iostream>
#define MAX 5
using namespace std;

int stack[MAX], top = -1;

void push(int x) {
    if (top == MAX - 1)
        cout << "Overflow\n";
    else
        stack[++top] = x;
}

void pop() {
    if (top == -1)
        cout << "Underflow\n";
    else
        cout << "Popped: " << stack[top--] << "\n";
}

void isEmpty() {
    if (top == -1)
        cout << "Empty\n";
    else
        cout << "Not Empty\n";
}

void isFull() {
    if (top == MAX - 1)
        cout << "Full\n";
    else
        cout << "Not Full\n";
}

void display() {
    if (top == -1)
        cout << "Empty\n";
    else {
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << "\n";
    }
}

void peek() {
    if (top == -1)
        cout << "Empty\n";
    else
        cout << "Top: " << stack[top] << "\n";
}

int main() {
    int ch, x;
    while (1) {
        cout << "1.Push 2.Pop 3.isEmpty 4.isFull 5.Display 6.Peek 7.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cin >> x; push(x); break;
            case 2: pop(); break;
            case 3: isEmpty(); break;
            case 4: isFull(); break;
            case 5: display(); break;
            case 6: peek(); break;
            case 7: return 0;
        }
    }
}
