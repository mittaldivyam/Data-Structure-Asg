#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100
using namespace std;

int stack[MAX];
int top = -1;

void push(int x) { if (top < MAX - 1) stack[++top] = x; }
int pop() { return (top == -1) ? -1 : stack[top--]; }
int peek() { return (top == -1) ? -1 : stack[top]; }
bool isEmpty() { return (top == -1); }

bool canBeSorted(vector<int>& A) {
    vector<int> sortedA = A;
    sort(sortedA.begin(), sortedA.end());
    int n = A.size(), idx = 0, nextExpected = 0;
    top = -1;

    for (int i = 0; i < n; i++) {
        push(A[i]);
        while (!isEmpty() && peek() == sortedA[nextExpected]) {
            pop();
            nextExpected++;
        }
    }
    return nextExpected == n;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> A(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> A[i];

    if (canBeSorted(A))
        cout << "Yes, possible\n";
    else
        cout << "No, not possible\n";

    return 0;
}
