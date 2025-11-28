/*
  Author : rudxkush
*/
vector<int> Solution::findOccurences(vector<int> &A) {
    int n = A.size();
    sort(A.begin(), A.end());
    vector<int> ans;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(i < n - 1 && A[i] == A[i + 1]) {
            sum += 1;
        } else {
            sum += 1;
            ans.push_back(sum);
            sum = 0;
        }
    }
    return ans;
}
