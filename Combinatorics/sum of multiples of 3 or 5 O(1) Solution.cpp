#include <iostream>
using namespace std;

long long sumOfMultiples(long long k, long long n) {
    // #multiples of k below n
    long long m = (n - 1) / k;
    // k*1 + k*2 + k*3 + ..... + k*m -> k(1 + 2 + 3 ... + m) -> k * (m * (m + 1) / 2)
    return k * m * (m + 1) / 2;
}

int main() {
    int t;
    cin >> t;
    vector<long long> ans;
    while(t--) {
        int n;
        cin >> n;
        long long sum = sumOfMultiples(3, n) +
                        sumOfMultiples(5, n) - sumOfMultiples(15, n);
        ans.push_back(sum);
    }
    for (int it : ans) {
        cout << it << endl;
    }
    return 0;
}
