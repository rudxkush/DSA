#include <iostream>
#include <vector>
using namespace std;

bool hasAtLeastOneZero(vector<int>& nums) {
    int n = (int) nums.size();
    for(int i = 0; i < n; i++) {
        if(nums[i] == 0) {
            return true;
        }
    }
    return false;
}

bool hasAtLeastTwoEvenDigits(vector<int>& nums) {
    int evenDigitCount = 0;
    int n = (int) nums.size();
    for(int i = 0; i < n; i++) {
        if(nums[i]%2 == 0) {
            evenDigitCount++;
        }
    }
    return evenDigitCount >= 2;
}

bool divisibleBy3(vector<int>& nums) {
    int sum_of_digits = 0;
    for(int num : nums) {
        sum_of_digits += num;
    }
    return sum_of_digits%3 == 0;
}

bool divisibleBy60(vector<int>& nums) {
    if (nums.size() == 1 && nums[0] == 0) return 1;
    if (hasAtLeastOneZero(nums)) {
        if (hasAtLeastTwoEvenDigits(nums)) {
            if (divisibleBy3(nums)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    vector<int> nums = {0, 6};
    if (divisibleBy60(nums)) {
        cout << "One of the number’s configurations is indeed divisible by sixty." << endl;
    } else {
        cout << "None of the number’s configurations is divisible by sixty" << endl;
    }
    return 0;
}
