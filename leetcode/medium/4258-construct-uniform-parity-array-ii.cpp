class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool odd = false, even = true;
        int mn = INT_MAX;
        for (int i = 0; i < nums1.size(); i++) {
            mn = min(mn, nums1[i]);
            if (nums1[i] % 2) even = false;
        }
        return even || (mn % 2 != 0);
    }
};