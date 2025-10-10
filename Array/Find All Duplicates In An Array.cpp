vector<int> findDuplicates(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        int idx = arr[i] % n; // % n to make it fall within the boundary even after previous increments
        arr[idx] += n;
    }
    vector<int> duplicate;
    for(int i = 0; i < n; i++) {
        int factor = arr[i] / n;
        if(factor >= 2) {
          duplicate.push_back(i);
        }
    }
    return duplicate;
}
