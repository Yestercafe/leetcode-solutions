class Solution {
public:
    int maxScoreWords(vector<string>& ws, vector<char>& lc_, vector<int>& score) {
        int n = ws.size();
        vector wc(n, vector(26, 0));
        for (int i = 0; i < n; ++i) {
            for (auto ch : ws[i]) {
                wc[i][ch - 'a']++;
            }
        }
        vector lc(26, 0);
        for (auto ch : lc_) lc[ch - 'a']++;
        function<int(int, int)> dfs = [&](int i, int sum) {
            if (i == n) {
                return sum;
            }
            auto& sc = wc[i];
            bool suf = true;
            for (int ii = 0; ii < 26; ++ii) {
                if (lc[ii] < sc[ii]) {
                    suf = false;
                    break;
                }
            }
            
            int ans = 0;
            if (suf) {
                int more = 0;
                for (int ii = 0; ii < 26; ++ii) {
                    lc[ii] -= sc[ii];
                    more += sc[ii] * score[ii];
                }
                ans = dfs(i + 1, sum + more);
                for (int ii = 0; ii < 26; ++ii) {
                    lc[ii] += sc[ii];
                }
            }
            
            int k = dfs(i + 1, sum);
            return max(ans, k);
        };

        return dfs(0, 0);
    }
};

