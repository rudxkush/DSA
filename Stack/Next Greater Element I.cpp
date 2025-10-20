class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> mapPlaces; // nums1[i] -> index
        stack<int> st;
        for (int i = 0; i < n; i++) {
            mapPlaces[nums1[i]] = i;
        }
        for (int i = nums2.size() - 1; i >= 0; --i) {
            while (!st.empty() && st.top() <= nums2[i])
                st.pop();
            if (mapPlaces.find(nums2[i]) != mapPlaces.end())
                ans[mapPlaces[nums2[i]]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }
        return ans;
    }
};
