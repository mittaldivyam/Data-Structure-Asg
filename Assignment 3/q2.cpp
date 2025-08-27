#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) return;
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

int main() {
    char str[MAX];
    cout << "Enter a string: ";
    cin >> str;

    int n = strlen(str);
    for (int i = 0; i < n; i++)
        push(str[i]);

    cout << "Reversed: ";
    for (int i = 0; i < n; i++)
        cout << pop();

    cout << "\n";
    return 0;
}
