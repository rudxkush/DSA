/*
    Author : rudxkush
*/
int Solution::isPalindrome(int A) {
    if(A < 0) return 0;
    string number = "";
    while(A) {
        int unit_digit = A%10;
        number += (unit_digit + '0');
        A /= 10;
    }
    string original = number;
    reverse(number.begin(), number.end());
    return original == number ? 1 : 0;
}
