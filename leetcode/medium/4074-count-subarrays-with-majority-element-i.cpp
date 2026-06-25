class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int t) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int tc = 0;
            // if (nums[i] == t) tc++;
            for (int j = i; j < n; j++) {
                int len = j - i + 1;
                if (nums[j] == t) tc++;
                if (2 * tc > len) ans++;
            }
        }
        return ans;
    }
};