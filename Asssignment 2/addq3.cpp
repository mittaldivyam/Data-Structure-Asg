#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of matrix (n): ";
    cin >> n;

    int arr[100][100];  // Assuming max size 100x100

    int val = 1;
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;

    while (val <= n * n) {
        for (int i = left; i <= right && val <= n * n; i++) arr[top][i] = val++;
        top++;

        for (int i = top; i <= bottom && val <= n * n; i++) arr[i][right] = val++;
        right--;

        for (int i = right; i >= left && val <= n * n; i--) arr[bottom][i] = val++;
        bottom--;

        for (int i = bottom; i >= top && val <= n * n; i--) arr[i][left] = val++;
        left++;
    }

    cout << "Spiral Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << arr[i][j] << "\t";
        cout << "\n";
    }

    return 0;
}
