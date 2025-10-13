class Solution {
public:
    int atMost(string& s, int k) {
        unordered_map<char, int> mp; // {char, freq}
        int l = 0, r = 0, count = 0, n = s.length();
        while (r < n) {
            mp[s[r]]++;
            while (mp.size() > k) {
                mp[s[l]]--;
                if (mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }
                l++;
            }
            count += r - l + 1;
            r++;
        }
        return count;
    }
    int numberOfSubstrings(string s) { return atMost(s, 3) - atMost(s, 2); }
};


class SlightlyBetterSolution {
public:
    int numberOfSubstrings(string s) {
        int len = s.length();
        // Track last position of a, b, c
        vector<int> lastPos = {-1, -1, -1};
        int total = 0;

        for (int i = 0; i < len; i++) {
            lastPos[s[i] - 'a'] = i;
            total += 1 + min({lastPos[0], lastPos[1], lastPos[2]});
        }

        return total;
    }
};

/*
    a b c a b c
    0 1 2 3 4 5
    lastPositionA = 3
    lastPositionB = 4
    lastPositionC = 5

    count = 0 + 1 + 2 + 3 + 4 = 10
*/
