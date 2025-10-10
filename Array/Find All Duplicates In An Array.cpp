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
/*
    0  1  2  3  4  5  6
    1, 2, 3, 6, 3, 6, 1, n = 7
    i
       idx
    1, 9, 3, 6, 3, 6, 1, n = 7
       i 
          idx
    1, 9, 10, 6, 3, 6, 1, n = 7
           i
              idx
    1, 9, 10, 13, 3, 6, 1, n = 7
              i
                       idx
    1, 9, 10, 20, 3, 6, 1, n = 7
                  i
             idx
    1, 9, 10, 20, 3, 6, 8, n = 7
                     i
                       idx
    1, 16, 10, 20, 3, 6, 14, n = 7
                         i
       idx
   
    8, 9,    10, 20,  3, 6, 14, n = 7
    1  >=2   1   >=2  1  1  >=2
*/
