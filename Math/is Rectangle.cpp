int Solution::solve(int A, int B, int C, int D) {
    return ((A == B && C == D && (A < C || A > C))
          || A == C && B == D && (A < B || A > B)
          || A == D && B == C && (A < B || A > B));
}
