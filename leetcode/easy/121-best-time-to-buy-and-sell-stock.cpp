class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        int mn = a[0], ans = 0;
        for (int i = 1; i < n; i++) {
            ans = max(ans, a[i] - mn);
            if (mn > a[i]) mn = a[i];
        }
        return ans;
    }
};