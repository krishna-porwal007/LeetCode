class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> c(n);
        for (int i = 1; i < n; i++) c[i] = c[i - 1] + (nums[i] - nums[i - 1] > maxDiff);
        vector<bool> ans;
        for (auto it : queries) ans.push_back(c[it[0]] == c[it[1]]);
        return ans;
    }
};