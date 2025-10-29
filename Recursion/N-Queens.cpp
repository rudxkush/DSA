/*
    Author: rudxkush
*/
class Solution {
public:
    int rows = 0, cols = 0;
    vector<vector<string>> allConfigs;
    bool puttingHereMakesNoDifference(vector<string>& board, int rank, int file) {
        // row and column check
        for(int i = 0; i < board.size(); i++) {
            if(board[rank][i] == 'Q') return false;
            if(board[i][file] == 'Q') return false;
        }

        // diagonal check
        for(int i = rank, j = file; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q') return false;
        }

        // anti diagonal check
        for(int i = rank, j = file; i >= 0 && j < board.size(); i--, j++) {
            if(board[i][j] == 'Q') return false;
        } 

        return true;
    }
    void placeNQueens(vector<string>& board, int rank, int n) {
        // Base Condition
        if (rank == rows) {
            allConfigs.push_back(board);
            return ;
        }

        // Choices
        for (int file = 0; file < cols; file++) {
            if (puttingHereMakesNoDifference(board, rank, file)) {
                board[rank][file] = 'Q';
                placeNQueens(board, rank + 1, n - 1);
                board[rank][file] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        // Classic Backracking Problem
        rows = n;
        cols = n;
        vector<string> board(n, string(n, '.'));
        placeNQueens(board, 0, n);
        return allConfigs;
    }
};
