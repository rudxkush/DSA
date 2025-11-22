/*
  Author: rudxkush
*/
#include <iostream>
#include <vector>
#include <algorithm> // for min
#include <climits>   // for INT_MAX
using namespace std;
class Solution {
public:
    void buildSegmentTree(vector<int>& nums, vector<int>& segmentTree, int low, int high, int position) {
        if (low > high) {
            return ;
        }
        if (low == high) {
            segmentTree[position] = nums[low];
            return ;
        }
        int mid = low + (high - low) / 2;
        buildSegmentTree(nums, segmentTree, low, mid, 2*position + 1); // left subtree
        buildSegmentTree(nums, segmentTree, mid + 1, high, 2*position + 2); // right subtree

        segmentTree[position] = min(segmentTree[2*position + 1], segmentTree[2*position + 2]); // parent = min(leftChild, rightChild)
    }
    int rangeMinQuery(vector<int>& segmentTree, int qlow, int qhigh, int low, int high, int position) {
        // Either we would have a partial overlap
        // (or) we would have a total overlap
        // (or) we would have a no overlap
        if(qlow <= low && qhigh >= high){
            return segmentTree[position];
        }
        if (qlow > high || qhigh < low) {
            // no overlap
            return INT_MAX;
        }
        int mid = low + (high - low) / 2;
        int left = rangeMinQuery(segmentTree, qlow, qhigh, low, mid, 2*position + 1); // left subtree
        int right = rangeMinQuery(segmentTree, qlow, qhigh, mid + 1, high, 2*position + 2); // right subtree
        return min(left, right);
    }
    void minimumRangeQuery(vector<int>& nums, vector<vector<int>>& queries) {
        int n = (int) nums.size();
        int segmentTreeSize = 4 * n;
        vector<int> segmentTree(segmentTreeSize);

        // construct the segment tree
        buildSegmentTree(nums, segmentTree, 0, n - 1, 0);

        // query in (logn)
        for (auto query : queries) {
            int low = query[0];
            int high = query[1];
            int result = rangeMinQuery(segmentTree, low, high, 0, n - 1, 0);
            cout << "Min in range [" << low << ", " << high << "] is: " << result << endl;
        }
    }
};

int main() {
    vector<int> nums = {-1, 0, 2, 3, 4, 35, 99};
    vector<vector<int>> queries = {{0, 3},{4, 6}};
    Solution obj;
    obj.minimumRangeQuery(nums, queries);
    return 0;
}
