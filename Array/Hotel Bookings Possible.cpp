bool Solution::hotel(vector<int>& arrive, vector<int>& depart, int K) {
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    int n = arrive.size();
    int i = 0;
    int j = 0;
    int room = 0;
    while (i < n && j < n) {
        if (arrive[i] <= depart[j]) {
            room++;
            if (room > K)
                return false;
            i++;
        } else {
            room--;
            j++;
        }
    }
    return true;
}
