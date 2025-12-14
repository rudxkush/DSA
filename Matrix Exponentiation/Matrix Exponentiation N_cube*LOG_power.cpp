#include <iostream>
#include <vector>
using namespace std;
const int mod = 1e9+7;

void printMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    cout << "Printing Result: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "   ";
        }
        cout << endl;
    }
}

vector<vector<int>> multiplyMatrix(vector<vector<int>>& A, vector<vector<int>>& B) {
    int n = A.size();          // rows of A
    int p = A[0].size();       // cols of A = rows of B
    int m = B[0].size();       // cols of B
    vector<vector<int>> product(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                product[i][j] = (product[i][j] + (A[i][k] * B[k][j]) % mod) % mod;
            }
        }
    }
    return product;
}

vector<vector<int>> identityMatrix(int N) {
    vector<vector<int>> I(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) I[i][i] = 1;
    return I;
}

vector<vector<int>> computeMatrixExponentiation(vector<vector<int>>& matrix, int N) {
    if (N == 0) {
        int size = matrix.size();
        return identityMatrix(size);
    }
    if (N == 1) { // if it is A^1
        return matrix;
    }

    vector<vector<int>> resultByTwo = computeMatrixExponentiation(matrix, N/2);
    vector<vector<int>> computedValue = multiplyMatrix(resultByTwo, resultByTwo);

    if (N & 1) { // If N is odd
        return multiplyMatrix(computedValue, matrix);
    } else {
        return computedValue;
    }
}

int main() {
    int N;
    vector<vector<int>> matrix;
    cout << "Enter Matrix Size: " << endl;
    int row_size, col_size;
    cin >> row_size >> col_size;
    if (row_size != col_size) {
        cout << "Matrix exponentiation requires a square matrix" << endl;
        return 0;
    }
    matrix.resize(row_size, vector<int> (col_size));
    cout << "Enter Matrix Elements: " << endl;
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "Enter Power: " << endl;
    cin >> N;
    vector<vector<int>> res = computeMatrixExponentiation(matrix, N);
    printMatrix(res);
    return 0;
}
