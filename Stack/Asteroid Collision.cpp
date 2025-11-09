/*
    Author : rudxkush
*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (ast[i] > 0)
                st.push(ast[i]);
            else {
                int left = -ast[i];
                while (!st.empty() && st.top() < left && st.top() > 0) {
                    st.pop();
                }
                if (!st.empty() && st.top() == left) {
                    st.pop();
                } else if (st.empty() || st.top() < 0) {
                    st.push(ast[i]);
                }
            }
        }
        int survived = st.size() - 1;
        vector<int> astW(survived + 1);
        while (!st.empty()) {
            astW[survived] = st.top();
            survived--;
            st.pop();
        }
        return astW;
    }
};
