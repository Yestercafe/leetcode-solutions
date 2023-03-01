class Solution {
    using i64 = long long;
    static constexpr i64 D = 10000000LL;
public:
    string printBin(double num) {
        set<pair<i64, i64>> s;
        pair<i64, i64> f {static_cast<i64>(num * 2 * D), D};
        string ans = "0.";
        while (f.first != 0) {
            if (s.find(f) != s.end()) return "ERROR";
            s.insert(f);
            if (f.first >= f.second) {
                ans.push_back('1');
                f.first -= f.second;
            } else {
                ans.push_back('0');
            }
            f.first *= 2;
        }
        return ans;
    }
};

