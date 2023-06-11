class Solution {
    vector<int> g;
    int n;
    set<int> s;
    int up;
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        g.reserve(n);
        auto trans = [](vector<int>& v) {
            int f = 1;
            int ans = 0;
            for (auto ri = v.rbegin(); ri != v.rend(); ++ri, f *= 2) {
                ans += f * (*ri);
            }
            return ans;
        };
        for (auto& v : grid) {
            g.push_back(trans(v));
            // cout << g.back() << ' ';
        }
        
        int m = grid[0].size();
        up = (1 << m);  // [0, up] e.g. [0, 32]
        vector<pair<bool, int>> vis(up + 1);
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            vis[g[i]].first = true;
            vis[g[i]].second = i;
            for (int k = 0; k <= up; ++k) {
                if (vis[k].first) {
                    int xo = (g[i] ^ k);
                    bool flag = true;
                    for (int bit = 0; bit < m; ++bit) {
                        if ((((xo & (1 << bit)) >> bit) == 0) && (((k & (1 << bit)) >> bit) == 1)) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        ans.push_back(vis[k].second);
                        if (k != 0) ans.push_back(i);
                        break;
                    }
                }
            }
            if (ans.size()) break;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

