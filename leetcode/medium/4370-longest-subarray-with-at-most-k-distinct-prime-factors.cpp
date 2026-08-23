class Solution {
    // maximum distinct prime factors upto 1e5 is just 6
    static const int MAXN = 1e5 + 1;
    int spf[MAXN + 2], freq[MAXN + 2];
    int distinct = 0;
    void func () {
        for (int i = 0; i <= MAXN; i++) spf[i] = i;
        for (int i = 2; i * i <= MAXN; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= MAXN; j += i) if (spf[j] == j) spf[j] = i;
            }
        }
    }
    void count(int a) {
        while (a > 1) {
            int x = spf[a];
            if (freq[x] == 0) distinct++;
            freq[x]++;
            while (a % x == 0) a /= x;
        }
    }
    void rem(int a) {
        while (a > 1) {
            int x = spf[a];
            freq[x]--;
            if (freq[x] == 0) distinct--;
            while (a % x == 0) a /= x;
        }
    }
public:
    int longestSubarray(vector<int>& nums, int k) {
        func();
        int n = nums.size();
        int ans = 0;
        int l = 0;
        for (int r = 0; r < n; r++) {
            count(nums[r]);
            while (distinct > k) {
                rem(nums[l]);
                l++;
            }
            ans = max(ans, (r - l + 1));
        }
        return ans;
    }
};