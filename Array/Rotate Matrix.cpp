/*
    Author : rudxkush
*/
void bruteSolution::rotate(vector<vector<int> > &A) {
    // Transpose of matrix A is what 90 D rotation(A) looks like
    int n = (int) A.size();
    vector rotatedMatrixA(n, vector<int>(n)); 
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {
            rotatedMatrixA[row][col] = A[n - 1 - col][ row];
        }
    }
    A = rotatedMatrixA;
}

void Solution::rotate(vector<vector<int> > &A) {
    // reverse row wise
    reverse(A.begin(), A.end());
    // swap values to there desired location
    int n = (int) A.size();
    for(int row = 0; row < n; row++) {
        for(int col = row + 1; col < n; col++) {
            swap(A[row][col], A[col][row]);
        }
    }
}
