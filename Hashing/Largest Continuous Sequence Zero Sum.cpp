vector<int> bruteSolution::lszero(vector<int> &A) {
    int maxLength = 0;
    int n = (int) A.size();
    int bestLeft = -1;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += A[j];
            if(sum == 0) {
                int length = j - i + 1;
                if(maxLength < length) {
                    bestLeft = i;
                    maxLength = length;
                }
            }
        }
    }
    
    if(bestLeft == -1) return vector<int> {};
    vector<int> ans;
    for(int i = bestLeft; i < bestLeft + maxLength; i++) {
        ans.push_back(A[i]);
    }
    
    return ans;
}

vector<int> optimalSolution::lszero(vector<int> &A) {
    int n = (int) nums.size();
    unordered_map<int, int> mp; // {prefix sum till i, i}
    int left = -1;
    int maxLength = 0;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += nums[i];
        if(sum == 0) {   // sum of element of the sub array starting from 0 till i is zero
            int length = i + 1;
            if(maxLength < length) {
                maxLength = length;
                left = 0; 
            }
        } else {
            if(mp.find(sum) != mp.end()) {   // this means that their is a window that has the sum zero
                int j = mp[sum];
                if(maxLength < i - j) {
                    maxLength = i - j;
                    left = j + 1;
                }
            } else {
                mp[sum] = i; 
            }
        }
    }
    if(left == -1) return vector<int> {};
    vector<int> ans;
    for(int i = left; i < left + maxLength; i++) {
        ans.push_back(nums[i]);
    }
    return ans;
}
