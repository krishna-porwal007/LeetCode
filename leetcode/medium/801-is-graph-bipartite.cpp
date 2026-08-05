class Solution {
private:
    bool dfs(int node, int c, vector<int> &color, vector<vector<int>> &graph) {
        color[node] = c;
        for (int v : graph[node]) {
            if (color[v] == -1) {
                if (c == 1) {
                    if (dfs(v, 0, color, graph) == false) {
                        return false;
                    }
                }
                else if (c == 0) {
                    if (dfs(v, 1, color, graph) == false) {
                        return false;
                    }
                }
            }
            else if (color[v] == c) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (dfs(i, 0, color, graph) == false) return false;
            }
        }
        return true;
    }
};