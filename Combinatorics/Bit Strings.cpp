#include <iostream>
#include <math.h>
using namespace std;

long long mod = 1e9 + 7;

long long power(long long num, long long pow) {
    long long ans = 1;
    while(pow > 0) {
        if(pow % 2 == 1) ans = (ans * num) % mod;
        num = (num * num) % mod;
        pow /= 2;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << power(2, n);
    return 0;
}
