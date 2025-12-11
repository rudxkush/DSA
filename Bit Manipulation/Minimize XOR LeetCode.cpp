class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ans = 0;
        int setBitsOfNum2 = __builtin_popcount(num2);

        // set bits in num2 where num1 has set bits from MSB to LSB -> minimise XOR
        for (int i = 31; i >= 0; i--) {
            if ((num1 >> i) & 1 && setBitsOfNum2 > 0) {
                ans |= (1 << i);
                setBitsOfNum2--;
            }
        }

        // set remaining bits of num2 at smallest unset positions (setBitsOfNum2 > 0)
        for (int i = 0; i <= 31 && setBitsOfNum2 > 0; i++) {
            if (((ans >> i) & 1) == 0) {
                ans |= (1 << i);
                setBitsOfNum2--;
            }
        }

        return ans;
    }
};
