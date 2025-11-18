/*
  Author : rudxkush
*/
vector<int> Solution::plusOne(vector<int> &a) {
    int n = a.size();
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] < 9) {
            a[i]++;       
            // prune trailing 0s
            int j = 0;
            while(a[j] == 0) {
                j++;
            }
            a.erase(a.begin(), a.begin() + j);
            return a;     // No carry generated, return immediately
        }
        a[i] = 0;
    }
    a.insert(a.begin(), 1);
    return a;
}
