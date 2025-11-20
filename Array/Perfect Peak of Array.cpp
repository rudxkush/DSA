/*
    Author : rudxkush
*/
int Solution::perfectPeak(vector<int> &A) {
    int n = (int) A.size();
    int smallest = INT_MAX;
    vector<int> suffix(n);
    for(int i = n - 1; i >= 0; i--) {
        smallest = min(smallest, A[i]);
        suffix[i] = smallest;
    } 
    // maintain greater as you go
    int greater = A[0];
    for(int i = 1; i < n - 1; i++) {
        if(greater < A[i]  and  A[i] < suffix[i + 1]) {
            return 1;
        }
        greater = max(greater, A[i]);
    }
    return 0;
}

/*
    Select(rand(A)) 
    such that,
        - All elements on right are strictly greater
        - All elements on left are strictly smaller 

    maintain smallest number on it's right
    maintain greater number on it's left
    
    1, 1, 3, 3, 6, 7, 7, 7, 9
    
    5, 5, 5, 5, 6, 8, 10, 10, 10
    
    leftMax[i] < A[i]  and  A[i] < rightMin[i]
*/
