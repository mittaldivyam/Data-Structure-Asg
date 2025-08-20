#include <iostream>
using namespace std;

int findMissingNumber(int arr[], int size) {
    int left = 0, right = size - 1;
    int expected_diff = arr[0] - 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int current_diff = arr[mid] - mid;

        if (current_diff == expected_diff) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left + expected_diff;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6, 7};
    int size = sizeof(arr)/sizeof(arr[0]);

    int missing = findMissingNumber(arr, size);
    cout << "Missing number is: " << missing << endl;

    return 0;
}
