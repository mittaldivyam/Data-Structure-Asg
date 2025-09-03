#include <iostream>
#include <vector>
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

vector<int> dailyTemperatures(vector<int>& temp) {
    int n = temp.size();
    vector<int> ans(n, 0);
    top = -1; 
    
    for (int i = 0; i < n; i++) {
        while (!isEmpty() && temp[i] > temp[peek()]) {
            int idx = pop();
            ans[idx] = i - idx;
        }
        push(i);
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;
    vector<int> temp(n);
    cout << "Enter temperatures: ";
    for (int i = 0; i < n; i++) cin >> temp[i];
    
    vector<int> ans = dailyTemperatures(temp);
    cout << "Answer: ";
    for (int x : ans) cout << x << " ";
    cout << "\n";
    return 0;
}
