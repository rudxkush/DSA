class Solution {
public:
    void Rearrange(int arr[], int n) {
        int nextNeg = 0;                // where next negative goes
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) {
                int cur = i;
                int val = arr[i];        // temp store negative
                while (cur > nextNeg) {  // shift right
                    arr[cur] = arr[cur-1];
                    cur--;
                }
                arr[nextNeg] = val;
                nextNeg++;
            }
        }
    }
};

