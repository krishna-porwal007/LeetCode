class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> hash(n);
        for (int i = 0; i < n; i++) hash[i] = i;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i]) {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                    hash[i] = prev;
                }
            }
        }    
        vector<int> ans;
        int index = max_element(dp.begin(), dp.end()) - dp.begin();
        while (hash[index] != index) {
            ans.push_back(nums[index]);
            index = hash[index];
        }    
        ans.push_back(nums[index]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};