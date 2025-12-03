int Solution::trailingZeroes(int A) {
    // 2 * 5
    // #5 < #2, we would find the number of times A / 5 > 1
    int nTrailingZeroes = 0;
    while(A/5) {
        nTrailingZeroes += A/5;
        A /= 5;
    }
    return nTrailingZeroes;
}
