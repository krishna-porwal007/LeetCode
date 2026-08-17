class Solution {
public:
    bool stoneGameIX(vector<int>& nums) {
        /*
            so let's say 1 1 3 3 2 2 -> can choose 2a -> 2b -> 1a -> 3b -> 3a -> 1b
            if odd 3's then changes the outcome 
        */
        int n = nums.size();
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 3 == 0) cnt0++;
            else if (nums[i] % 3 == 1) cnt1++;
            else cnt2++;
        }
        cout << cnt0 << " " << cnt1 << " " << cnt2 << endl;
        if (cnt1 == 0 && cnt2 == 0) return false;
        if (cnt1 == cnt2) return cnt0 % 2 == 0;
        // 1 2 1 2 2 -> 2a 2b 1a 2b 1a 
        // 1 2 1 2 2 2 -> 2a 2b 1a 2b 1a 2b 
        if (cnt0 % 2 == 0) return cnt1 > 0 && cnt2 > 0;
        return (abs(cnt1 - cnt2) > 2);
    }
};