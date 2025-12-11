const int mod = 1e9+7;
int Solution::cntBits(vector<int> &nums) {
    int res = 0;
    for(int i = 31; i >= 0; i--) {
        long long ones = 0, zeroes = 0;
        for(int num : nums) {
            if((num >> i) & 1) {
                ones += 1;
            } else {
                zeroes += 1;
            }
        }
        res = (res + (2LL * (ones * zeroes) % mod) % mod) % mod;
    }
    return res;
}
/*
  nums = {1, 3, 5}
  0001
  0011
  0101
  
  3->1's , 0->1's , contribution = 0
  1->1's , 2->0's , contribution = 2*(2*1)
  1->1's , 2->0's , contribution = 2*(2*1)
*/
