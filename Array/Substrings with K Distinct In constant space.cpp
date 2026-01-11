class Solution {
  public:
    int atMost(string& s, int k) {
        int freq[26] = {0};
        int countDistinct = 0;
        int n = s.length(); 
        int i = 0;
        int count = 0;
        for(int j = 0; j < n; j++) {
            if (freq[s[j] - 'a'] == 0)
                countDistinct++;
            freq[s[j] - 'a']++;
            while(countDistinct > k) {
                freq[s[i] - 'a']--;
                if(freq[s[i] - 'a'] == 0) {
                    countDistinct -= 1;
                }
                i++;
            }
            count += j - i + 1;
        }
        return count;
    }
    int countSubstr(string& s, int k) {
        return atMost(s, k) - atMost(s, k - 1);
    }
};
