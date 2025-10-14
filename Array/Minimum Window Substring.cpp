class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length())
            return "";

        unordered_map<char, int> targetMap;
        for (auto ch : t)
            targetMap[ch]++;

        unordered_map<char, int> ongoingMap;
        int have = 0, need = targetMap.size();
        int l = 0, startIndex = 0;
        int minLen = INT_MAX;
        int n = s.length();

        for (int r = 0; r < n; r++) {
            char endChar = s[r];
            if (targetMap.find(endChar) != targetMap.end()) {
                ongoingMap[endChar]++;
                if (ongoingMap[endChar] == targetMap[endChar])
                    have++; // this char is now fully satisfied
            }

            while (have == need) {
                int len = r - l + 1;
                if (len < minLen) {
                    minLen = len;
                    startIndex = l;
                }

                char startChar = s[l];
                if (targetMap.find(startChar) != targetMap.end()) {
                    ongoingMap[startChar]--;
                    if (ongoingMap[startChar] < targetMap[startChar])
                        have--; // we lost a fully satisfied char
                }
                l++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(startIndex, minLen);
    }
};
