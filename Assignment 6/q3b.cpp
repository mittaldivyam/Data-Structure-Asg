#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAtEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = newNode;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

int sizeOfCircular() {
    if (head == nullptr)
        return 0;

    int count = 1;
    Node* temp = head->next;
    while (temp != head) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int n, val;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtEnd(val);
    }

    cout << "Size of Circular Linked List: " << sizeOfCircular() << endl;
    return 0;
}
