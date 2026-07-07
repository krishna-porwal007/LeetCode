class Solution {
    using ll = long long;
public:
    long long sumAndMultiply(int n) {
        int temp = n, sum = 0;
        ll x = 0;
        vector<int> a;
        while (temp) {
            if (temp % 10 != 0) {
                a.push_back(temp % 10);
                sum += (temp % 10);
            }
            temp /= 10;
        }
        int m = a.size();
        for (int i = m - 1; i >= 0; i--) {
            x += a[i];
            x *= 10;
        }
        x /= 10;
        return 1ll * x * sum;
    }
};