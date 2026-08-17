class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& a) {
        int n = a.size();
        sort(lights.begin(), lights.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int rem = a[i] % period; 
            int wait = 0;
            auto it = upper_bound(lights.begin(), lights.end(), rem);
            if (it == lights.end()) wait = period - rem;
            ans = max(ans, wait);
        }
        return ans;
    }
};