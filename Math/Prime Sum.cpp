vector<int> Solution::primesum(int A) {
   vector<bool> sieve(A + 1, 1); // Initially all are Primes 
   sieve[0] = sieve[1] = 0; // Non-Primes 
   for(int i = 2; i * i <= A; i++) {
       if(sieve[i] == 1) {
           // Set all the numbers to Non Prime
           // as they are multiple of this Prime Number 
           for(int j = i*i; j <= A; j += i) {
               sieve[j] = 0;
           }
       }
   }
   for(int i = 2; i <= A; i++) {
       if(sieve[i] && sieve[A - i]) {
           return {i, A - i};
       }
   }
   return {};
}
