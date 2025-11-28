int Solution::isPalindrome(int A) {
    string number = "";
    while(A) {
        int unit_digit = A%10;
        number += to_string(unit_digit);
        A /= 10;
    }
    string original = number;
    reverse(number.begin(), number.end());
    return original == number ? 1 : 0;
}
