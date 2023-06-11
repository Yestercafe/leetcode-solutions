class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.length();
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            for (int d = 1; i + d - 1 < n; ++d) {
                string ss = s.substr(i, d);
                ss.erase(unique(ss.begin(), ss.end()), ss.end());
                if (ss.length() + 1 == d || ss.length() == d) {
                    ans = max(ans, d);
                }
            }
        }
        return ans;
    }
};

