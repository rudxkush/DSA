int get_rev(int num){  // reversing the binary representation of a given number.
    int ans = 0;
    while(num){
        int lb = num & 1;  // lower bit
        ans |= lb;
        ans <<= 1;
        num >>= 1;
    }
    ans >>=  1; // last extra shifted bit we are removing
    return ans;
}

int Solution::solve(int A) {
    // first look at the patterns. find number of palindromes for a fixed length.
    // for len == 1 and 2 only 1 palindromes.  1 and 11.
    // for len == 3 and 4 only 2 palindromes. 101 and 111 . 1001 and 111
    // for len == 5 and 6 only 4 palindromes. 10001 10101 11011 11111. 100001 101101 110011 111111.
    // so as you can see the number of binary palindromes for a given length is 2^(len-1)/2.
   
    int len = 1;
    int cnt = 1;
    int n = A;
   
    // lets take a example for this case say A == 29.
    while(cnt < A){
        len++;
        int no_of_palindromes = (1 << (len-1)/2);  // number of palindromes of length == len.
        cnt += no_of_palindromes;
    }
   
    // so cnt will stop at 8 which means the 29th binary palindrome is in group 8 (ie has length 8).
    cnt -= (1 << (len-1)/2); // find how many palindromes are there till prev group.
   
    //find the offset
    int offset = n - cnt -1; // -1 because n - cnt is counting from the end of last group but we want
    // to count from the start of this group.
    // for 29 the offser we will get is 6
   
    // now we know our numbers length == len and offset;
   
    // for binary palindrome if we take care of the bits in the first half second half is just reverse of that.
    // and anyhow first bit is always one. so we shift the offset by len/2 dist because we want the right half
    // to be empty
   
    int ans = (1 << (len-1)); // 10000000 . offset << len/2 == 1100000
    ans |= offset << (len)/2 ;//1110 0000. now just reverse the first half and or it will ans.
   
    int rev = get_rev(ans);  // 1110 0000  or 0000 0111
    ans |= rev; // 1110 0111
   
    return ans;
}
