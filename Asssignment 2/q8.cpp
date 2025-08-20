#include <iostream>
using namespace std;

int countDistinct(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[1000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int distinctCount = countDistinct(arr, n);
    cout << "Total distinct elements: " << distinctCount << endl;

    return 0;
}