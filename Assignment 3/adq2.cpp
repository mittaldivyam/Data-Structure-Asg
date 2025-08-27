#include <iostream>
#define MAX 100
using namespace std;

int stack[MAX];
int top = -1;
int minElement;

void push(int x) {
    if (top == MAX - 1) {
        cout << "Overflow\n";
        return;
    }
    if (top == -1) {
        stack[++top] = x;
        minElement = x;
    } 
    else if (x >= minElement) {
        stack[++top] = x;
    } 
    else {
        stack[++top] = 2 * x - minElement;
        minElement = x;
    }
}

void pop() {
    if (top == -1) {
        cout << "Underflow\n";
        return;
    }
    int t = stack[top--];
    if (t < minElement) {
        cout << "Popped: " << minElement << "\n";
        minElement = 2 * minElement - t;
    } 
    else {
        cout << "Popped: " << t << "\n";
    }
}

int getMin() {
    if (top == -1) {
        cout << "Stack empty\n";
        return -1;
    }
    return minElement;
}

int peek() {
    if (top == -1) return -1;
    int t = stack[top];
    if (t < minElement) return minElement;
    return t;
}

int main() {
    push(3);
    push(5);
    cout << "Min: " << getMin() << "\n";
    push(2);
    push(1);
    cout << "Min: " << getMin() << "\n";
    pop();
    cout << "Min: " << getMin() << "\n";
    pop();
    cout << "Top: " << peek() << "\n";
    cout << "Min: " << getMin() << "\n";
    return 0;
}
