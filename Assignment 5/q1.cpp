#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAtBeginning(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << val << " at the beginning.\n";
}

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
    cout << "Inserted " << val << " at the end.\n";
}

void insertBeforeValue(int val, int beforeVal) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == beforeVal) {
        insertAtBeginning(val);
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != beforeVal)
        temp = temp->next;

    if (temp->next == nullptr) {
        cout << "Node with value " << beforeVal << " not found.\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Inserted " << val << " before " << beforeVal << ".\n";
}

void insertAfterValue(int val, int afterVal) {
    Node* temp = head;
    while (temp != nullptr && temp->data != afterVal)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Node with value " << afterVal << " not found.\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Inserted " << val << " after " << afterVal << ".\n";
}

void deleteFromBeginning() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    cout << "Deleted node from beginning.\n";
}

void deleteFromEnd() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "Deleted last node.\n";
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;

    delete temp->next;
    temp->next = nullptr;
    cout << "Deleted node from end.\n";
}

void deleteSpecificNode(int val) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    if (head->data == val) {
        deleteFromBeginning();
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != val)
        temp = temp->next;

    if (temp->next == nullptr) {
        cout << "Node with value " << val << " not found.\n";
        return;
    }

    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
    cout << "Deleted node with value " << val << ".\n";
}

void searchNode(int val) {
    Node* temp = head;
    int pos = 1;
    while (temp != nullptr) {
        if (temp->data == val) {
            cout << "Node with value " << val << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node with value " << val << " not found.\n";
}

void displayList() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr)
            cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

int main() {
    int choice, val, key;
    do {
        cout << "\n===== Singly Linked List Menu =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Value\n";
        cout << "4. Insert After a Value\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search for a Node\n";
        cout << "9. Display List\n";
        cout << "0. Exit\n";
        cout << "===================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                insertAtEnd(val);
                break;
            case 3:
                cout << "Enter new value and before which value: ";
                cin >> val >> key;
                insertBeforeValue(val, key);
                break;
            case 4:
                cout << "Enter new value and after which value: ";
                cin >> val >> key;
                insertAfterValue(val, key);
                break;
            case 5:
                deleteFromBeginning();
                break;
            case 6:
                deleteFromEnd();
                break;
            case 7:
                cout << "Enter value to delete: ";
                cin >> val;
                deleteSpecificNode(val);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> val;
                searchNode(val);
                break;
            case 9:
                displayList();
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
