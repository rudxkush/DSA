class Solution {
public:
    int uniquePaths(int m, int n) {
        int total_moves = m + n - 2;
        int down_moves = m - 1;
        int right_moves = n - 1;
        // or n - 1 as it has a combinatorial symmetry
        long long nCr = 1;
        for(int i = 1; i <= down_moves; i++) {
            nCr *= (total_moves - down_moves + i);
            nCr /= i;
        }
        return (int) nCr;
    }
};
