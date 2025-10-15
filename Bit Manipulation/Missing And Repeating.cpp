class mathWorks {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        long long totalSum = 1LL * n * (n + 1)/ 2;
        long long totalSqSum = 1LL * n * (n + 1) * (2LL * n + 1) / 6;
        long long actualSum = 0, actualSqSum = 0;
        for(int it : arr) {
            actualSum += it; 
            actualSqSum += 1LL * it * it; 
        }
        long long diff1 = actualSum - totalSum;  // repeating - missing
        long long diff2 =  actualSqSum - totalSqSum; // repeating^2 - missing^2
        /*
              diff1 / diff2
              repeating - missing / repeating^2 - missing^2
              repeating - missing / repeating^2 - 2*repeating*missing + missing^2
              repeating - missing / (repeating - missing) * (repeating + missing)
              1 / repeating + missing
              that is why we do diff2 / diff1
        */
        long long combined = diff2 / diff1; // repeating + missing
        int repeatingNum = (int) combined + diff1; // repeating + missing + repeating - missing
        repeatingNum = repeatingNum / 2; // 2* repeating / 2 = repeating
        int missingNum = (int) combined - repeatingNum; // repeating - missing - repeating 
        return {repeatingNum, missingNum};
    }
};

