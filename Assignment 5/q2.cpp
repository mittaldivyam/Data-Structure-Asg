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
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}

void displayList() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr)
            cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

void countAndDeleteOccurrences(int key) {
    int count = 0;

    while (head != nullptr && head->data == key) {
        Node* del = head;
        head = head->next;
        delete del;
        count++;
    }

    Node* temp = head;
    while (temp != nullptr && temp->next != nullptr) {
        if (temp->next->data == key) {
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
            count++;
        } else {
            temp = temp->next;
        }
    }

    cout << "Count: " << count << " , Updated Linked List: ";
    if (head == nullptr)
        cout << "Empty List" << endl;
    else
        displayList();
}

int main() {
    int n, val, key;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtEnd(val);
    }

    cout << "Enter key to delete: ";
    cin >> key;

    cout << "Original Linked List: ";
    displayList();

    countAndDeleteOccurrences(key);

    return 0;
}
