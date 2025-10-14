class Solution {
public:
    bool isPowerOfFour(int n) {
        /*
            n = 4^x
            taking log base 2 on both side
            logn base e = x * log4 base e
            x = logn base e / log4 base e
            and then we check whether x on substituting in the exp 4^x gives n
        */
        if(n <= 0) return false;
        int x = log(n) / log(4);
        if(pow(4, x) == n) {
            return true;
        }
        return false;
    }
};

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        return ((n & (n-1)) == 0) && (((n-1) % 3) == 0); // it should be a power of 2 and n - 1 is divisible by 3
    }
};
