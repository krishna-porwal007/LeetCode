class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        vector<int> e(n + 1, 0), o(n + 1, 0);
        for (int i = 0; i < n; i++) {
            o[i + 1] = o[i] + (nums[i] % 2 == 1);
            e[i + 1] = e[i] + (nums[i] % 2 == 0);
        }
        int cnt = 0;
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                int E = e[r + 1] - e[l];
                int O = o[r + 1] - o[l];
                if (1LL * E * b <= 1LL * O * a) cnt++;
            }
        }
        return cnt;
    }
};