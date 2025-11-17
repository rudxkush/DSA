int Solution::solve(vector<int> &A, int B) {
    int n = (int) A.size();
    int i = 0;
    int count = 0;
    while(i < n){
        int left = max(0, i - B + 1);
        int right = min(n-1 , i + B - 1);
        bool found = false;
        while(right > left){
            if(A[right] == 1){
                found = true;
                break;
            }
            right--;
        }
        if(found == false){
            return -1;
        }
        count++;
        i = right + B;
    }
    return count;
}
