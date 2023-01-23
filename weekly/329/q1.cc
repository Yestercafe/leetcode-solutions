class Solution {
public:
    int alternateDigitSum(int n) {
        auto s = to_string(n);
        int sign = 1;
        int ans = 0;
        for (auto c : s) {
            ans += sign * (c - '0');
            sign = -sign;
        }
        return ans;
    }
};

