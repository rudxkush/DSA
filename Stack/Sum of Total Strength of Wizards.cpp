/*
    Author: rudxkush
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
const int mod = 1e9 + 7;
class Solution {
private:
    int n = 0;
    vector<long long> pprefix;
    vector<long long> prefix;
    vector<int> nse;
    vector<int> psee;
public:
    void build_prefix_arrays(vector<int>& strength) {
        prefix.assign(n + 1, 0);
        pprefix.assign(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = (prefix[i] + strength[i]) % mod;          // standard prefix sum
            pprefix[i + 1] = (pprefix[i] + prefix[i + 1]) % mod;      // prefix of prefix
        }
    }
    void nearest_smaller_element_on_right(vector<int>& strength) {
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && strength[st.top()] >= strength[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nse[i] = st.top();
            }
            st.push(i);
        }
    }
    void nearest_smaller_or_equal_element_on_left(vector<int>& strength) {
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && strength[st.top()] > strength[i]) {
                st.pop();
            }
            if (!st.empty()) {
                psee[i] = st.top();
            }
            st.push(i);
        }
    }
    int totalStrength(vector<int>& strength) {
        n = strength.size();
        build_prefix_arrays(strength);

        nse.assign(n, n);
        nearest_smaller_element_on_right(strength);

        psee.assign(n, -1);
        nearest_smaller_or_equal_element_on_left(strength);

        auto modSub = [&](long long a, long long b) {
            return (a - b + mod) % mod;
        };

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int left_count = i - psee[i];
            int right_count = nse[i] - i;

            long long total_left  = modSub(pprefix[i], pprefix[max(0, psee[i])]);
            long long total_right = modSub(pprefix[nse[i]], pprefix[i]);

            long long contrib = (strength[i] % mod) *
                (( (left_count * total_right % mod - right_count * total_left % mod + mod) % mod )) % mod;

            ans = (ans + contrib) % mod;
        }
        return ans;
    }
};

int main() {
    /*
        As the ruler of a kingdom, you have an army of wizards at your command.
        You are given a 0-indexed integer array strength, where strength[i] denotes the strength of the ith wizard.
        For a contiguous group of wizards (i.e. the wizards' strengths form a subarray of strength), the total strength
        is defined as the product of the following two values:
            1. The strength of the weakest wizard in the group.
            2. The total of all the individual strengths of the wizards in the group.

        Input: strength = [1,3,1,2]
        Output: 44
        Explanation: The following are all the contiguous groups of wizards:
        - [1] from [1,3,1,2] has a total strength of min([1]) * sum([1]) = 1 * 1 = 1
        - [3] from [1,3,1,2] has a total strength of min([3]) * sum([3]) = 3 * 3 = 9
        - [1] from [1,3,1,2] has a total strength of min([1]) * sum([1]) = 1 * 1 = 1
        - [2] from [1,3,1,2] has a total strength of min([2]) * sum([2]) = 2 * 2 = 4
        - [1,3] from [1,3,1,2] has a total strength of min([1,3]) * sum([1,3]) = 1 * 4 = 4
        - [3,1] from [1,3,1,2] has a total strength of min([3,1]) * sum([3,1]) = 1 * 4 = 4
        - [1,2] from [1,3,1,2] has a total strength of min([1,2]) * sum([1,2]) = 1 * 3 = 3
        - [1,3,1] from [1,3,1,2] has a total strength of min([1,3,1]) * sum([1,3,1]) = 1 * 5 = 5
        - [3,1,2] from [1,3,1,2] has a total strength of min([3,1,2]) * sum([3,1,2]) = 1 * 6 = 6
        - [1,3,1,2] from [1,3,1,2] has a total strength of min([1,3,1,2]) * sum([1,3,1,2]) = 1 * 7 = 7
        The sum of all the total strengths is 1 + 9 + 1 + 4 + 4 + 4 + 3 + 5 + 6 + 7 = 44.

        Intuition: prefixSu for getting the sum and knowing the start and end of every minimum via stacks.
     */
    vector<int> strength = {1,3,1,2};
    Solution obj;
    cout << obj.totalStrength(strength) << endl;
    return 0;
}
