#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    int arr[100][100];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    bool found = false;

    for (int i = 0; i < n; i++) {
        int minVal = arr[i][0];
        int colIndex = 0;
        for (int j = 1; j < m; j++) {
            if (arr[i][j] < minVal) {
                minVal = arr[i][j];
                colIndex = j;
            }
        }

        bool isSaddle = true;
        for (int k = 0; k < n; k++) {
            if (arr[k][colIndex] > minVal) {
                isSaddle = false;
                break;
            }
        }

        if (isSaddle) {
            cout << "Saddle point found at (" << i << ", " << colIndex << ") with value " << minVal << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No saddle point found.\n";
    }

    return 0;
}
