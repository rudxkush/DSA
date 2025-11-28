string Solution::largestNumber(const vector<int> &nums) {
    vector<int> A(nums);
    sort(A.begin(), A.end(), 
    [](int A, int B) {
        string strA = to_string(A);
        string strB = to_string(B);
        return strA + strB > strB + strA;
    });
    if (A[0] == 0) return "0";
    string ans = "";
    for(int num : A) {
        ans += to_string(num);
    }
    return ans;
}
/*

    3   30  34  5   9
    
    9   5   34  3   30
    
*/
