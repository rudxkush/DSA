int Solution::colorful(int A) {
    set<int> unique;
    string num = to_string(A);
    int n = num.length();

    for(int i = 0; i < n; i++) {
        int product = 1;
        for(int j = i; j < n; j++) {
            product *= (num[j] - '0');

            if(unique.find(product) != unique.end()) {
                return 0;
            }
            unique.insert(product);
        }
    }
    return 1;
}
