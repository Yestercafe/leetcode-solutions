class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> ans;
        vector<string> p;

        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ans.push_back(p);
                return ;
            }
            auto palin = [](const string& s) {
                int n = s.length();
                for (int i = 0; i < n / 2; ++i) {
                    if (s[i] != s[n - 1 - i]) return false;
                }
                return true;
            };

            for (int j = i; j < n; ++j) {
                auto subs = s.substr(i, j - i + 1);
                if (palin(subs)) {
                    p.push_back(subs);
                    dfs(j + 1);
                    p.pop_back();
                }
            }
        };
        dfs(0);

        return ans;
    }
};

