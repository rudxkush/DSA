int Solution::singleNumber(const vector<int> &A) {
    int ones = 0, twoes = 0;
    for(int num : A) {
        ones = (ones ^ num) & (~twoes); 
        twoes = (twoes ^ num) & (~ones);
    }
    return ones;
}
