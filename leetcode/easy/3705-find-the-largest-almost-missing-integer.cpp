class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        if (k == 1) {
            int ans = -1;
            for (auto it : mp) {
                if (it.second == 1) {
                    ans = max(ans, it.first);
                }
            }
            return ans;
        }
        else if (k == n) {
            int mx = *max_element(nums.begin(), nums.end());
            return mx;
        }
        else {
            if (mp[nums[0]] == 1 && mp[nums[n - 1]] == 1) {
                int l = max(nums[0], nums[n - 1]);
                return l;
            }
            else if (mp[nums[0]] == 1) return nums[0];
            else if (mp[nums[n - 1]] == 1) return nums[n - 1];
        }
        return -1;
    }
};