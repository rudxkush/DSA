int Solution::solve(int A) {
    int distance_of_set_bit_from_left = 0;
    for(int i = 0; i < 32; i++) {
        if((A >> i) & 1) {
            return distance_of_set_bit_from_left;
        }
        distance_of_set_bit_from_left++;
    }
    return 0;
}
