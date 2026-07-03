class Solution {
    using ll = long long;
    vector<bool> o;
    vector<vector<pair<int, int>>> adj;
    vector<ll> dp;
    ll n, kk, limit;
    ll dfs (int node) {
        if (node == n - 1) return 0;
        if (dp[node] != -1) return dp[node];
        ll best = LLONG_MAX;
        for (auto it : adj[node]) {
            int x = it.first, y = it.second;
            if (y < limit) continue;
            if (x != n - 1 && !o[x]) continue;
            ll nxt = dfs(x);
            if (nxt != LLONG_MAX) best = min(best, nxt + y);
        }
        return dp[node] = best;
    }
    bool func(int e) {
        limit = e;
        dp.assign(n, -1);
        ll mncost = dfs(0);
        return mncost <= kk;
    }
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n = online.size();
        kk = k;
        o = online;
        adj.assign(n, {});
        vector<int> cost;
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            cost.push_back(it[2]);
        }
        sort(cost.begin(), cost.end());
        cost.erase(unique(cost.begin(), cost.end()), cost.end());
        int l = 0, r = cost.size() - 1;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (func(cost[mid])) {
                ans = cost[mid];
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};