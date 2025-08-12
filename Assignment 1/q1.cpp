#include <iostream>
using namespace std;

int arr[20];
int size = 0;

void insertInitial() {
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void display() {
    if (size == 0) {
        cout << "Array is empty\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << (i == size - 1 ? "" : " ");
    }
    cout << "\n";
}

void insertAt(int pos, int value) {
    if (pos < 0 || pos > size) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    size++;
    cout << "Element inserted.\n";
}

void deleteElement(int pos) {
    if (pos < 0 || pos >= size) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    cout << "Element deleted.\n";
}

void searchElement(int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            cout << "Element found at position " << i << "\n";
            return;
        }
    }
    cout << "Element not found.\n";
}

int main() {
    int choice, pos, value;
    do {
        cout << "\n--- Array Operations Menu ---\n";
        cout << "1. Insert Initial Elements\n";
        cout << "2. Display Array\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Position\n";
        cout << "5. Search Element\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertInitial();
                break;
            case 2:
                display();
                break;
            case 3:
                cout << "Enter position and value: ";
                cin >> pos >> value;
                insertAt(pos, value);
                break;
            case 4:
                cout << "Enter position: ";
                cin >> pos;
                deleteElement(pos);
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                searchElement(value);
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
