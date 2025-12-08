double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int n = A.size(), m = B.size();
    
    // Ensure A is smaller
    if(n > m) return findMedianSortedArrays(B, A);
    
    int low = 0, high = n;
    int total = n + m;
    
    while(low <= high) {
        int cutA = (low + high) / 2;
        int cutB = (total + 1)/2 - cutA;
        
        int leftA  = (cutA == 0 ? INT_MIN : A[cutA - 1]);
        int rightA = (cutA == n ? INT_MAX : A[cutA]);
        
        int leftB  = (cutB == 0 ? INT_MIN : B[cutB - 1]);
        int rightB = (cutB == m ? INT_MAX : B[cutB]);
        
        if(leftA <= rightB && leftB <= rightA) {
            // Correct partition found
            if(total % 2 == 0) {
                return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
            } else {
                return double(max(leftA, leftB));
            }
        }
        
        else if(leftA > rightB) {
            // Move left
            high = cutA - 1;
        }
        else {
            // Move right
            low = cutA + 1;
        }
    }
    
    return 0.0; // fallback
}
