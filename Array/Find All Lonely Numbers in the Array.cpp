/*
    Author : rudxkush
*/
#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution1 {
public:
    void findLonely(vector<int>& nums) {
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
        for (int lone : lonely) {
            cout << lone << " ";
        }
        cout << endl;
    }
};

class Solution2 {
public:
    void findLonely(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        int n = nums.size();
        vector<int> lonely;
        for (int i = 0; i < n; i++) {
            if (mp[nums[i]] == 1 &&
                mp.find(nums[i] - 1) == mp.end() &&
                mp.find(nums[i] + 1) == mp.end()) {
                lonely.push_back(nums[i]);
            }
        }
        for (int lone : lonely) {
            cout << lone << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << "Using Sort -------> TC: O(nlogn), SC: O(0)" << endl;
    Solution1 obj1;
    obj1.findLonely(nums);
    cout << "Using Unordered Map -------> TC: O(n), SC: O(n)" << endl;
    Solution2 obj2;
    obj2.findLonely(nums);
    return 0;
}
