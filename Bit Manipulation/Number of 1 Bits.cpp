class SolutionUsingInbuiltFunction {
public:
    int hammingWeight(int n) {
        int count =  __builtin_popcount(n);
        return count;
    }
};

class Solution {
public:
    int hammingWeight(int n) {
        int count =  0;
        for(int i = 0; i < 32; i++) {
            int setOrNot = (n >> i) & 1;
            count += setOrNot;
        }
        return count;
    }
};
