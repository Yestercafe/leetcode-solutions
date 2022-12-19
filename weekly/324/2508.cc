class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> g;
        unordered_map<int, int> deg;

        for (auto& v : edges) {
            g[v[0]].insert(v[1]);
            g[v[1]].insert(v[0]);
            ++deg[v[0]];
            ++deg[v[1]];
        }

        vector<int> odd;
        for (auto& [f, s] : deg) {
            if (s & 1) {
                odd.push_back(f);
            }
        }
        int m = odd.size();
        if (m == 0) {
            return true;
        } else if (m == 2) {
            int x = odd[0], y = odd[1];
            if (g[y].find(x) == g[y].end()) {
                return true;
            }

            for (int i = 1; i <= n; ++i) {
                if (i != x && i != y && g[i].find(x) == g[i].end() && g[i].find(y) == g[i].end()) {
                    return true;
                }
                return false;
            }
        } else if (m == 4) {
            return g[odd[0]].find(odd[1]) == g[odd[0]].end() && g[odd[2]].find(odd[3]) == g[odd[2]].end()
                || g[odd[0]].find(odd[2]) == g[odd[0]].end() && g[odd[1]].find(odd[3]) == g[odd[1]].end()
                || g[odd[0]].find(odd[3]) == g[odd[0]].end() && g[odd[2]].find(odd[1]) == g[odd[2]].end();
        } 
        // else
        return false;
    }
};

