/*
  Author : rudxkush
*/
vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int n = (int) A.size();
    int m = (int) A[0].size();
    int totalElements = n * m;

    int up = 0, down = n - 1, left = 0, right = m - 1;
    vector<int> spiral;

    while (totalElements > 0) {

        // move left → right
        for (int i = left; i <= right && totalElements > 0; i++) {
            spiral.push_back(A[up][i]);
            totalElements--;
        }
        up++;

        // move top → bottom
        for (int i = up; i <= down && totalElements > 0; i++) {
            spiral.push_back(A[i][right]);
            totalElements--;
        }
        right--;

        // move right → left
        for (int i = right; i >= left && totalElements > 0; i--) {
            spiral.push_back(A[down][i]);
            totalElements--;
        }
        down--;

        // move bottom → top
        for (int i = down; i >= up && totalElements > 0; i--) {
            spiral.push_back(A[i][left]);
            totalElements--;
        }
        left++;
    }

    return spiral;
}
