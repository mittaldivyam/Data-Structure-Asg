#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;

void insert(int val, int pos = -1, int ref = -1, bool after = true) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = newNode->prev = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    if (pos == 1) { // insert at beginning
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->data != ref)
        temp = temp->next;

    if (ref == -1) { // insert at end
        temp->next = newNode;
        newNode->prev = temp;
    } else {
        if (temp->data != ref) {
            cout << "Reference not found.\n";
            delete newNode;
            return;
        }
        if (after) {
            newNode->next = temp->next;
            if (temp->next)
                temp->next->prev = newNode;
            temp->next = newNode;
            newNode->prev = temp;
        } else {
            newNode->next = temp;
            newNode->prev = temp->prev;
            if (temp->prev)
                temp->prev->next = newNode;
            temp->prev = newNode;
            if (temp == head)
                head = newNode;
        }
    }
}

void deleteNode(int key) {
    if (head == nullptr) {
        cout << "List empty.\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr && temp->data != key)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Node not found.\n";
        return;
    }

    if (temp == head)
        head = head->next;

    if (temp->next)
        temp->next->prev = temp->prev;
    if (temp->prev)
        temp->prev->next = temp->next;

    delete temp;
    cout << "Node deleted.\n";
}

void search(int key) {
    int pos = 1;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key) {
            cout << "Node " << key << " found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node not found.\n";
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
    int choice, val, ref;
    bool after;

    while (true) {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert Node\n2. Delete Node\n3. Search Node\n4. Display List\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Insert (1) at end or (2) before/after specific node or (3) at start? ";
                cin >> choice;
                if (choice == 3)
                    insert(val, 1);
                else if (choice == 1)
                    insert(val);
                else {
                    cout << "Enter reference node value: ";
                    cin >> ref;
                    cout << "Insert after(1) or before(0) reference node? ";
                    cin >> after;
                    insert(val, -1, ref, after);
                }
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                deleteNode(val);
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> val;
                search(val);
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
