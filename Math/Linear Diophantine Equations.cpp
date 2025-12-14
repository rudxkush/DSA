/*
  Author: rudxkush
*/
class Solution {
  public:
    int greatestCommonDiv(int a, int b) {
        while(b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
    int isPossible(int A, int B, int C) {
        int G = greatestCommonDiv(A, B);
        if(C%G == 0) {
            return true;
        } else {
            return false;
        }
    }
};
