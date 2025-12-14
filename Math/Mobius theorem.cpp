#include <iostream>
using namespace std;

bool isPrime(int value) {
    if (value < 2) return false;
    for (int divisor = 2; divisor * divisor <= value; divisor++) {
        if (value % divisor == 0) return false;
    }
    return true;
}

int mobius(int number) {
    if (number == 1) return 1;

    int distinctPrimeCount = 0;

    for (int factor = 2; factor <= number; factor++) {
        if (number % factor == 0 && isPrime(factor)) {

            // square-free check
            if (number % (factor * factor) == 0)
                return 0;

            distinctPrimeCount++;
        }
    }

    return (distinctPrimeCount % 2 == 0) ? 1 : -1;
}

int main() {
    cout << mobius(17) << endl;
    cout << mobius(25) << endl;
    cout << mobius(6) << endl;
}
