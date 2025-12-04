#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printArray(string& nums) {
    int n = (int) nums.size();
    for (int i = 0; i < n - 1; i++) {
        cout << nums[i] << ", ";
    }
    cout << nums[n - 1] << endl;
}
class Solution {
public:
    string generateNextPalindrome(string& nums) {
        int n = (int) nums.size(), mid = (n - 1) / 2;

        string ans = nums;
        for (int i = 0 ; i <= mid; i++) {
            ans[n - i - 1] = ans[i];
        }
        for (int i = 0; i < n; i++) {
            if (ans[i] < nums[i]) { // smaller than nums
                break;
            } else if (ans[i] > nums[i]) { // strictly greater -> return
                return ans;
            }
        }

        printArray(ans);
        for (int i = mid; i >= 0; i--) {
            if (ans[i] < '9') {
                ans[i] = (char) ans[i] + 1;
                ans[n - i - 1] = ans[i];
                return ans;
            }
            ans[i] = '0';
            ans[n - 1 - i] = '0';
        }
        ans[0] = '1';
        ans.push_back('1');
        return ans;
    }
};

int main() {
    string nums = "94187978322";
    cout << "Given Array: " << endl;
    printArray(nums);
    Solution palindrome;
    string ans = palindrome.generateNextPalindrome(nums);
    cout << "Next smallest palindrome: " << endl;
    printArray(ans);
    return 0;
}
