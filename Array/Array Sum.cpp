vector<int> Solution::addArrays(vector<int> &A, vector<int> &B) {
    int size_of_A = (int) A.size();
    int size_of_B = (int) B.size();
    int i = size_of_A - 1;
    int j = size_of_B - 1;
    int carry = 0;
    vector<int> sum;
    while(i >= 0 || j >= 0 || carry) {
        int currA = i >= 0 ? A[i] : 0;
        int currB = j >= 0 ? B[j] : 0;
        int currSum = currA + currB + carry;
        sum.push_back(currSum % 10);
        carry = currSum / 10;
        i--; j--;
    }
    reverse(sum.begin(), sum.end());
    return sum;
}


//       1   -> carry
// 1 2 9 8 9
//   3 4 5 6
// ---------
//         5       
