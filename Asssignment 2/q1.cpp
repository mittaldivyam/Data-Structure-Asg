#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int left=0, right=size-1;
    while(left<=right) {
        int mid=left+(right-left)/2;
        if(arr[mid]==target) return mid;
        else if(arr[mid]<target) left=mid+1;
        else right=mid-1;
    }
    return -1;
}

int main() {
    int sortedArr[] = {2,5,10,12,16,20,30,52,75,90};
    int size = sizeof(sortedArr)/sizeof(sortedArr[0]);
    int target = 2;
    int result = binarySearch(sortedArr, size, target);
    if(result != -1) cout << "Element found at index: " << result << endl;
    else cout << "Element not found in the array." << endl;
    return 0;
}
