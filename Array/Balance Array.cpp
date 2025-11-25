#include <iostream>
using namespace std;

int countSpecialElements(vector<int>& A) {
    int n = (int) A.size();
    int odd = 0, even = 0;
    int leftOdd[n], rightOdd[n];
    int leftEven[n], rightEven[n];
    for(int i = 0;i < n; i++){
        leftOdd[i] = odd;
        leftEven[i] = even;
        if(i%2 == 0)
            even += A[i];
        else
            odd += A[i];
    }
    odd = 0;
    even = 0;
    for(int i = n-1; i >= 0; i--){
        rightOdd[i] = odd;
        rightEven[i] = even;
        if(i%2 == 0)
            even += A[i];
        else
            odd += A[i];
    }
    // for (int i = 0; i < n; i++) {   cout << leftOdd[i] << " ";  } cout << endl;
    // for (int i = 0; i < n; i++) {   cout << leftEven[i] << " ";  } cout << endl;
    // for (int i = 0; i < n; i++) {   cout << rightEven[i] << " ";  } cout << endl;
    // for (int i = 0; i < n; i++) {   cout << rightOdd[i] << " ";  } cout << endl;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(leftOdd[i] + rightEven[i] == leftEven[i] + rightOdd[i]){
            // cout << leftOdd[i] << ", " << rightEven[i] << " ==  " << leftEven[i] << ", " << rightOdd[i] << endl;
            ans++;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {2, 1, 6, 4};
    countSpecialElements(nums);
    return 0;
}
/*
        nums = [2, 1, 6, 4] 
        leftOdd = { 0 0 1 1 }
        leftEven = { 0 2 2 8 }
        rightEven = { 6 6 0 0 }
        rightOdd = { 5 4 4 0 }

        0, 6 !=  0, 5
        0, 6 !=  2, 4
        0, 6 ==  2, 4
        1, 0 !=  2, 4
        1, 0 !=  8, 0
        2 + 5 = 1 + 8
        8 + 6 = 5 + 4

*/
