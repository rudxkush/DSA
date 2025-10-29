/*
    Author: rudxkush
*/
class Solution {
public:
    const int mod = 1e9 + 7;
    vector<int> nearestSmallerElementOnRight(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                res[i] = st.top();
            } else {
                res[i] = n; // no smallest on the right
            }
            st.push(i);
        }
        return res;
    }
    vector<int> nearestSmallerOrEqualElementOnLeft(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                res[i] = st.top();
            } else {
                res[i] = -1; // no smallest on the left
            }
            st.push(i);
        }
        return res;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> left = nearestSmallerOrEqualElementOnLeft(arr);
        vector<int> right = nearestSmallerElementOnRight(arr);
        int ans = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int l = abs(i - left[i]);
            int r = abs(i - right[i]);
            ans = (ans + (l * r * 1LL * arr[i]) % mod) % mod;
        }
        return ans;
    }
};
