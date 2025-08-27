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

char peek() {
    if (top == -1) return '\0';
    return stack[top];
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int k = 0;
    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix[k++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && peek() != '(')
                postfix[k++] = pop();
            pop(); 
        }
        else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c))
                postfix[k++] = pop();
            push(c);
        }
    }
    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
    cout << "Postfix: " << postfix << "\n";
}

int main() {
    char infix[MAX];
    cout << "Enter infix expression: ";
    cin >> infix;
    infixToPostfix(infix);
    return 0;
}
