#include <iostream>
using namespace std;

int countInversions(double arr[], int n) {
    int invCount = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                invCount++;
            }
        }
    }
    return invCount;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    double arr[1000];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int inversions = countInversions(arr, n);
    cout << "Number of inversions: " << inversions << endl;

    return 0;
}