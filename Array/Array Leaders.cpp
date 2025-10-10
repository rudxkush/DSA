class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> we;
        int n = arr.size();
        int mini = arr[n-1] - 1;
        for(int i = n - 1; i >= 0; i--) {
            if(mini <= arr[i]) {
                we.push_back(arr[i]);
                mini = arr[i];
            }
        }
        reverse(we.begin(), we.end());
        return we;
    }
};
