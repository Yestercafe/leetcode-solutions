class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0"s;
        string ans;
        while (n != 0) {
            ans.push_back('0' + (n & 1));
            n -= (n & 1);
            n /= -2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

