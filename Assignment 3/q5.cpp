#include <iostream>
#include <cstring>
#include <cctype>
#define MAX 100
using namespace std;

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) return;
    stack[++top] = x;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int evaluatePostfix(char exp[]) {
    for (int i = 0; i < strlen(exp); i++) {
        char c = exp[i];
        if (isdigit(c)) {
            push(c - '0');   // convert char digit to int
        }
        else {
            int val2 = pop();
            int val1 = pop();
            switch (c) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return pop();
}

int main() {
    char exp[MAX];
    cout << "Enter postfix expression: ";
    cin >> exp;
    cout << "Result: " << evaluatePostfix(exp) << "\n";
    return 0;
}
