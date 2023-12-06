class Solution {
public:
    string printBin(double num) {
        string ans = "0.";
        while (abs(num) > 1e-7 && ans.size() <= 32) {
            num *= 2;
            if (num >= 1) {
                ans.push_back('1');
                --num;
            } else {
                ans.push_back('0');
            }
        }
        if (ans.back() == '.') {
            ans.push_back('0');
        }

        if (ans.size() <= 32) return ans;
        return "ERROR";
    }
};

