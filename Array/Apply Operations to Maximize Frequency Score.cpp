/*
    Author: rudxkush
*/
#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <math.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    int maxFrequencyScore(vector<int>& nums, long long k) {
        ll n = nums.size();
        sort(nums.begin(), nums.end());

        vector<ll> prefixSum(n + 1);
        prefixSum[0] = 0;
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        ll maxWindow = 0;
        ll l = 0, r = 0;
        while(r < n) {
            r++; // Window is now [l, r)

            ll mid = l + (r - l)/2;
            ll target = nums[mid];
            ll leftLen = mid - l;
            ll rightLen = r - mid;

            // Note: We use prefixSum[mid] and prefixSum[l] for the left part
            ll leftCost = target * leftLen - (prefixSum[mid] - prefixSum[l]);
            // Note: We use prefixSum[r] and prefixSum[mid] for the right part
            ll rightCost = (prefixSum[r] - prefixSum[mid]) - target * rightLen;

            // Shrink the window
            while(leftCost + rightCost > k) {
                l++; // Shrink from the left

                // Recalculate cost for the new window [l, r)
                mid = l + (r - l)/2;
                target = nums[mid];
                leftLen = mid - l;
                rightLen = r - mid;
                leftCost = target * leftLen - (prefixSum[mid] - prefixSum[l]);
                rightCost = (prefixSum[r] - prefixSum[mid]) - target * rightLen;
            }

            maxWindow = max(maxWindow, r - l);
        }
        return (int) maxWindow;
    }
};

// class bruteSolution {
// public:
//     int maxFrequencyScore(vector<int>& nums, long long k) {
//         int maxFrequency = 1; // Number itself
//         int n = nums.size();
//         for (int i = 0; i < n; i++) {
//             int target = nums[i];
//             int operations_performed_to_convert_element_to_target = 0;
//             int freq = 0;
//             long long leftK = k;
//             for (int j = 0; j < n; j++) {
//                 // 2 things to thing here is what if the number is greater than the target and number is lesser than the target
//                 if (nums[j] <= target) {
//                     operations_performed_to_convert_element_to_target += target - nums[j];
//                 } else {
//                     operations_performed_to_convert_element_to_target += nums[j] - target;
//                 }
//                 if (operations_performed_to_convert_element_to_target <= leftK) {
//                     leftK = leftK - (long long) operations_performed_to_convert_element_to_target;
//                     freq++;
//                 } else {
//                     // exponentially grow into two separate choice based binary tree where one choice where you do not touch leftK and everything else stays intact
//                     // and other option is you start from here finding all the possible by incrementing or decrementing
//                 }
//             }
//             maxFrequency = max(maxFrequency, freq);
//         }
//         return maxFrequency;
//     }
// };

int main() {
    int n = 13;
    long long k = 45;
    // cin >> n >> k;
    vector<int> nums = {3,20,13,2,3,15,24,19,8,13,19,20,21};
    // for (int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    int result =  obj.maxFrequencyScore(nums, k);
    cout << "Frequency of the Most Frequent Element: " << result << endl;
    return 0;
}
