class Solution {
public:
    void binaryDescription(string& temp, int i, vector<string>& allSuchStrings,
                           bool adjacentFlag) {
        if (i >= temp.size()) {
            allSuchStrings.push_back(temp);
            return;
        }

        if (adjacentFlag) {
            temp[i] = '0';
            binaryDescription(temp, i + 1, allSuchStrings, false);
        } else {
            temp[i] = '1';
            binaryDescription(temp, i + 1, allSuchStrings, true);
            temp[i] = '0';
            binaryDescription(temp, i + 1, allSuchStrings, false);
        }
    }
    vector<string> validStrings(int n) {
        string temp(n, '0');
        vector<string> allSuchStrings;
        binaryDescription(temp, 0, allSuchStrings, false);
        return allSuchStrings;
    }
};
