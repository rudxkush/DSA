int Solution::repeatedNumber(const vector<int> &A) {
    int n = (int) A.size();
    if(n == 0) return 0;

    // using modified Boyer–Moore for > n/3 frequency
    int c1 = 1, c2 = -1;
    int v1 = A[0], v2;

    for(int i = 1; i < n; i++) {
        if(A[i] == v1) {
            c1++;
        } 
        else if(c2 != -1) {
            if(A[i] == v2) c2++;
            else {
                c1--;
                c2--;
            }
        } 
        else {
            v2 = A[i];
            c2 = 1;
        }

        if(c2 == 0) c2 = -1;

        if(c1 == 0) {
            if(c2 != -1) {
                v1 = v2;
                c1 = c2;
                c2 = -1;
            } 
            else if(i < n - 1) {
                v1 = A[i + 1];
                c1 = 1;
                i++;
            } 
            else return -1;
        }
    }

    // verify candidates
    c1 = 0, c2 = 0;
    for(int x : A) {
        if(x == v1) c1++;
        if(c2 != -1 && x == v2) c2++;
    }

    if(c1 > n / 3.0) return v1;
    if(c2 > n / 3.0) return v2;
    return -1;
}
