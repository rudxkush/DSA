string multiplyStringByInt(const string &num, int x) {
    int carry = 0;
    string result = "";

    // multiply from right to left
    for (int i = num.size() - 1; i >= 0; i--) {
        int digit = num[i] - '0';
        int prod = digit * x + carry;
        result += char((prod % 10) + '0');
        carry = prod / 10;
    }

    // leftover carry
    while (carry) {
        result += char((carry % 10) + '0');
        carry /= 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

string Solution::solve(int A) {
    string result = "1";
    while(A > 1){
        result = multiplyStringByInt(result, A);
        A = A - 1;
    }
    // long long product = 1; // overflows after 20 or 21
    // while(A > 1) {
    //     product *= A;
    //     A = A - 1; 
    // }
    // string ans = "";
    // while(product) {
    //     int lastDigit = product%10;
    //     ans += to_string(lastDigit);
    //     product /= 10;
    // }
    // reverse(ans.begin(), ans.end());
    // return ans;
    return result;
}
