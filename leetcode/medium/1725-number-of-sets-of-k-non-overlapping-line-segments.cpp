class Solution {
    using ll = long long;
    static const int MOD = 1e9 + 7;
    static const int MAXN = 2001;
    ll fac[MAXN + 1], ifac[MAXN + 1];
    ll modpow(ll x, ll y) {
        ll res = 1;
        while (y > 0) {
            if (y & 1)
                res = res * x % MOD;
            x = x * x % MOD;
            y >>= 1;
        }
        return res;
    }
    void ic() {
        fac[0] = 1;
        for (int i = 1; i < MAXN + 1; i++) fac[i] = fac[i - 1] * i % MOD;
        ifac[MAXN] = modpow(fac[MAXN], MOD - 2);
        for (int i = MAXN; i >= 1; i--)
            ifac[i - 1] = ifac[i] * i % MOD;
    }
    ll ncr(int n, int r) {
        if (r < 0 || r > n)
            return 0;
        return fac[n] * ifac[r] % MOD * ifac[n - r] % MOD;
    }

public:
    int numberOfSets(int n, int k) {
        ic();
        return ncr(n + k - 1, 2 * k);
    }
};