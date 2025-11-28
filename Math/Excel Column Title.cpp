string Solution::convertToTitle(int A) {
    string ans = "";
    while(A > 0) {
        A--;
        char ch = (A%26) + 'A';
        ans += ch;
        A /= 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
/*

Another Example: A = 267
Step 1: A = 267  
        A-- = 266 // 0 index based
        266 % 26 = 6  ans += 'G'
        A = 266 / 26 = 10

Step 2: A = 10 
        A-- = 9 // 0 index based
        9 % 26 = 9   ans += 'J'
        A = 9 / 26 = 0

reverse("GJ")
Result = "JG"

*/
