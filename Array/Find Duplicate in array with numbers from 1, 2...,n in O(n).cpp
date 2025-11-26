int Solution::repeatedNumber(const vector<int> &num) {
    int slow = num[0];
    int fast = num[0];
    slow = num[slow];
    fast = num[num[fast]];
    while(slow!=fast){
        slow = num[slow];
        fast = num[num[fast]];
    }
    slow = num[0];
    while(slow != fast){
        slow = num[slow];
        fast = num[fast];
    }
    return slow;
}
