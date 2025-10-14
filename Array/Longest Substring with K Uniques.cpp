class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int l = 0, n = s.length();
        unordered_map<char, int> currentlyHave;
        int maxLen = INT_MIN;
        for(int r = 0; r < n; r++) {
            currentlyHave[s[r]]++;
            while(currentlyHave.size() > k) {
                currentlyHave[s[l]]--;
                if(currentlyHave[s[l]] == 0) {
                    currentlyHave.erase(s[l]);
                }
                l++;
            }
            if(currentlyHave.size() == k) {
                maxLen = max(maxLen, r-l+1);
            }
        }
        return maxLen == INT_MIN ? -1 : maxLen;
    }
};
