vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    /*
        [
            [0, 0] 
            [0, 1], [1, 0]  
            [0, 2], [1, 1], [2, 0] 
            [1, 2], [2, 1]  
            [2, 2] 
        ]
    */ 
    int n = (int) A.size();
    int number_of_rows = 2*n - 1;
    vector<vector<int>> antiDiagonal(number_of_rows);
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            antiDiagonal[i + j].push_back(A[i][j]);
        }
    }
    return antiDiagonal;
}
