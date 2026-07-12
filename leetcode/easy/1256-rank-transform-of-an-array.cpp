class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> cp = arr;
        int n = arr.size();
        sort(cp.begin(), cp.end());
        unordered_map<int, int> mp;
        int cnt = 0;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && cp[j] == cp[i]) j++;
            cnt++;
            mp[cp[i]] = cnt; 
            i = j;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) ans.push_back(mp[arr[i]]);
        return ans;
    }
};