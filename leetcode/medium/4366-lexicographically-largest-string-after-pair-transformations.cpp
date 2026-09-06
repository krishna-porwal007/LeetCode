class Solution {
    string encode (int e) {
        if (e < 26) return string(1, 'a' + e);
        int cnt = 1 << (e - 25);
        return string(cnt, 'z');
    }
    string solve (int n) {
        string ans = "";
        for (int e = 0; e < 31; e++) if (n & (1 << e)) ans += encode(e);
        reverse(ans.begin(), ans.end());
        return ans;
    }
public:
    vector<string> largestString(vector<int>& nums) {
        int n = nums.size();
        vector<string> res;
        for (int i = 0; i < n; i++) {
            string ans = solve(nums[i]);
            res.push_back(ans);
        }
        return res;
    }
};