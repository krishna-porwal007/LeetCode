class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) pref[i] = max(pref[i - 1], nums[i]);
        int ans = INT_MIN;
        /*
            j - k >= i;
            pref[j - k] + nums[j]
        */
        for (int i = k; i < n; i++) ans = max(ans, pref[i - k] + nums[i]);
        return ans;
    }
};