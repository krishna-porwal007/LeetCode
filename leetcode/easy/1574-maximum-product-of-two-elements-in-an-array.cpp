class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = -1, smx = -1, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] >= mx) {
                smx = mx;
                mx = nums[i];
            }
            else if (smx <= nums[i]) smx = nums[i];
        }
        return (mx - 1) * (smx - 1);
    }
};