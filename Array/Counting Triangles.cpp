const int mod = 1e9 + 7;
int Solution::nTriang(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int count = 0;
    for(int k = n - 1; k > 1; k--) {
        int i = 0, j = k - 1;
        while(i != j) {
            if(arr[i] + arr[j] > arr[k]) {
                int validPairs = j - i;
                count = (count + validPairs) % mod;
                j--;
            } else {
                i++;
            }
        }
    }
    return count;
}
