class Solution {
  const int INT = 1e6;

public:
  int minOperations(string s1, string s2) {
    int n = s1.size();
    int ans = 0;
    if (n == 1) {
      if (s1 == s2)
        return 0;
      else if (s1[0] == '0' && s2[0] == '1')
        return 1;
      else
        return -1;
    }
    for (int i = 0; i < n; i++)
      if (s1[i] == '0' && s2[i] == '1')
        ans++;
    int i = 0;
    while (i < n) {
      if (s1[i] == '1' && s2[i] == '0') {
        int j = i;
        while (j < n && s1[j] == '1' && s2[j] == '0')
          j++;
        ans += (j - i) / 2;
        if ((j - i) % 2)
          ans += 2;
        i = j;
      } else
        i++;
    }
    return ans;
  }
};
