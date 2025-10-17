class Solution {
public:
    bool checkValidity(char open, char close) {
        return (open == '(' && close == ')') || (open == '{' && close == '}') ||
               (open == '[' && close == ']');
    }

    bool isValid(string s) {
        stack<char> st;
        for (char bracket : s) {
            if (bracket == '(' || bracket == '{' || bracket == '[') {
                st.push(bracket);
            } else {
                if (st.empty())
                    return false;
                char top = st.top();
                st.pop();
                if (!checkValidity(top, bracket))
                    return false;
            }
        }
        return st.empty();
    }
};
