#include <iostream>
using namespace std;

int reverse(int n) {
    int ans = 0;
    while (n > 0) {
        ans |= (n & 1);
        ans <<= 1;
        n >>= 1;
    }
    ans >>= 1;
    return ans;
}

int solve(int Ath) {
    int len = 0;
    int counter = 1;

    // Find length of the Ath palindrome
    while (counter <= Ath) {
        len++;
        int configurableBits = 1 << ((len - 1) / 2);
        counter += configurableBits;
    }

    int configurableBits = 1 << ((len - 1) / 2);
    int start = counter - configurableBits;
    int offset = Ath - start;

    // Build left half
    int AthNumber = 1 << (len - 1);
    AthNumber |= (offset << (len / 2));

    // Mirror to form palindrome
    int numToRev = AthNumber >> (len / 2);
    int mirrorFirstHalf = reverse(numToRev);
    AthNumber |= mirrorFirstHalf;
    return AthNumber;
}


int main() {
    cout << solve(29);
    cout << endl;
    return 0;
}
