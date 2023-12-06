class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        function<void(int, int, string&)> dfs = [&](int rem_pa, int in_cnt, string& path) {
            if (path.length() == n * 2) {
                cout << path << " " << rem_pa << ' ' << in_cnt << endl;
                ans.push_back(path);
                return;
            }
            
            if (rem_pa) {
                path.push_back('(');
                dfs(rem_pa - 1, in_cnt + 1, path);
                path.pop_back();
            }

            if (in_cnt) {
                path.push_back(')');
                dfs(rem_pa, in_cnt - 1, path);
                path.pop_back();
            }
        };

        string path;
        path.reserve(n * 2);

        dfs(n, 0, path);

        return ans;
    }
};

