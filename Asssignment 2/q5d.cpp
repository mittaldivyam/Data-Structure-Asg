#include <iostream>
using namespace std;

// index in 1-D for upper-triangular (0-based): i<=j
int idxUT(int n, int i, int j) {            // i,j are 0-based
    int before = i*n - (i*(i-1))/2;         // elements before row i
    return before + (j - i);                // move within row
}

int main() {
    int n; 
    cout << "Enter n: ";
    cin >> n;

    int sz = n*(n+1)/2;
    int ut[sz];
    for(int k=0;k<sz;k++) ut[k]=0;

    cout << "Enter upper triangular elements row-wise (i<=j):\n";
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cin >> ut[idxUT(n,i,j)];
        }
    }

    cout << "\nUpper Triangular Matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>=i) cout << ut[idxUT(n,i,j)] << " ";
            else     cout << 0 << " ";
        }
        cout << "\n";
    }
    return 0;
}