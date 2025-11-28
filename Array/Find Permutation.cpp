/*
  Author : rudxkush
*/
vector<int> Solution::findPerm(const string A, int B) {
    int n = A.size();
    vector<int> describedPermutation;
    int mini = 1, maxi = B;
    for(int i = 0; i < B; i++) {
        if(A[i] == 'I') {
            describedPermutation.push_back(mini++);
        } else if(A[i] == 'D') {
            describedPermutation.push_back(maxi--);
        }
    }
    describedPermutation.push_back(mini); // describedPermutation.push_back(maxi) would also work
    return describedPermutation;
}
