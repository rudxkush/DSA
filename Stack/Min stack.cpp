#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<int> st;
    int minNumber;
public:
    MinStack() {
        minNumber = INT_MAX;
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push(val);
            minNumber = val;
        } else if (val < minNumber) {
            st.push(2 * val - minNumber); 
            minNumber = val;
        } else {
            st.push(val);
        }
    }
    
    /*
      when you get a new minima
      you try to encode it with prevMin and the currMin and store it into the stack
      Encoded = 2 * currMin - prevMin
      st.push(Encoded);
      at the time of pop,
      if(st.top() < minNumber) {
        prevMin = 2 * currMin - Encoded;
        globalMini = prevMin;
      }
    */
    
    void pop() {
        if (st.empty()) return;
        if (st.top() < minNumber) {
            minNumber = 2 * minNumber - st.top();
        }
        st.pop();
    }
    
    int top() {
        if (st.empty()) return -1;
        if (st.top() < minNumber) return minNumber; 
        return st.top();
    }
    
    int getMin() {
        return minNumber;
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl; // -3
    minStack.pop();
    cout << minStack.top() << endl;    // 0
    cout << minStack.getMin() << endl; // -2
    return 0;
}
