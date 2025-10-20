class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> nextWarmer(n);
        stack<pair<int, int>> st; // {temperature, index}
        for(int i = n - 1; i >= 0; --i) {
            while(!st.empty() && st.top().first <= temp[i]) {
                st.pop();
            }
            if(!st.empty()) {
                int days = abs(st.top().second - i);
                nextWarmer[i] = days;
            } else {
                nextWarmer[i] = 0;
            }
            st.push({temp[i], i});
        }
        return nextWarmer;
    }
};
