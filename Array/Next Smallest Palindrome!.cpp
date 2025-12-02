string Solution::solve(string A) {
    int n = (int) A.size();
    int mid = (n - 1) / 2;

    string ans = A;

    // ---------------------------------------
    // Step 1: Mirror left → right
    // ---------------------------------------
    for (int i = mid; i >= 0; i--) {
        ans[n - 1 - i] = ans[i];
    }

    // ---------------------------------------
    // Step 2: Compare mirrored ans with original A
    // If ans > A, we are done
    // If ans == A, continue
    // If ans < A, we need to increment
    // ---------------------------------------
    for (int i = 0; i < n; i++) {
        if (ans[i] > A[i]) {
            return ans;
        }
        else if (ans[i] < A[i]) {
            break;
        }
    }

    // ---------------------------------------
    // Step 3: Increment the middle and propagate
    // ---------------------------------------
    for (int i = mid; i >= 0; i--) {

        if (ans[i] < '9') {
            ans[i] = (char)(ans[i] + 1);
            ans[n - 1 - i] = ans[i];
            return ans;
        }

        ans[i] = '0';
        ans[n - 1 - i] = '0';
    }

    // ---------------------------------------
    // Step 4: If all digits were '9'
    // Example: "999" → "1001"
    // ---------------------------------------
    ans[0] = '1';
    ans.push_back('1');

    return ans;
}

