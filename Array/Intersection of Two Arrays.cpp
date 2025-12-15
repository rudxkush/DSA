class bruteSolution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;
        while(i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            }else {
                if(ans.empty() || ans.back() != nums1[i]) {
                    ans.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};

class optimalSolution {
  public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> seenNums1;
        for(int num : nums1) {
            seenNums1[num]++;
        }
        vector<int> intersects;
        for(int num : nums2) {
            if(seenNums1.find(num) != seenNums1.end() && seenNums1[num] != 0) {
                intersects.push_back(num);
                seenNums1[num] = 0;
            }
        }
        return intersects;
    }
};
