/*
    Author: rudxkush
*/
class Solution {
public:
    vector<int> nearestSmallestOrEqualElementOnLeft(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                res[i] = st.top();
            } else {
                res[i] = -1;
            }
            st.push(i);
        }
        return res;
    }
    vector<int> nearestSmallestElementOnRight(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                res[i] = st.top();
            } else {
                res[i] = n;
            }
            st.push(i);
        }
        return res;
    }
    vector<int> nearestLargestOrEqualElementOnLeft(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                res[i] = st.top();
            } else {
                res[i] = -1;
            }
            st.push(i);
        }
        return res;
    }
    vector<int> nearestLargestElementOnRight(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                res[i] = st.top();
            } else {
                res[i] = n;
            }
            st.push(i);
        }
        return res;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftSmallestOrEqual = nearestSmallestOrEqualElementOnLeft(nums);
        vector<int> rightSmallest = nearestSmallestElementOnRight(nums);
        vector<int> leftLargestOrEqual = nearestLargestOrEqualElementOnLeft(nums);
        vector<int> rightLargest = nearestLargestElementOnRight(nums);

        long long total_minimum = 0;
        long long total_maximum = 0;
    
        for(int i = 0; i < n; i++) {
            int lSe = abs(i - leftSmallestOrEqual[i]);
            int rS = abs(i - rightSmallest[i]);
            int lLe = abs(i - leftLargestOrEqual[i]);
            int rL = abs(i - rightLargest[i]);

            total_minimum += lSe * rS * nums[i];
            total_maximum += lLe * rL * nums[i];
        }
        return total_maximum - total_minimum;
    }
};
