class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<bool> tx (2048, false);
        for (int i = 0; i < n; i++) for (int j = i; j < n; j++) tx[nums[i] ^ nums[j]] = true;
        vector<bool> ttx (2048, false);
        for (int i = 0; i < 2048; i++) for (int j = 0; j < n; j++) if (tx[i]) ttx[nums[j] ^ i] = true;
        int cnt = 0;
        for (int i = 0; i < 2048; i++) if (ttx[i]) cnt++;
        return cnt;
    }
};