/*
    Author : rudxkush
*/
#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int>& nums) {
    int n = (int) nums.size();
    for (int i = 0; i < n - 1; i++) {
        cout << nums[i] << ", ";
    }
    cout << nums[n - 1] << endl;
}

vector<int> findPerm(int n, long K) {
    vector<int> firstPerm;
    for (int i = 1; i < n; i++) firstPerm.push_back(i);
    firstPerm.push_back(n);

    vector<long long> fact(19);
    fact[0] = fact[1] = 1;
    for(int i = 2; i < 19; i++) fact[i] = fact[i - 1] * i;

    vector<int> kThPerm;
    K--;
    long long upperBound = (long long) 1e18;

    for (int i = n - 1; i >= 0; i--) {
        long long factorial = (i >= 19) ? upperBound : fact[i];
        int index = K / factorial;
        kThPerm.push_back(firstPerm[index]);
        firstPerm.erase(firstPerm.begin() + index);
        K %= factorial;
    }
    return kThPerm;
}

int main() {
    vector<int> Kth = findPerm(4, 17);
    cout << "The asked Kth Permutation is : " << endl;
    printArray(Kth);
    return 0;
}
