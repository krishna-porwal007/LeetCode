class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end()), mn = *min_element(nums.begin(), nums.end());
        vector<bool> a(mx - mn + 1, false);
        for (int i = 0; i < n; i++) a[nums[i] - mn] = true;
        vector<int> ans;
        for (int i = 0; i < a.size(); i++) if (!a[i]) ans.push_back(i + mn);
        return ans;
    }
};