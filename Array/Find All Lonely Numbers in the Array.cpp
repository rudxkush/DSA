#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // To check (nums[i - 1] + 1 == nums[i] && nums[i + 1] == nums[i]) in O(1)
        int n = nums.size();
        vector<int> lonely;
        for (int i = 0; i < n; i++) {
            bool leftCheck = (i == 0) ? true : nums[i - 1] < nums[i] - 1;
            bool rightCheck = (i == n - 1) ? true : nums[i + 1] > nums[i] + 1;
            if (leftCheck && rightCheck) {
                lonely.push_back(nums[i]);
            }
        }
        // for (int lone : lonely) {
        //     cout << lone << " ";
        // }
        return lonely;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    obj.findLonely(nums);
    return 0;
}
