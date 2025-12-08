class Solution {
  public:
    int getLeftCount(vector<vector<int>>& mat, int num) {
        int count = 0, n = (int) mat.size(), m = (int) mat[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] <= num) {
                    count++;
                }
            }
        }
        return count;
    }
    int findMedian(vector<vector<int>>& mat) {
        int n = (int) mat.size(), m = (int) mat[0].size();
        int start = 1;
        int end = INT_MAX;
        for(int i = 0; i < n; i++) {
            end = max(end, mat[i][m - 1]);
        }

        int mThreshold = n*m / 2;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if (getLeftCount(mat, mid) <= mThreshold) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return start;
    }
};
