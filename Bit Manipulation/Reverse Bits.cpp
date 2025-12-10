unsigned int Solution::reverse(unsigned int A) {
    unsigned int ans = 0;
    for (int i = 0; i < 32; i++) { // Loop through all 32 bits
        ans = (ans << 1) | (A & 1); // Shift `ans` left and add the least significant bit of `A`
        A >>= 1; // Shift `A` right to process the next bit
    }
    return ans;
}
