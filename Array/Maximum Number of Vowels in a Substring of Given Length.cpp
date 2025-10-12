class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a','e','i','o','u'};
        int n = s.length();
        int maxVowels = INT_MIN;
        int count = 0;
        for(int i = 0; i < k; i++) {
            if(vowels.find(s[i]) != vowels.end()) {
                count++;
            }
        }
        maxVowels = max(maxVowels, count);
        for(int i = k; i < n; i++) {
            int removeAVowel = 1;
            int addAVowel = 0;
            if(vowels.find(s[i - k]) == vowels.end()) {
                removeAVowel = 0;
            }
            if(vowels.find(s[i]) != vowels.end()) {
                addAVowel = 1;
            }
            count = count + addAVowel - removeAVowel;
            maxVowels = max(maxVowels, count);
        }
        return maxVowels;
    }
};
