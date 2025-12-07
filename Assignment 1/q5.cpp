#include <iostream>
using namespace std;

int main() {
    int r, c;
    cout << "Enter number of rows: ";
    cin >> r;
    cout << "Enter number of columns: ";
    cin >> c;

    int arr[20][20];

    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    // Row sums
    cout << "\nSum of each row:\n";
    for (int i = 0; i < r; i++) {
        int sum = 0;
        for (int j = 0; j < c; j++) {
            sum += arr[i][j];
        }
        cout << "Row " << i << " = " << sum << endl;
    }

    // Column sums
    cout << "\nSum of each column:\n";
    for (int j = 0; j < c; j++) {
        int sum = 0;
        for (int i = 0; i < r; i++) {
            sum += arr[i][j];
        }
        cout << "Column " << j << " = " << sum << endl;
    }

    return 0;
}
