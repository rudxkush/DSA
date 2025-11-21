/*
    Author : rudxkush
*/
int Solution::solve(int A, int B) {
    // Count top left squares
    int topLeft = min(A, B) - 1;

    // Count bottom right squares
    int bottomRight = 8 - max(A, B);

    // Count top right squares
    int topRight = min(A, 9 - B) - 1;

    // Count bottom left squares
    int bottomLeft = 8 - max(A, 9 - B);

    // Return total count
    return (topLeft + topRight + bottomRight + bottomLeft);
}


