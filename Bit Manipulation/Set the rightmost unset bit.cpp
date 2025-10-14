class Solution {
  public:
    int setBit(int n) {
        for (int i = 0; i < 32; i++) {
            if (((n >> i) & 1) == 0) {  
                n |= (1 << i);        
                break;
            }
        }
        return n;
    }
};
