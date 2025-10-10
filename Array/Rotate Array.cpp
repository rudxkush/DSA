class Solution {
  public:
    void reverseArr(vector<int>& arr, int l, int r) {
        while(l < r) {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n;                 // if d >= n
        if (d == 0) return ;

        reverseArr(arr, 0, n - 1);
        reverseArr(arr, 0, n - d - 1);
        reverseArr(arr, n - d, n - 1);
    }
};
