string multiplyStringByInt(string &intermediate, int x) {
    int carry  = 0;
    int n = (int) intermediate.size();
    string ans = "";
    
    for(int i = n - 1; i >= 0; --i) {
        int number = intermediate[i] - '0';
        int product = x * number;
        int carry_product_sum = product + carry;
        ans.push_back((carry_product_sum % 10) + '0');
        carry = carry_product_sum / 10;
    }
    
    while(carry) {
        ans.push_back((carry % 10) + '0');
        carry /= 10;
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}

string Solution::solve(int A) {
    string factorial = "1";
    while(A > 1){
        factorial = multiplyStringByInt(factorial, A);
        A = A - 1;
    }
    // long long product = 1;   // <---- overflows ll after 20!
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
    return factorial;
}
