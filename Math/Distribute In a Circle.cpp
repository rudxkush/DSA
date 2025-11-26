int Solution::solve(int A, int B, int C) {
    int start = C;
    int number_of_boxes = A;
    int positions = B;
    int distanceCovered = (start + number_of_boxes - 1) % positions;
    return distanceCovered;
}
