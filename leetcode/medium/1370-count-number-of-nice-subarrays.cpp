class Solution {
    int func(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), cnt = 0, ans = 0;
        while (r < n) {
            if (nums[r] % 2 == 1) cnt++;
            while (cnt > k) {
                if (nums[l] % 2 == 1) cnt--;
                l++;
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // i should start reading questions properly
        // atmost type problem;
        return func(nums, k) - func(nums, k - 1);
    }
};