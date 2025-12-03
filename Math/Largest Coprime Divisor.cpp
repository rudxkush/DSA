int GCD(int a, int b) {
    while(b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
int Solution::cpFact(int A, int B) {
    int G = GCD(A, B);
    int newA = A;
    while(G > 1) {
        newA = A/G;
        A = newA;
        G = GCD(A, B);
    }
    return newA;
}
