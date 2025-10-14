int computeXor(int n) {
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    ans ^= i;
  }
  return ans;
}

int computeXor(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0; // n % 4 == 3
}

/*
    0  0000 -> 0
    1  0000 ^ 0001 = 0001 -> 1  (n % 4 == 1)
    2  0001 ^ 0010 = 0011 -> 3  (n % 4 == 2)
    3  0011 ^ 0011 = 0000 -> 0  (n % 4 == 3)
    4  0000 ^ 0100 = 0100 -> 4  (n % 4 == 0)
*/
