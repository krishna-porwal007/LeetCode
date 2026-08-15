class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        bool f = false;
        for (int i = 0; i < n; i++) {
            x ^= nums[i];
            if (!f && nums[i] != 0) f = true;
        }
        if (x != 0) return n;
        else if (f) return n - 1;
        return 0;
    }
};