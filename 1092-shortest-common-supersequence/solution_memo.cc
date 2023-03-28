class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int n = s.length(), m = t.length();
        vector memo(n, vector(m, 0));
        function<int(int, int)> dfs = [&](int i, int j) {
            if (i < 0) return j + 1;
            if (j < 0) return i + 1;
            if (memo[i][j]) return memo[i][j];
            if (s[i] == t[j])
                return memo[i][j] = dfs(i - 1, j - 1) + 1;
            return memo[i][j] = min(dfs(i - 1, j), dfs(i, j - 1)) + 1;
        };

        function<string(int, int)> make_ans = [&](int i, int j) {
            if (i < 0) return t.substr(0, j + 1);
            if (j < 0) return s.substr(0, i + 1);
            if (s[i] == t[j])
                return make_ans(i - 1, j - 1) + s[i];
            if (dfs(i, j) == dfs(i - 1, j) + 1) {
                return make_ans(i - 1, j) + s[i];
            } else {
                return make_ans(i, j - 1) + t[j];
            }
        };

        return make_ans(n - 1, m - 1);
    }
};

