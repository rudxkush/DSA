int atmost(vector<int>& A, int k) {
    unordered_map<int, int> freqMp;
    int n = (int) A.size();
    int i = 0, j = 0, count = 0;
    while(j < n) {
        freqMp[A[j]]++;
        while(freqMp.size() > k && i <= j) {
            freqMp[A[i]]--;
            if(freqMp[A[i]] == 0) {
                freqMp.erase(A[i]);
            }
            i++;
        }
        count += j - i + 1;
        j++;
    }
    return count;
}
int Solution::solve(vector<int> &A, int B) {
    return atmost(A, B) - atmost(A, B - 1);
}
