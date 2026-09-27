class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> link (n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') st.push(i);
            else if (s[i] == ')') {
                int idx = st.top();
                st.pop();
                link[idx] = i;
                link[i] = idx;
            }
        }
        string ans = "";
        bool front = true;
        int dir = 1;
        for (int i = 0; i < n; i += dir) {
            if (s[i] == '(' || s[i] == ')') {
                i = link[i];
                dir = -dir;
            }
            else ans += s[i];
        }
        return ans;
    }
};