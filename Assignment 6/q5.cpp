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
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

bool isCircular() {
    if (head == nullptr) return false; // empty list is not considered circular

    Node* temp = head->next;
    while (temp != nullptr && temp != head)
        temp = temp->next;

    return (temp == head);
}

void makeCircular() {
    if (head == nullptr) return;
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = head; // make list circular
}

int main() {
    int n, val, choice;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtEnd(val);
    }

    cout << "Do you want to make the list circular? (1-Yes, 0-No): ";
    cin >> choice;
    if (choice == 1)
        makeCircular();

    if (isCircular())
        cout << "The linked list is circular.\n";
    else
        cout << "The linked list is not circular.\n";

    return 0;
}
