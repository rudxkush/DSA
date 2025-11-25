/*
  Author : rudxkush
*/
int nCr(int n, int r) {
    if (r > n) return 0;  
    long long answer = 1;
    for(int i = 0; i < r; i++) {
        answer *= (n - i);
        answer /= (i + 1);
    }
    return answer;
}
