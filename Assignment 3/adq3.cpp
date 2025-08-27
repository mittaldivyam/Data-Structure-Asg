#include <iostream>
#define MAX 100
using namespace std;

int stack[MAX];
int top = -1;

void push(int x) {
    if (top < MAX - 1) stack[++top] = x;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int peek() {
    if (top == -1) return -1;
    return stack[top];
}

bool isEmpty() {
    return (top == -1);
}

void nextGreater(int arr[], int n) {
    int result[n];
    for (int i = n - 1; i >= 0; i--) {
        while (!isEmpty() && peek() <= arr[i])
            pop();
        if (isEmpty())
            result[i] = -1;
        else
            result[i] = peek();
        push(arr[i]);
    }
    cout << "Next Greater Elements: ";
    for (int i = 0; i < n; i++)
        cout << result[i] << " ";
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    nextGreater(arr, n);
    return 0;
}
