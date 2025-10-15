#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;

void insertAtEnd(char val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

bool isPalindrome() {
    if (head == nullptr) return true; // empty list is palindrome

    Node* left = head;
    Node* right = head;

    // Move right pointer to the last node
    while (right->next != nullptr)
        right = right->next;

    // Compare left and right characters
    while (left != right && left->prev != right) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

void display() {
    Node* temp = head;
    cout << "Doubly Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n;
    char val;
    cout << "Enter number of characters: ";
    cin >> n;

    cout << "Enter characters: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtEnd(val);
    }

    display();

    if (isPalindrome())
        cout << "The linked list is a palindrome.\n";
    else
        cout << "The linked list is not a palindrome.\n";

    return 0;
}
