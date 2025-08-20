#include <iostream>
using namespace std;

int main() {
    // Sparse matrix in triplet form
    // First row: rows, cols, nonZero
    int A[10][3] = { {3,3,3}, {0,0,5}, {1,1,8}, {2,2,10} };
    int T[10][3];

    int rows = A[0][0], cols = A[0][1], t = A[0][2];

    // First entry of transpose
    T[0][0] = cols;
    T[0][1] = rows;
    T[0][2] = t;

    int k = 1;
    // For each column of original, find elements
    for(int col=0; col<cols; col++) {
        for(int i=1; i<=t; i++) {
            if(A[i][1] == col) {
                T[k][0] = A[i][1];  // new row = old col
                T[k][1] = A[i][0];  // new col = old row
                T[k][2] = A[i][2];
                k++;
            }
        }
    }

    // Print result
    cout << "Transpose in triplet form:\n";
    cout << "Row Col Val\n";
    for(int i=0; i<=t; i++) {
        cout << T[i][0] << " " << T[i][1] << " " << T[i][2] << endl;
    }
    return 0;
}