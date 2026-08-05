class Solution {
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &res, vector<int> &vis, vector<int> &pathvis) {
        vis[node] = 1;
        pathvis[node] = 1;
        for (int v : adj[node]) {
            if (!vis[v]) {
                if (dfs(v, adj, res, vis, pathvis) == true) {
                    return true;
                }
            }
            else if (pathvis[v]) {
                return true;
            }
        }
        res.push_back(node);
        pathvis[node] = 0;
        return false;
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& edge) {
        // you need to take bi first to get ai
        // so directed graph basically
        // b -> a ka edge hoga
        // basically apply a dfs 
        // pathvis wala concept
        vector<vector<int>> adj (n);
        for (auto it : edge) adj[it[1]].push_back(it[0]);
        vector<int> vis(n, 0), pathvis(n, 0);
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, res, vis, pathvis) == true) return {};
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};