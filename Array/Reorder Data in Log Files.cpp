class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digitLogs, letterLogs, ans;
        // separate the two different type of logs
        for(auto log : logs) {
            int index = log.find(" "); // find the first space delimiter
            if(isdigit(log[index + 1])) {
                digitLogs.push_back(log);
            } else {
                letterLogs.push_back(log);
            }
        }
        // sort(letter logs)
        sort(letterLogs.begin(), letterLogs.end(), 
        [](const string& A, const string& B) {
            int indexA = A.find(" ");
            int indexB = B.find(" ");
            if(A.substr(indexA + 1) == B.substr(indexB + 1)) {
                return A.substr(0, indexA) < B.substr(0, indexB);
            } else {
                return A.substr(indexA + 1) < B.substr(indexB + 1);
            }
        }); 

        // ans = sort(letterLogs) + digitLogs
        ans.insert(ans.begin(), letterLogs.begin(), letterLogs.end());
        ans.insert(ans.end(), digitLogs.begin(), digitLogs.end());
        return ans;
    }
};
