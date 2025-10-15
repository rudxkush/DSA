class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for (auto op : operations) {
            if (op == "C") {
                st.pop();
            } else if (op == "D") {
                st.push(st.top() * 2);
            } else if (op == "+") {
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                int sum = top1 + top2;
                st.push(top1);
                st.push(sum);
            } else {
                st.push(stoi(op));
            }
        }

        int totalSum = 0;
        while (!st.empty()) {
            totalSum += st.top();
            st.pop();
        }
        return totalSum;
    }
};
