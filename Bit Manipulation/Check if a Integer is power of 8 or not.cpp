class Solution {
  public:
    string is_power_of_eight(long long int n) {
         if((n & (n - 1)) == 0) {
            if(((n - 1) % 7) == 0) {
                return "Yes";
            }
        }
        return "No";
    }
};
