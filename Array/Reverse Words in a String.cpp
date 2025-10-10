class Solution {
public:
    string joinWords(vector<string>& words) {
        string result;
        for (int i = 0; i < words.size(); i++) {
            if (i > 0) result += " ";             // Add space between words
            result += words[i];
        }
        return result;
    }
    string reverseWords(string s) {
        vector<string> ans;
        string word = "";

        for (char c : s) {
            if (c != ' ') {
                word += c;            // Keep Building the word
            } else if (!word.empty()) {
                ans.push_back(word);  // Store the completed word
                word = "";            // Reset for the next word
            }
        }
        
        if (!word.empty()) ans.push_back(word);        // Push any leftover
        reverse(ans.begin(), ans.end());               // Reverse words order
        return joinWords(ans);
    }
};
