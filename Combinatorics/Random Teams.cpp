#include <iostream>
#include <vector>
#include <string>

using namespace std;

//long long factorial(int n) {
//    long long ans = 1;
//    for(int i = 2; i <= n; i++) {
//        ans *= i;
//    }
//    return ans;
//}

void solve(int N, int M) {
    long long n = 1LL * N;
    long long m = M - 1;
    long long largestTeamAfterMSplit = n - m;
    //    long long num = factorial(largestTeamAfterMSplit);
    //    long long deno = factorial(2)  * factorial(largestTeamAfterMSplit - 2);
    //    long long k_max = num / deno;

    long long k_max = largestTeamAfterMSplit * (largestTeamAfterMSplit - 1) / 2;

    long long k = M;
    long long  teamMemCount =  n / k;
//    cout << teamMemCount << endl;
    long long extra = n % k;
//    cout << extra << endl;

    long long k_min =  (M - extra) * (teamMemCount * (teamMemCount - 1) / 2) +
                extra * (teamMemCount + 1) * (teamMemCount) / 2;

    cout << k_min << " " << k_max;
}

int main() {
    int n, m;
    cin >> n >> m;
    solve(n, m);
    return 0;
}
