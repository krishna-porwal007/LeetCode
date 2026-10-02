class Solution {
    void rec (string &cur, int l, int r, vector<string> &ans) {
        if (l > r || l < 0) return;
        if (l + r == 0) {
            ans.push_back(cur);
            return;
        } 
        cur += '(';
        rec(cur, l - 1, r, ans);
        cur.pop_back();
        cur += ')';
        rec(cur, l, r - 1, ans);
        cur.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        rec (cur, n, n, ans);
        return ans;
    }
};