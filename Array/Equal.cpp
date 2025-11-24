#include <bits/stdc++.h>
using namespace std;

vector<int> Solution::equal(vector<int> &nums) {
    unordered_map<int, pair<int, int>> doubletSumMap; // {sum, {i, j}}
    int n = (int) nums.size();
    vector<int> validTuple = {n, n, n, n};
        
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int sum = nums[i] + nums[j];
            if(doubletSumMap.find(sum) == doubletSumMap.end()) {
                doubletSumMap[sum] = {i, j};
            } else {
                auto position = doubletSumMap[sum];
                int prevI = position.first;
                int prevJ = position.second;
                int currentK = i, currentL = j;
                vector<int> candidate = {prevI, prevJ, currentK, currentL};
                // is the tuple valid?
                if(prevI < prevJ &&        // i < j
                   currentK < currentL &&  // k < l
                   prevI < currentK &&     // i < k
                   prevJ != currentK &&    // j != k
                   prevJ != currentL) {    // j != l 
                    // is the tuple lexicographically smallest?
                    if(validTuple > candidate) {
                        validTuple = candidate;
                    }      
                }
            }
        }
    }
    
    return (validTuple[0] == n) ? vector<int>() : validTuple;
}
/*
        3, 4, 7, 1, 2, 9, 8
        
        {i, j, k, l}
        A[i] + A[j] = A[k] + A[l]
        i < j, k < l
        i < k
        j != k, l
        
        A[0] + A[2] = A[3] + A[5]
        3 + 7 = 1 + 9
        10 = 10 ----> valid tuples of indices that are lexicographically smallest

*/
