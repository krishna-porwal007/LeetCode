class Solution {
    int ans = INT_MAX;
    void dfs(int node, vector<vector<pair<int, int>>> &adj, vector<bool> &vis) {
        vis[node] = true;
        for (auto it : adj[node]) {
            ans = min(ans, it.second);
            if (!vis[it.first]) {
                dfs(it.first, adj, vis);
            }
        } 
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj (n + 1);
        vector<bool> vis (n + 1, false);
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        dfs(1, adj, vis);
        return ans;
    }
};