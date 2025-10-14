class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        for(int i = 0; i < 32; i++) {
            int bitX1ati = (x >> i) & 1; 
            int bitX2ati = (y >> i) & 1; 

            if(bitX1ati != bitX2ati) {
                count++;
            }
        }
        return count;
    }
};
