class Solution {
public:
    bool isPalindromic(string s) {
        int n = s.size();
        string res;
        for (char c : s) {
            string l = bitset<8>(static_cast<unsigned char>(c)).to_string();
            res += l;
        }
        n *= 8;
        int l = 0, r = n - 1;
        while (l < r) {
            if (res[l] != res[r]) return false;
            else {
                l++;
                r--;
            }
        }
        return true;
    }
};