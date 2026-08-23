class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int x = lower;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (nums[i] < lower) continue;
            if (nums[i] > upper) break;
            while (x < nums[i]) {
                res.push_back(x++);
            }
            x = nums[i] + 1;
        }
        while (x <= upper) res.push_back(x++);
        if (res.empty()) return {};
        vector<vector<int>> ans;
        int m = res.size();
        int start = res[0];
        for (int i = 1; i <= m; i++) {
            if (i == m || res[i] != res[i - 1] + 1) {
                ans.push_back({start, res[i - 1]});
                if (i < m) start = res[i];
            }
        }
        return ans;
    }
};