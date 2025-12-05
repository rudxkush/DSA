typedef vector<vector<int>> Matrix;

vector<vector<int> > Solution::prettyPrint(int n) {
    int size = 2*n - 1;
    Matrix ans(size, vector<int>(size));
    // build the answer matrix
    for(int i = 0; i < n; i++) {
        for(int j = i; j < size - i; j++) {
        ans[i][j] = n - i;
        ans[j][i] = n - i;
        ans[size - 1 - i][size - 1 - j] = n - i;
        ans[j][size - 1 - i] = n - i;
        }
    }
    return ans;
}
