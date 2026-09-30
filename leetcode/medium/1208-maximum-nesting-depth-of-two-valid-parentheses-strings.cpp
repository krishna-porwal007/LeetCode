class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        stack<int> st;
        vector<int> ans(n, 0);
        int cnt = 0;
        bool flag = false; // 0
        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                cnt++;
                ans[i] = cnt % 2;
            }
            else {
                ans[i] = cnt % 2;
                cnt--;
            }
        }
        return ans;
    }
};