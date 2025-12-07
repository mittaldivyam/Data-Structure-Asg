#include <iostream>
using namespace std;

int arr[20];
int size = 0;
bool hashTable[1000] = {false};   // assuming values < 1000

void insert() {
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void print() {
    cout << "The elements of the array are: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void deleteElement(int pos) {
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void remove_duplicates() {
    for (int i = 0; i < size; i++) {
        if (hashTable[arr[i]] == false) {
            hashTable[arr[i]] = true;
        } else {
            deleteElement(i);
            i--;
        }
    }
}

int main() {
    insert();
    cout << "Original array: ";
    print();

    remove_duplicates();

    cout << "After removing duplicates array: ";
    print();
}
