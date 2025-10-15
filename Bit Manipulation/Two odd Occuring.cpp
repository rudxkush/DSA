class Solution {
public:
    vector<int> twoOddNum(vector<int>& arr) {
        int n = arr.size();
        int hasBoth = 0;
        // hasBoth contain both the non repeating elements
        for (int i = 0; i < n; i++) {
            hasBoth ^= arr[i];
        }
        // Get the rightmost set bit (RMB)
        int rightmostSetBit = hasBoth & -hasBoth;
        int bucketOfRMBsame = 0;
        int bucketOfRMBdiff = 0;
        // Divide numbers into two groups based on RMB
        for (int i = 0; i < n; i++) {
            if (arr[i] & rightmostSetBit) // if it is set!
                bucketOfRMBsame ^= arr[i];
            else
                bucketOfRMBdiff ^= arr[i];
        }

        if (bucketOfRMBsame > bucketOfRMBdiff)
            return {bucketOfRMBsame, bucketOfRMBdiff};
        else
            return {bucketOfRMBdiff, bucketOfRMBsame};
    }
};
