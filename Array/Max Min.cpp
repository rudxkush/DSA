/*
  Author : rudxkush
*/
int Solution::solve(vector<int> &A) {
     int maxElement = INT_MIN;
     int minElement = INT_MAX;
     for(int num : A) {
          maxElement = max(maxElement, num);
          minElement = min(minElement, num);
     }
    return maxElement + minElement;
}

// In the case interviewer futher ask you to optimise the code such that it makes minimum number of comparisons, 
// Go for recursive solution (divide and conquer approach).

pair<int, int> findMinMax(vector<int>& A, int left, int right) {
    if(left > right) {
        return {INT_MIN, INT_MAX};
    }
    if(left == right) {
        return {A[left], A[left]};
    }
    
    int mid = left + (right - left) / 2;
    pair<int, int> processedLeft = findMinMax(A, left, mid);
    pair<int, int> processedRight = findMinMax(A, mid + 1, right);
    
    int minElement = processedRight.second > processedLeft.second ? processedLeft.second : processedRight.second;
    int maxElement = processedRight.first < processedLeft.first ? processedLeft.first : processedRight.first;
    
    return {maxElement, minElement};
}

int Solution::solve(vector<int> &A) {
    int n = (int) A.size();
    pair<int,int> minMaxPair = findMinMax(A, 0, n-1); // 0, 1, ..... n-1
    return minMaxPair.first + minMaxPair.second; // {max, min}
}
