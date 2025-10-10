class divSolution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        int totalProduct = 1;
        unordered_set<int> st; // collect the zero index if any present!
        bool zeroPrs = false;  // flag for having zeroes in an array
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                totalProduct *= nums[i];
            } else {
                zeroPrs = true;
                st.insert(i);
            }
        }
        if (st.size() > 1) {
            return vector<int>(n, 0);
        } else if (zeroPrs) {
            result[*st.begin()] = totalProduct;
        } else {
            for (int i = 0; i < n; i++) {
                int productAtIndexI = totalProduct / nums[i];
                result[i] = productAtIndexI;
            }
        }
        return result;
    }
};

class nonDivSolution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixProduct(n, 1);
        vector<int> ans(n, 1);
        for (int i = 1; i < n; i++) {
            prefixProduct[i] = prefixProduct[i - 1] * nums[i - 1];
        }
        int suffixProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = prefixProduct[i] * suffixProduct;
            suffixProduct *= nums[i];
        }
        return ans;
    }
};
