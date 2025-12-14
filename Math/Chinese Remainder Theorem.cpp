#include <iostream>
#include <vector>
#include <string>
using namespace std;

int naiveCRT(vector<int>& nums, vector<int>& mods) {
    int x = 1;
    int n = nums.size();
    // It is a fact that the unique solution for x mod M is always going to lie <= M
    while (true) {
        int i = 0;
        for (; i < n; i++) {
            if (x % mods[i] != nums[i]) {
                break;
            }
        }
        if (i == n) {
            break;
        }
        x += 1;
    }
    return x;
}

int main() {
    cout << "If m1, m2, ..., mn are pairwise coprime, then there always exists \n"
            "a unique solution for x mod M, where M = m1 × m2 × ... × mn" << endl;
    int n;
    cout << "Enter Size: " << endl;
    cin >> n;
    vector<int> nums(n);
    vector<int> mods(n);
    cout << "Enter Elements Congruent to x: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter Their Respective m's: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> mods[i];
    }
    cout << "Unique Solution of x mod M: " << endl;
    cout << naiveCRT(nums, mods) << endl;
    return 0;
}
