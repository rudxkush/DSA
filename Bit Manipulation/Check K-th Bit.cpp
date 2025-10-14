class Solution {
  public:
    bool checkKthBit(int n, int k) {
        for(int i = 0; i < k; i++) {
            n >>= 1; 
        }
        return n & 1 ? true : false;
    }
};
