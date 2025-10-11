class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int count = 0;
        for(int i = n-1; i >= 2; i--) {
            int j = 0;
            int k = i - 1;
            // set these two in a way that we get the sum
            // of any 2 elements in triplet to be greater then the third.
            while(j < k) {
                if(arr[j] + arr[k] > arr[i]) {
                    count += k - j;
                    k--;
                } else {
                    j++;
                }
            }
        }
        return count;
    }
};
