/*
  Author : rudxkush
*/
vector<int> Solution::getRow(int A) {
    vector<int> pascalKthRow(A + 1);
    pascalKthRow[0] = 1;
    pascalKthRow[A] = 1;
    long long temp = 1;
    for(int i = 1; i < A; i++) {
        temp *= (A - i + 1);
        temp /= i;
        pascalKthRow[i] = temp; // 3
    }
    return pascalKthRow;
}
/*
         1
        1 1
       1 2 1
      1 3 3 1 <------ A = 3
     1 4 6 4 1 <----- A = 4
    pascalKthRow[0] = 1
    pascalKthRow[1] = 1

    1 4  6  4 1 <----- A = 4
   1 5 10 10 5 1<----- A = 5
   
   4 * 1          4 * ??                        4 * 1
   (r-c+1)/c      4*(r-c+1)/c = 4 * 3 / 2 = 6
   
   5 * 1                 5 * 2             5 * 2     5 * 1
   1*(row-col+1)/col     prevComputed*(row - col + 1)/col
  
  
  int nCr(int n, int r) {
      if (r > n) return 0;  
      long long answer = 1;
      for(int i = 0; i < r; i++) {
          answer *= (n - i);
          answer /= (i + 1);
      }
      return answer;
  }
*/ 
