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
