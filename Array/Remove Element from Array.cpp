int Solution::removeElement(vector<int> &A, int B) {
    int n = (int) A.size();
    int index = 0;
    for(int i = 0; i < n; i++) {
        if(A[i] == B) {
            continue;
        } else {
            A[index] = A[i];
            index++;
        }
    }
    return index;
}
