class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int m = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < m; i++) mp[nums[i]].push_back(i);
        int ans = 0;
        for (auto it : mp) {
            int n = it.second.size();
            if (n != 3) continue;
            for (int i = 1; i < n - 1; i++) {
                cout << it.second[i] << " ";
                if (it.second[i] - it.second[i - 1] == it.second[i + 1] - it.second[i]) ans++;
            }
        }
        return ans;
    }
};