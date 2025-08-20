#include <iostream>
using namespace std;

// function to set value in diagonal matrix
void setDiagonal(int arr[], int n, int i, int j, int val) {
    if(i == j) {
        arr[i-1] = val;   // store only diagonal elements
    }
}

// function to get value at (i, j)
int getDiagonal(int arr[], int n, int i, int j) {
    if(i == j)
        return arr[i-1];
    else
        return 0;   // non-diagonal elements are always 0
}

// function to display the full matrix
void display(int arr[], int n) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout << getDiagonal(arr, n, i, j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int arr[n];   // store only diagonal elements
    for(int i=0; i<n; i++) arr[i] = 0;  // initialize with 0

    cout << "Enter " << n << " diagonal elements:\n";
    for(int i=1; i<=n; i++) {
        int val;
        cin >> val;
        setDiagonal(arr, n, i, i, val);
    }

    cout << "\nDiagonal Matrix is:\n";
    display(arr, n);

    return 0;
}