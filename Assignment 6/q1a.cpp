#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insert(int val, int ref = -1, bool after = true) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = newNode;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;

    if (ref == -1) { // insert at end
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        return;
    }

    do {
        if (temp->data == ref) {
            if (after) {
                newNode->next = temp->next;
                temp->next = newNode;
            } else {
                Node* prev = head;
                while (prev->next != temp)
                    prev = prev->next;
                prev->next = newNode;
                newNode->next = temp;
                if (temp == head)
                    head = newNode;
            }
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Reference not found.\n";
    delete newNode;
}

void deleteNode(int key) {
    if (head == nullptr) {
        cout << "List empty.\n";
        return;
    }

    Node *curr = head, *prev = nullptr;
    do {
        if (curr->data == key) {
            if (curr == head && curr->next == head) {
                delete head;
                head = nullptr;
                cout << "Node deleted.\n";
                return;
            }
            if (curr == head) {
                Node* last = head;
                while (last->next != head)
                    last = last->next;
                head = head->next;
                last->next = head;
            } else {
                prev->next = curr->next;
            }
            delete curr;
            cout << "Node deleted.\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);

    cout << "Node not found.\n";
}

void search(int key) {
    if (head == nullptr) {
        cout << "List empty.\n";
        return;
    }
    int pos = 1;
    Node* temp = head;
    do {
        if (temp->data == key) {
            cout << "Node " << key << " found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    cout << "Node not found.\n";
}

void display() {
    if (head == nullptr) {
        cout << "List empty.\n";
        return;
    }
    Node* temp = head;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    int choice, val, ref;
    bool after;
    while (true) {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Insert Node\n2. Delete Node\n3. Search Node\n4. Display List\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Insert (1) at end or (2) before/after specific node? ";
                cin >> choice;
                if (choice == 1)
                    insert(val);
                else {
                    cout << "Enter reference node value: ";
                    cin >> ref;
                    cout << "Insert after(1) or before(0) reference node? ";
                    cin >> after;
                    insert(val, ref, after);
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
