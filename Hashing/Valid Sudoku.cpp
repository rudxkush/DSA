int Solution::isValidSudoku(const vector<string> &board) {
    for (int i = 0; i < 9; i++) {
        unordered_set<char> rowSet, colSet, boxSet;
        for (int j = 0; j < 9; j++) {
            // Row check
            if (board[i][j] != '.') {
                if (rowSet.count(board[i][j])) return false;
                rowSet.insert(board[i][j]);
            }

            // Column check
            if (board[j][i] != '.') {
                if (colSet.count(board[j][i])) return false;
                colSet.insert(board[j][i]);
            }

            // 3x3 Box check
            int boxRow = 3 * (i / 3) + j / 3;
            int boxCol = 3 * (i % 3) + j % 3;
            if (board[boxRow][boxCol] != '.') {
                if (boxSet.count(board[boxRow][boxCol])) return false;
                boxSet.insert(board[boxRow][boxCol]);
            }
        }
    }
    return true;
}
