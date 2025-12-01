void Solution::setZeroes(vector<vector<int> > &A) {
    int n = (int) A.size();
    int m = (int) A[0].size();

    bool firstRowZero = false;
    bool firstColZero = false;

    // check if first row has zero
    for(int j = 0; j < m; j++) {
        if(A[0][j] == 0) firstRowZero = true;
    }

    // check if first col has zero
    for(int i = 0; i < n; i++) {
        if(A[i][0] == 0) firstColZero = true;
    }

    // use first row and column as markers
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(A[i][j] == 0) {
                A[i][0] = 0;
                A[0][j] = 0;
            }
        }
    }

    // apply row markers
    for(int i = 1; i < n; i++) {
        if(A[i][0] == 0) {
            for(int j = 1; j < m; j++) {
                A[i][j] = 0;
            }
        }
    }

    // apply column markers
    for(int j = 1; j < m; j++) {
        if(A[0][j] == 0) {
            for(int i = 1; i < n; i++) {
                A[i][j] = 0;
            }
        }
    }

    // handle first row
    if(firstRowZero) {
        for(int j = 0; j < m; j++) A[0][j] = 0;
    }

    // handle first col
    if(firstColZero) {
        for(int i = 0; i < n; i++) A[i][0] = 0;
    }
}
