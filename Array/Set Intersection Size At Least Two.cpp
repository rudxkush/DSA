class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = (int)intervals.size();

        // sort the intervals by end (and if same end, by start)
        // so that picking from the right gives max overlap later
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& A, const vector<int>& B) {
                 if (A[1] != B[1])
                     return A[1] < B[1];
                 return A[0] < B[0];
             });

        // take the last 2 points of the very first interval
        // because taking from the right gives the smallest
        // possible containing set
        vector<int> containingSet;
        containingSet.push_back(intervals[0][1] - 1);
        containingSet.push_back(intervals[0][1]);

        for (int i = 1; i < n; i++) {
            int size = containingSet.size();
            int last = containingSet[size - 1];
            int secondLast = containingSet[size - 2];
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            // case 1: no overlap
            if (currStart > last) {
                containingSet.push_back(currEnd - 1);
                containingSet.push_back(currEnd);
            }
            // case 2: touching by 1
            else if (currStart == last) {
                containingSet.push_back(currEnd);
            }
            // case 3: overlap by 1 but not fully covered
            else if (currStart > secondLast) {
                containingSet.push_back(currEnd);
            }
            // case 4: skip interval
        }

        return (int)containingSet.size();
    }
};
